#pragma once

#include <stdexcept>
#include <sstream>

template<typename T>
class LinkedList {

public:

    // Forbid the creation of a copy constructor
    LinkedList(const LinkedList& other) = delete;

    // Forbid assignment operator
    LinkedList<T>& operator=(const LinkedList& other) = delete;

    // Complexity: O(1)
    LinkedList()
    {
        Node* p = new Node;
        p->next = p;
        p->prev = p;
        _sentinel = p;
    }

    // Complexity: O(N)
    LinkedList(std::initializer_list<T> args): LinkedList()
    {
       for (T arg: args) {
           insert_back(arg);
       }
    }

    // Complexity: O(N)
    ~LinkedList()
    {
        Node* current = _sentinel->next;
        while (current != _sentinel) {
            Node* p = current;
            current = current->next;
            delete p;
        }
        delete _sentinel;
    }

    // Complexity: O(1)
    void insert_front(T value)
    {
        Node* p = new Node;
        p->value = value;
        p->next = _sentinel->next;
        p->prev = _sentinel;
        _sentinel->next->prev = p;
        _sentinel->next = p;
        ++_size;
    }

    void insert_back(T value)
    {
        Node* p = new Node;
        p->value = value;
        p->next = _sentinel;
        p->prev = _sentinel->prev;
        _sentinel->prev->next = p;
        _sentinel->prev = p;
        ++_size;
    }

    // Complexity: O(1)
    int size() const
    {
        return _size;
    }

    // Complexity: O(1)
    bool is_empty() const
    {
        return not _size;
    }

    // Complexity: O(N)
    std::string to_string() const
    {
        std::ostringstream result;
        result << "[";
        bool first_time = true;
        Node* p = _sentinel->next;
        while (p != _sentinel) {
            if (first_time) {
                first_time = false;
            } else {
                result << ", ";
            }
            result << p->value;
            p = p->next;
        }
        result << "]";
        return result.str();
    }

    T remove_front()
    {
        if (is_empty()) {
            throw std::length_error(
                "Can't remove from an empty list");
        }
        Node* p = _sentinel->next;
        T result = p->value;
        _sentinel->next = p->next;
        p->next->prev = _sentinel;
        delete p;
        --_size;
        return result;
    }

private:

    struct Node {
        T value;
        Node* next;
        Node* prev;
    };

    Node* _sentinel = nullptr;
    int _size = 0;
};
