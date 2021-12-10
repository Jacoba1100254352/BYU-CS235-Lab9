#ifndef BST_LAB_BST_H
#define BST_LAB_BST_H

#include "BSTInterface.h"
#include "NodeTree.h"


class [[maybe_unused]] BST : public BSTInterface {
private:
    NodeTree *T = nullptr;

public:
    BST() = default;

    ~BST() override {
        if (T != nullptr)
            removeMe(T);
        else delete T;
        T = nullptr;
    }

    //Please note that the class that implements this interface must be made
    //of objects which implement the NodeInterface

    /*
    * Returns the root node for this tree
    *
    * @return the root node for this tree.
    */
    [[nodiscard]] NodeTreeInterface* getRootNode() const override{
        return T;
    }

    /*
    * Attempts to add the given int to the BST tree
    *
    * @return true if added
    * @return false if unsuccessful (i.e. the int is already in tree)
    */
    bool add(int data) override{
        return insert(T, data);
    }

    //
    bool insert(NodeTree *&t, int data) {

        // Look ahead and see if CHILDREN are null
        if (t == nullptr) {
            //insert.
            t = new NodeTree(data);
            return true;
        }

        // If there is a node already with the value passed, DON'T add.
        if (t->value == data) return false;

        // If data is less than t->value, go down left. If not, go right.
        // (data < t->value) ? insert(t->left, data) : insert(t->right, data);
        return insert(((t->value > data) ? t->left : t->right), data);
    }

/*    if (t == nullptr)
    {
        t = new NodeTree(data);
        return true;
    }

    // If there is a node already with the value passed, DON'T add.
    if (t->value == data) return false;

    return insert( (t->value > data) ? t->left : t->right, data);
}*/

    /*
    * Attempts to remove the given int from the BST tree
    *
    * @return true if successfully removed
    * @return false if remove is unsuccessful(i.e. the int is not in the tree)
    */
    bool remove(int data) override{
        return eliminate(T, data);
    }

    bool eliminate(NodeTree *&t, int data){
        if(t == nullptr)
            return false;
        else if(t->value == data) {
            //Different cases!

            //if this doesn't have a left child...repurpose t to be t = t->right
            //Create temporary pointer and DELETE after circumvent
            ///Don't need to worry about 0 children cases, because we'll set it to NULL anyways.
            if(t->left == nullptr){
                //NodeTree *tmp = t;
                t = t->right;
                //delete tmp;
                //no RIGHT child
            } else if(t->right == nullptr){
                //NodeTree *tmp = t;
                t = t->left;
                //delete tmp;

                //2 children case!!! Try and understand this one better.
            } else {
                //passing it left so our IOP function doesn't have to.
                NodeTree *iOP = getInOrderPredecessor(t->left);
                //Put that in order predecessor at the top!
                t->value = iOP->value;
                eliminate(t->left, static_cast<int>(iOP->value));
            }
            return true;
        }
        return eliminate( ((data < t->value) ? t->left : t->right), data);
    }

    NodeTree* getInOrderPredecessor(NodeTree *t) {
        return (t->right == nullptr) ? t : getInOrderPredecessor(t->right);
    }

    /*
    * Removes all nodes from the tree, resulting in an empty tree.
    */
    void clear() override{
        removeMe(T);
        T = nullptr;
    }

    void removeMe(NodeTree *&t){
        if(t == nullptr)
            return;

        if (t->left != nullptr)
            removeMe(t->left);
        if (t->right != nullptr)
            removeMe(t->right);

        delete t;
    }
};


#endif //BST_LAB_BST_H
