//
// Created by Tiffany Montgomery on 2019-10-20.
//

#pragma once
#include <list>

namespace tiff {

    template <typename E>
    class Node{
    public:
        Node(E);
        E& operator*();
        Node get_parent() const;
        Node* get_children() const;
        bool isRoot() const;
        bool isExternal() const;
    private:
        Node<E> parent;
        std::list<Node<E>> children;
        bool root;
        E value;
    };

    //implementation
    template <typename E>
    Node<E>::Node(E val){
        this->value = val;
        this->children = new std::list<Node<E>>;
    }

    /*
    template <typename E>
    Node<E> Node<E>::parent() const {

    }
    */

    template <typename E>
    class Tree {
    public:
        Node<E>* root;
        std::list<Node<E>> node_list; //Node list can use an stl list, assume an iterator type is provided
        static int depth(Node<E>); //do these need to be static? How does this affect code size?
        static int height(Node<E>);
    private:
        int size() const;
        bool empty() const;
        Node<E> get_root() const;
        Node<E>* get_nodes() const;
    };



    template <typename E>
    int Tree<E>::depth(tiff::Node<E> n) {
        if (n.isRoot()) {
            return 0;
        }
        else {
            return 1 + depth(n.parent());
        }
    }

    template <typename E>
    int Tree<E>::height(tiff::Node<E> n) {
        if (n.isExternal()){
            return 0;
        } else {
            int h = 0;
            for (int i = 0; i < n.children().size(); ++i){ //do this with an iterator
                h = max(h, height(n.children()[i]));
            }
            return 1 + h;
        }
    }

}