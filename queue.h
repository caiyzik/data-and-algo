//
// Created by Tiffany Montgomery on 2019-10-15.
//

#pragma once
#include <string>

//Give an implementation of the deque ADT using an array, so that each of the update functions run in O(1) time.
//implement the queue ADT in a fully generic manner using a dynamically allocated C++ array.

namespace tiff {
    class QueueEmpty: public std::exception{
        const char* what() const noexcept override {
            return "Empty Queue. Nothing to return.";
        }
    };

    template <class E>
    class Queue {
    private:
        int elements;
        int capacity;
        int front;
        int rear;
        E* q;
        E* resize();

    public:

        explicit Queue (int);

        ~Queue();
        int size() const;

        bool empty() const;

        const E& get_front() const throw(QueueEmpty);

        void enqueue(const E &e);

        void dequeue() throw(QueueEmpty);

    };

}