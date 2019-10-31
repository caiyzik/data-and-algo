//
// Created by Tiffany Montgomery on 2019-10-20.
//

#pragma once

namespace tiff {

    template <typename E>
    class Node{
    public:
        E& operator*();
        Node parent() const;
        Node* children() const;
        bool isRoot() const;
        bool isExternal() const;
    private:

    };

    template <typename E>
    class Tree {
    public:
        //Node* nodes;
        //Node list can use an stl list, assume an iterator type is provided
        static int depth(Node<E>); //do these need to be static? How does this affect code size?
        static int height(Node<E>);
    private:
        int size() const;
        bool empty() const;
        Node<E> root() const;
        Node<E>* nodes() const;
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