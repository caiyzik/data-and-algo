#include <iostream>
#include "dlinkedlist.h"
#include "gtest/gtest.h"



TEST(DoubleLinkedList, Empty_WhenEmpty){
    DoubleLinkedList* dll = new DoubleLinkedList;
    EXPECT_EQ(dll->empty(), true);
    delete dll;
}

TEST(DoubleLinkedList, Empty_NotEmpty){ //more tests for when the first element is inserted from the back?
    DoubleLinkedList* dll = new DoubleLinkedList;
    dll->addFront(1);
    EXPECT_EQ(dll->empty(), false);
    delete dll;
}

TEST(DoubleLinkedList, Front_Empty){
    DoubleLinkedList* dll = new DoubleLinkedList;
    int d = dll->front();
    EXPECT_EQ(d, nullptr); //should this return null?
    delete dll;
}

TEST(DoubleLinkedList, Front_NotEmpty){
    DoubleLinkedList* dll = new DoubleLinkedList;
    dll->addFront(1);
    EXPECT_EQ(dll->front(), 1);
    delete dll;
}

TEST(DoubleLinkedList, Back_Empty){
    DoubleLinkedList* dll = new DoubleLinkedList;
    EXPECT_EQ(dll->back(), nullptr);
    delete dll;
}

TEST(DoubleLinkedList, Back_NotEmpty){
    DoubleLinkedList* dll = new DoubleLinkedList;
    dll->addFront(1);
    EXPECT_EQ(dll->back(), 1);
    delete dll;
}

TEST(DoubleLinkedList, AddFront_Empty){
    DoubleLinkedList* dll = new DoubleLinkedList;
    dll->addFront(1);
    EXPECT_EQ(dll->front(), 1);
    delete dll;
}

TEST(DoubleLinkedList, AddFront_NotEmpty){
    DoubleLinkedList* dll = new DoubleLinkedList;
    dll->addFront(1);
    dll->addFront(2);
    EXPECT_EQ(dll->front(), 2);
    delete dll;
}

TEST(DoubleLinkedList, AddBack_Empty){
    DoubleLinkedList* dll = new DoubleLinkedList;
    dll->addBack(1);
    EXPECT_EQ(dll->back(), 1);
    delete dll;
}

TEST(DoubleLinkedList, AddBack_NotEmpty){
    DoubleLinkedList* dll = new DoubleLinkedList;
    dll->addBack(1);
    dll->addBack(2);
    EXPECT_EQ(dll->back(), 2);
    delete dll;
}

TEST(DoubleLinkedList, RemFront_Empty){
    DoubleLinkedList* dll = new DoubleLinkedList;
    dll->removeFront();
    EXPECT_EQ(dll->front(), nullptr);
    delete dll;
}

TEST(DoubleLinkedList, RemFront_NotEmpty_SingleElem){
    DoubleLinkedList* dll = new DoubleLinkedList;
    dll->addFront(1);
    dll->removeFront();
    EXPECT_EQ(dll->front(), nullptr);
    delete dll;
}

TEST(DoubleLinkedList, RemFront_NotEmpty_MuliElem){
    DoubleLinkedList* dll = new DoubleLinkedList;
    dll->addFront(1);
    dll->addFront(2);
    dll->removeFront();
    EXPECT_EQ(dll->front(), 1);
    delete dll;
}

TEST(DoubleLinkedList, RemBack_Empty){
    DoubleLinkedList* dll = new DoubleLinkedList;
    dll->removeBack();
    EXPECT_EQ(dll->back(), nullptr);
    delete dll;
}

TEST(DoubleLinkedList, RemBack_NotEmpty_SingleElem){
    DoubleLinkedList* dll = new DoubleLinkedList;
    dll->addFront(1);
    dll->removeBack();
    EXPECT_EQ(dll->front(), nullptr);
    delete dll;
}

TEST(DoubleLinkedList, RemBack_NotEmpty_MuliElem){
    DoubleLinkedList* dll = new DoubleLinkedList;
    dll->addFront(1);
    dll->addBack(2);
    dll->removeBack();
    EXPECT_EQ(dll->back(), 1);
    delete dll;
}

