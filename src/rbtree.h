//
// Created by sangwon on 2022-04-04.
//

#pragma once

#ifndef OLEFS_RBTREE_H
#define OLEFS_RBTREE_H

#include "types.h"
#include <functional>

namespace OLEFS {
    enum class RBColor {
        BLACK = 0,
        RED = 1
    };

    template<class NKey, class NData>
    class RBNode {
    private:
        RBNode<NKey, NData>* _parent;
        RBNode<NKey, NData>* _left;
        RBNode<NKey, NData>* _right;
        RBColor _color;
        NKey _key;
        NData _data;

    public:
        RBNode()
            : _parent(nullptr), _left(nullptr), _right(nullptr), _color(RBColor::BLACK) { }
        RBNode(NKey key, NData data)
            : _parent(nullptr), _left(nullptr), _right(nullptr), _color(RBColor::BLACK), _key(key), _data(data) { }
        RBNode(RBNode<NKey, NData>* parent, NKey key, NData data)
            : _parent(parent), _left(nullptr), _right(nullptr), _color(RBColor::BLACK), _key(key), _data(data) { }

        ~RBNode() {
            _parent = nullptr;
            if(_left != nullptr) {
                delete _left;
                _left = nullptr;
            }
            if(_right != nullptr) {
                delete _right;
                _right = nullptr;
            }
        }

        void set_parent(RBNode<NKey, NData>* parent) { _parent = parent; }
        void set_left(RBNode<NKey, NData>* left) { _left = left; }
        void set_right(RBNode<NKey, NData>* right) { _right = right; }
        void set_color(RBColor color) { _color = color; }
        void set(NKey key, NData data) { set_key(key); set_data(data); }
        void set_key(NKey key) { _key = key; }
        void set_data(NData data) { _data = data; }

        RBNode<NKey, NData> get_parent() const { return _parent; }
        RBNode<NKey, NData> get_left() const { return _left; }
        RBNode<NKey, NData> get_right() const { return _right; }
        RBColor get_color() const { return _color; }
        NKey get_key() const { return _key; }
        NData get_data() const { return _data; }
    };

    template<class NKey, class NData>
    class RBTree {
    private:
        RBNode<NKey, NData>* _root;

    public:
        std::function<int32(const RBNode<NKey, NData>&, const RBNode<NKey, NData>&)> compare;

    public:
        RBTree() {
            _root = nullptr;
        }

        RBTree(NKey key, NData data) {
            _root = new RBNode<NKey, NData>(key, data);
        }

        RBTree(NKey key, NData data, std::function<int(const RBNode<NKey, NData>&, const RBNode<NKey, NData>&)> cmp) {
            _root = new RBNode<NKey, NData>(key, data);
            set_compare(cmp);
        }

        ~RBTree() {
            delete _root;
        }

        void set_compare(std::function<int32(const RBNode<NKey, NData>&, const RBNode<NKey, NData>&)> cmp) {
            compare = cmp;
        }

        void insert_node(NKey key, NData data);
        void insert_node(RBNode<NKey, NData>* node);
        void delete_node(NKey key);
        void delete_node(RBNode<NKey, NData>* node);
        RBNode<NKey, NData>* get_node(NKey key);
        RBNode<NKey, NData>* get_root() const { return _root; }
    };
}

#endif //OLEFS_RBTREE_H
