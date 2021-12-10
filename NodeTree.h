#ifndef NODE_TREE_H
#define NODE_TREE_H

#include <iostream>
#include "NodeTreeInterface.h"

class NodeTree : public NodeTreeInterface {
public:
    int value;
    NodeTree *left, *right;

    explicit NodeTree(int _data){
        value = _data;
        left = right = nullptr;
    }

    /*
    * Returns the data that is stored in this node
    *
    * @return the data that is stored in this node.
    */

    [[nodiscard]] int getData() const override{
        return value;
    }

    /*
    * Returns the left child of this node or null if it doesn't have one.
    *
    * @return the left child of this node or null if it doesn't have one.
    */
    [[nodiscard]] NodeTree* getLeftChild() const override{
        return left;
    }

    /*
    * Returns the right child of this node or null if it doesn't have one.
    *
    * @return the right child of this node or null if it doesn't have one.
    */
    [[nodiscard]] NodeTree* getRightChild() const override{
        return right;
    }
};

#endif //NODE_TREE_H
