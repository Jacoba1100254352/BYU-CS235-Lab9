#ifndef AVL_H
#define AVL_H

#include <stdexcept>
#include <iostream>
#include "AVLInterface.h"
#include "Node.h"

class AVL : public AVLInterface {
private:
    Node* T = nullptr;
public:
    ~AVL() override;

    ///   Imbalance Types   ///
    enum ebt {
        balanced = 0,
        LL = 1,
        LR = 2,
        RR = 3,
        RL = 4
    };

    ///   Get Root Node Function   ///
    [[nodiscard]] Node* getRootNode() const override{
        return T;
    }

    ///   Add Functions   ///
    bool add(int) override;
    static bool recAdd(Node*&, int);

    ///   Remove Functions   ///
    bool remove(int) override;
    bool recRemove(Node*&, int);

    ///   Balance Functions   ///
    static void balance(Node*&);
    static void rightRotate(Node*&);
    static void leftRotate(Node*&);
    Node* getInOrderPredecessor(Node* t) {
        return (t->right == nullptr) ? t : getInOrderPredecessor(t->right);
    }

    ///   Height Functions   ///
    static int updateHeight(Node*);
    static int max(Node*, Node*);
    static int getHeight(Node* t) {
        return (t == nullptr) ? -1 : t->height;
    }

    ///   Clear Functions   ///
    void clear() override;
    void recClear(Node*&);
};

#endif //AVL_H
