#ifndef NODE_H
#define NODE_H
#include "NodeInterface.h"

class Node : public NodeInterface {
public:
    int val;
    Node *left, *right;
    int height = -1;

    explicit Node(int _data){
        val = _data;
        left = right = nullptr;
        height = 0;
    }

    /*
    * Returns the data stored in this node
    *
    * @return the data stored in this node.
    */
    [[nodiscard]] int getData() const override{
        return val;
    }

    /*
    * Returns the left child of this node or null if empty left child.
    *
    * @return the left child of this node or null if empty left child.
    */
    [[nodiscard]] NodeInterface* getLeftChild() const override{
        return left;
    }

    /*
    * Returns the right child of this node or null if empty right child.
    *
    * @return the right child of this node or null if empty right child.
    */
    [[nodiscard]] NodeInterface* getRightChild() const override{
        return right;
    }

    /*
    * Returns the height of this node. The height is the number of nodes
    * along the longest path from this node to a leaf.  While a conventional
    * interface only gives information on the functionality of a class and does
    * not comment on how a class should be implemented, this function has been
    * provided to point you in the right direction for your solution.  For an
    * example on height, see page 448 of the text book.
    *
    * @return the height of this tree with this node as the local root.
    */
    int getHeight() override{
        return height;
    }

//    Node class function, gets height as long as T is not NULL.

};


#endif //NODE_H
