#include <iostream>

struct Node {
    int value;
    Node* next;
};

// Complexity: O(1)
void insert(Node*& list, int value)
{
    Node* p = new Node;
    p->value = value;
    p->next = list;
    list = p;
}

// Complexity: O(N)
void free(Node*& list)
{
    Node* p = list;
    while (p) {
        Node* next = p->next;
        delete p;
        p = next;
    }
    list = nullptr;
}

// Complexity: O(N)
void display(Node* list)
{
    Node* p = list;
    while (p) {
        std::cout << p->value << " ";
        p = p->next;
    }
    std::cout << "\n";
}

// Complexity: O(N)
int length(Node* list)
{
    Node* p = list;
    int result = 0;
    while (p) {
        ++result;
        p = p->next;
    }
    return result;
}


// Complexity: O(1)
void drop(Node*& list)
{
    if (list) {
        Node* p = list;
        list = list->next;
        delete p;
    }
}

// Complexity: O(N)
bool remove(Node*& list, int value)
{
    Node* p = list;
    Node* prev = nullptr;
    while (p) {
        if (p->value == value) {
            if (prev) {
                prev->next = p->next;
            } else {
                list = p->next;
            }
            delete p;
            return true;
        }
        prev = p;
        p = p->next;
    }
    return false;
}

void reverse(Node*& list)
{
    if (not list) { return; }
    Node* prev = nullptr;
    Node* next = list->next;
    while (next) {
        list->next = prev;
        prev = list;
        list = next;
        next = next->next;
    }
    list->next = prev;
}

int main()
{
    Node* list = nullptr;
    std::cout << "length(list) = " << length(list) << "\n";
    display(list);
    insert(list, 42);
    display(list);
    insert(list, 23);
    display(list);
    insert(list, 16);
    display(list);
    insert(list, 15);
    display(list);
    reverse(list);
    std::cout << "Reverse: ";
    display(list);
    std::cout << "length(list) = " << length(list) << "\n";
    drop(list);
    drop(list);
    display(list);
    std::cout << "length(list) = " << length(list) << "\n";
    std::cout << "remove(list, 42) = " << remove(list, 42) << "\n";
    std::cout << "remove(list, 108) = " << remove(list, 108) << "\n";
    std::cout << "remove(list, 23) = " << remove(list, 23) << "\n";
    display(list);
    free(list);
    display(list);
}
