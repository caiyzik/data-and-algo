//
// Created by Tiffany Montgomery on 2019-10-05.
//
#include <iostream>
#include "dlinkedlist.h"

namespace tiff {
    
    DoubleLinkedList::DoubleLinkedList() {
        //init the list. Set the head pointer
        _head = new Node();
        _tail = new Node();
    }

    DoubleLinkedList::~DoubleLinkedList() { //need to delete all the nodes
        Node *current = _head;
        Node *temp;
        while (current) {
            temp = current;
            current = current->next;
            delete temp;
        }
    }

    void DoubleLinkedList::add(Node *n, const int &data) { //insert new node in front of n
        Node *new_node = new Node(data);
        if (this->empty()) {
            _head->next = new_node;
            _tail->prev = new_node;
            new_node->prev = _head;
            new_node->next = _tail;
        } else if (n == _head->next) {
            new_node->prev = _head;
            new_node->next = _head->next;
            _head->next = new_node;
        } else if (n) {
            new_node->next = n;
            new_node->prev = n->prev;
            n->prev->next = new_node;
            n->prev = new_node;
        } else {
            n = new_node;
        }
    }

    void DoubleLinkedList::remove(Node *n) {
        if(n->prev && n->next) {
            n->prev->next = n->next;
            n->next->prev = n->prev;
            delete n;
        } else {
            throw EmptyListException();
        }
    }

    bool DoubleLinkedList::empty() const {
        if (_head->next && _head-> next != _tail) {
            return false;
        }
        return true;
    }

    const int& DoubleLinkedList::front() const {
        if(_head->next && _head->next != _tail){
            return _head->next->data;
        } else {
            throw EmptyListException();
        }
    }

    const int &DoubleLinkedList::back() const {
        if (_tail->prev) {
            return _tail->prev->data;
        } else {
            throw EmptyListException();
        }
    }

    void DoubleLinkedList::addFront(const int &data) {
        this->add(_head->next, data);
    }

    void DoubleLinkedList::addBack(const int &data) {
        this->add(_tail, data);
    }

    void DoubleLinkedList::removeFront() {
        if(_head->next) {
            this->remove(_head->next);
        } else {
            throw EmptyListException();
        }

    }

    void DoubleLinkedList::removeBack() {
        if(_tail->prev) {
            this->remove(_tail->prev);
        } else {
            throw EmptyListException();
        }
    }

}

