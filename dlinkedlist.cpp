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
    Node* current = _head;
    Node* temp;
    while(current){
        temp = current;
        current = current->next;
        delete temp;
    }
}

void DoubleLinkedList::add(Node* n, const int& data){ //insert new node in front of n
    Node* new_node = new Node(data);
    if(this->empty()){
        _head->next = new_node;
        _tail->prev = new_node;
    } else if (n == _head->next){
        new_node->prev = _head;
        new_node->next = _head->next;
        _head->next = new_node;
    } else if(n){
        new_node->next = n;
        new_node->prev = n->prev;
        n->prev->next = new_node;
        n->prev = new_node;
    } else{
        n = new_node;
    }
}
void DoubleLinkedList::remove(Node* n){
    n->prev->next = n->next;
    n->next->prev = n->prev;
    delete n;
}

bool DoubleLinkedList::empty() const{
    if(_head->next){
        return false;
    }
    return true;
}
const int& DoubleLinkedList::front() const{
    if(_head->next){
        return _head->next->data;
    } else {
        return NULL; //TODO: Throw an error instead
    }
}
const int& DoubleLinkedList::back() const{
    if(_tail->prev){
        return _tail->prev->data;
    } else{
        return NULL;
    }
}
void DoubleLinkedList::addFront(const int& data){
    this->add(_head->next, data);
}
void DoubleLinkedList::addBack (const int& data){
    this->add(_tail->prev, data);
}
void DoubleLinkedList::removeFront(){
    this->remove(_head->next);
}
void DoubleLinkedList::removeBack(){
    this->remove(_tail->prev);
}



