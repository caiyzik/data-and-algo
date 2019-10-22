//
// Created by Tiffany Montgomery on 2019-10-11.
//

#include <iostream>
#include "queue.h"
#include "gtest/gtest.h"

using namespace tiff;

TEST(Queue, Enqueue){
    Queue<int> q = Queue<int>(5);
    q.enqueue(1);
    EXPECT_EQ(q.get_front(), 1);
}

TEST(Queue, GetFront_Empty){
    Queue<int> q = Queue<int>(5);
    EXPECT_THROW(q.get_front(), QueueEmpty);
}

TEST(Queue, GetFront_NotEmpty){
    Queue<int> q = Queue<int>(5);
    q.enqueue(1);
    EXPECT_EQ(q.get_front(), 1);
}

TEST(Queue, Dequeue_Empty){
    Queue<int> q = Queue<int>(5);
    EXPECT_THROW(q.dequeue(), QueueEmpty);
}

TEST(Queue, Dequeue_NotEmpty){
    Queue<int> q = Queue<int>(5);
    q.enqueue(1);
    q.dequeue();
    EXPECT_THROW(q.dequeue(), QueueEmpty);
}

TEST(Queue, Resize){
    Queue<int> q = Queue<int>(5);
    for(int i = 0; i < 5; ++i){
        q.enqueue(i);
    }
    EXPECT_NO_THROW(q.enqueue(1));
}


