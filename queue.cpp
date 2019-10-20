//
// Created by Tiffany Montgomery on 2019-10-15.
//

#include "queue.h"

namespace tiff {

    template <typename E>
    Queue<E>::Queue(int size) {
        elements = 0;
        capacity = size;
        front = 0;
        rear = 0;
        q = new E[size];
    }




    template <typename E>
    Queue<E>::~Queue() {
        delete q;
    }

    //template class Queue<int>::~Queue<int>;

    template <typename E>
    int Queue<E>::size() const {
        return elements;
    }


    template <typename E>
    bool Queue<E>::empty() const{
        return (elements == 0);
    }

    template <typename E>
    const E& Queue<E>::get_front() const throw(QueueEmpty){
        if (empty()){
            throw QueueEmpty();
        }
        return q[front];
    }

    template <typename E>
    void Queue<E>::dequeue(){
        if(empty()){
            throw QueueEmpty();
        }
        front = (front + 1) % capacity;
        --elements;
    }

    template <typename E>
    void Queue<E>::enqueue(const E &e) {
        if (elements == capacity){
            resize();
        }
        q[rear] = e;
        rear = (rear + 1) % capacity;
        ++elements;
    }

    template <typename E>
    E* Queue<E>::resize() {
        capacity = elements*2;
        E* new_q = new E[capacity];
        for (int i = 0; i < elements; ++i){
            new_q[i] = q[i];
        }
        E* temp = q;
        q = new_q;
        delete temp;
    }

    template class Queue<int>;

}