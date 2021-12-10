//
// Created by njudd on 10/19/2021.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LinkedListInterface.h"

#include <string>
#include <sstream>

template<typename T>

class [[maybe_unused]] LinkedList : public LinkedListInterface<T> {

private:
    struct Node{
        explicit Node(T _value){
            value = _value;
            next = NULL;
        }

        T value;
        Node *next;
    };

    Node *head;

public:
    LinkedList() { head = nullptr; }

    ~LinkedList() { clear(); }

    void insertHead(T value){
        if(head == NULL) head = new Node(value);
        else {
            Node *currentElement = head;

            // Don't add duplicate values
            while (true)
                if (value == currentElement->value) return;   // Does value already exist?
                else if (currentElement->next == NULL) break; // Have we reached the end?
                else currentElement = currentElement->next;   // Keep going

            Node *n = head;
            head = new Node(value);

            head->next = n;
        }
    }


    void insertTail(T value) {
        if (head == NULL) head = new Node(value);
        else {
            Node *currentElement = head;

            // Don't add duplicate values
            while (true)
                if (value == currentElement->value) return;
                else if (currentElement->next == NULL) break;
                else currentElement = currentElement->next;

            currentElement->next = new Node(value);// If no duplicates exist insert at end
        }
    }

    void insertAfter(T newValue, T insertAfter){
        if(head == NULL) head = new Node(newValue);
        else {
            Node *currentElement = head; // EQUAL to EVERYTHING

            // Don't add duplicate values
            while (true)
                if (newValue == currentElement->value) return;
                else if (currentElement->next == NULL) break;
                else currentElement = currentElement->next;


            // Insert node with value value after node with value insertionNode
            currentElement = head;
            while (true)
                if (insertAfter == currentElement->value) break;
                else if(currentElement->next == NULL) return;
                else currentElement = currentElement->next;


            // Insert and reroute
            Node *placeHolder = currentElement->next;
            currentElement->next = new Node(newValue);
            currentElement->next->next = placeHolder;
            //head = currentElement;
//            delete placeHolder;
//            delete insert;
        }
    }


    void remove(T value){
        if(head == NULL)
            return;

        if(head->value == value) head = head->next;
        else {
            Node *searchAndDestroy = head;

            while(searchAndDestroy->next != NULL && searchAndDestroy->next->value != value) searchAndDestroy = searchAndDestroy->next;

            if(searchAndDestroy->next != NULL) {
                Node *placeHolder = searchAndDestroy->next;
                searchAndDestroy->next = placeHolder->next;

                delete placeHolder;
            }
        }
    }


    void clear(){
        while (head != NULL) remove(head->value);
        delete head;
    }

    T at(int index) {
        if (index < 0 || index >= size()) {
            throw out_of_range("at " + to_string(index) + " out_of_range at line " + to_string(__LINE__));
        } else {
            Node *ptr = head;
            for (int i = 0; i <= index; i++) {
                if (i == index) {
                    cout << "at " << index << " " << ptr->value << endl;
                    break;
                } else {
                    ptr = ptr->next;
                }
            }
            return (ptr->value);
        }
    }


    int size() {
        if (head == NULL) return 0;

        int listSize = 0;
        Node *ptr = head;
        while (ptr->next != NULL){
            listSize++;
            ptr = ptr->next;
        }
        return ++listSize;
    }


    string toString(){
        string theAnswer;
        stringstream ss(theAnswer);
        Node *iteration = head;

        while(iteration != NULL){
            //prints the space BEFORE the value!
            if(iteration != head) ss << " ";
            ss << iteration->value;
            iteration = iteration->next;
        }
        return ss.str();
    }


};


#endif //LINKEDLIST_H
