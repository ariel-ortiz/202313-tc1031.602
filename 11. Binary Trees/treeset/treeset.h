#pragma once

#include <functional>
#include <initializer_list>

template<typename T>
class TreeSet {

public:

    // Complexity: O(1)
    TreeSet() {}

    // Complexity: O(N)
    ~TreeSet()
    {
        _delete(_root);
    }

    // Complexity: O(N log N)
    TreeSet(std::initializer_list<T> args)
    {
        for (T value : args) {
            add(value);
        }
    }

    // Complexity: O(log N)
    bool add(T value)
    {
        if (_root) {
            Node* p = _root;
            while (true) {
                if (value == p->value) {
                    return false;
                } else if (value < p->value) {
                    if (p->left) {
                        p = p->left;
                    } else {
                        p->left = new Node(value);
                        _size++;
                        return true;
                    }
                } else {
                    if (p->right) {
                        p = p->right;
                    } else {
                        p->right = new Node(value);
                        _size++;
                        return true;
                    }
                }
            }

        } else {
            _root = new Node(value);
            _size++;
            return true;
        }
    }

    // Complixity: O(1)
    int size() const
    {
        return _size;
    }

    // Complixity: O(1)
    bool is_empty() const
    {
        return size() == 0;
    }

    // Complixity: O(log N)
    bool contains(T value) const
    {
        return _contains(value, _root);
    }

    void inorder(std::function<void(T)> fn) const
    {
        return _inorder(fn, _root);
    }

private:

    struct Node {
        Node(T value) {
            this->value = value;
        }
        T value;
        Node* left = nullptr;
        Node* right = nullptr;
    };

    void _delete(Node* p)
    {
        if (p) {
            _delete(p->left);
            _delete(p->right);
            delete p;
        }
    }

    bool _contains(T value, Node* p) const
    {
        if (p) {
            if (value == p->value) {
                return true;
            } else if (value < p->value) {
                return _contains(value, p->left);
            } else {
                return _contains(value, p->right);
            }
        } else {
            return false;
        }
    }

    void _inorder(std::function<void(T)> fn, Node* p) const
    {
        if (p) {
            _inorder(fn, p->left);
            fn(p->value);
            _inorder(fn, p->right);
        }
    }

    Node* _root = nullptr;
    int _size = 0;
};
