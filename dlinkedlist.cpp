//
// Created by Tiffany Montgomery on 2019-10-05.
//
#include <iostream>
#include "dlinkedlist.h"

DoubleLinkedList::DoubleLinkedList(){
    //init the list. Set the head pointer
    _head = new Node();
    _tail = new Node();
}

DoubleLinkedList::~DoubleLinkedList() { //need to delete all the nodes

}

void DoubleLinkedList::add(Node* n, const int& data){ //insert new node in front of n
    Node* new_node = new Node(data);
    if(this->empty()){
        _head = new_node;
        _tail = new_node;
    } else {
        n->prev = new_node;
        new_node->prev = n->prev;
        if(n == _head){
            _head = new_node;
        }
        if(n == _tail){

        }
    }

}
void DoubleLinkedList::remove(Node* n){

    if(_head && _head == n){
        _head = n->next;
        n->next->prev = nullptr;
    } else if (_tail && _tail == n){
        _tail = n->prev;
        n->prev->next = nullptr;
    } else {
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }

    delete n;

}

bool DoubleLinkedList::empty() const{
    if(_head){
        return false;
    }
    return true;
}
const int& DoubleLinkedList::front() const{
    if(_head){
        return _head->data;
    } else {
        return NULL; //TODO: Throw an error instead
    }
}
const int& DoubleLinkedList::back() const{
    if(_tail){
        return _tail->data;
    } else{
        return NULL;
    }
}
void DoubleLinkedList::addFront(const int& data){
    this->add(_head, data);
}
void DoubleLinkedList::addBack (const int& data){
    Node* new_node = new Node(data);
    if(_tail) {
        _tail->next = new_node;
    }
    new_node->prev = _tail;
    _tail = new_node;
}
void DoubleLinkedList::removeFront(){
    this->remove(_head);
}
void DoubleLinkedList::removeBack(){
    this->remove(_tail);
}



