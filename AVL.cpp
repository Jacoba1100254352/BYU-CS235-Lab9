#include "AVL.h"

AVL::~AVL() {
    AVL::clear();
}


/********************
*   ADD FUNCTIONS   *
********************/
bool AVL::add(int data){
    return recAdd(T, data);
}

bool AVL::recAdd(Node* &t, int data) {
    if (t == nullptr) { // Look ahead and see if CHILDREN are null
        t = new Node(data);
        return true;
    } else if (t->val == data) // If there is a node already with the val passed, DON'T add.
        return false;

    // Recursive Add and then balance
    bool returnValue = recAdd(((t->val > data) ? t->left : t->right), data);
    balance(t);
    return returnValue;
}


/***********************
*   REMOVE FUNCTIONS   *
***********************/
bool AVL::remove(int data) {
    return recRemove(T, data);
}

bool AVL::recRemove(Node *&t, int data){
    if(t == nullptr)
        return false;
    else if (t->val == data) {
        // If no left child: repurpose t to be t = t->right
        if(t->left == nullptr){
            Node* tmp = t;
            t = t->right;
            delete tmp;
        } else if (t->right == nullptr) { // no RIGHT child
            Node* tmp = t;
            t = t->left;
            delete tmp;
        } else { // Two children case
            // Recurse remove with the in-order predecessor at the top
            bool retVal = recRemove(t->left, t->val = getInOrderPredecessor(t->left)->val);
            balance(t);
            return retVal;
        }
        balance(t);
        return true;
    }
    bool retVal = recRemove(((data < t->val) ? t->left : t->right), data);
    balance(t);
    return retVal;
}


/************************
*   Balance FUNCTIONS   *
************************/
void AVL::balance(Node *&t){
    if (t != nullptr)
        t->height = updateHeight(t);

    switch (((t == nullptr) || abs(getHeight(t->left) - getHeight(t->right)) < 2) ? balanced : ((getHeight(t->left) - getHeight(t->right)) < -1) ? ((getHeight(t->right->right) >= getHeight(t->right->left)) ? RR : RL) : ((getHeight(t->left) - getHeight(t->right)) > 1)  ? ((getHeight(t->left->left) >= getHeight(t->left->right)) ? LL : LR) : throw std::invalid_argument("Invalid imbalance type, Line: " + to_string(__LINE__))) {
        case LR:
            leftRotate(t->left);
        case LL:
            rightRotate(t);
            break;
        case RL:
            rightRotate(t->right);
        case RR:
            leftRotate(t);
        case balanced:
            break;
        default:
            throw std::out_of_range("Incorrect enum balanceType returned on line: " + to_string(__LINE__));
    }
}

void AVL::rightRotate(Node* &t) {
    if (t == nullptr)
        return;

    Node *newRoot = t->left;
    t->left = newRoot->right;

    // Put the newRoot on top
    newRoot->right = t;
    t = newRoot;
    newRoot->right->height = updateHeight(newRoot->right);
    newRoot->height = updateHeight(newRoot);
}

void AVL::leftRotate(Node* &t) {
    if (t == nullptr)
        return;

    Node* newRoot = t->right;
    t->right = newRoot->left;

    // Put the newRoot on top
    newRoot->left = t;
    t = newRoot;
    newRoot->left->height = updateHeight(newRoot->left);
    newRoot->height = updateHeight(newRoot);
}


/***********************
*   HEIGHT FUNCTIONS   *
***********************/
int AVL::updateHeight(Node* t){
    return (t == nullptr) ? -1 : max(t->left, t->right) + 1;
}

int AVL::max(Node* left, Node* right){
    return (getHeight(left) > getHeight(right)) ? getHeight(left) : getHeight(right);
}


/**********************
*   CLEAR FUNCTIONS   *
**********************/
void AVL::clear() {
    recClear(T);
    T = nullptr;
}

void AVL::recClear(Node *&t){
    if(t == nullptr) return;

    if (t->left != nullptr) recClear(t->left);
    if (t->right != nullptr) recClear(t->right);

    delete t;
}
