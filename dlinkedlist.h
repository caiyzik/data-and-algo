//
// Created by Tiffany Montgomery on 2019-10-05.
//

#pragma once
#include <iostream>

//Give a fully generic implementation of the doubly linked list data structure using a templated class.

//template <typename T>
//Note accessing out of bounds isn't checked in vector so maybe don't check here...

namespace tiff {

    class EmptyListException: public std::exception{
        const char* what() const noexcept override {
            return "Empty List. Nothing to return.";
        }
    };


    class Node {
    private:
        Node() {
            next = nullptr;
            prev = nullptr;
        }

        Node(int data) : Node() { this->data = data; }

        Node *next;
        Node *prev;
        int data;

        friend class DoubleLinkedList;
    };


    class DoubleLinkedList {

    public:
        DoubleLinkedList();

        ~DoubleLinkedList();

        bool empty() const;

        const int &front() const;

        const int &back() const;

        void addFront(const int &);

        void addBack(const int &);

        void removeFront();

        void removeBack();

    private:
        Node *_head;
        Node *_tail;
    protected:
        void add(Node *, const int &);

        void remove(Node *);
    };
}