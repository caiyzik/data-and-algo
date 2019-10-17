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

    template<typename T> class DoubleLinkedList;

    template<typename T>
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

        friend class DoubleLinkedList<T>;
    };


    template<typename T>
    class DoubleLinkedList {

    public:
        DoubleLinkedList();

        ~DoubleLinkedList();

        bool empty() const;

        //const T &front() const;

        const T &back() const;

        void addFront(const int &);

        void addBack(const int &);

        void removeFront();

        void removeBack();

    private:
        Node<T> *_head;
        Node<T> *_tail;
    protected:
        void add(Node<T> *, const int &);

        void remove(Node<T> *);
    };
}