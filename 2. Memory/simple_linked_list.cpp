#include <iostream>

struct Node {
    int value;
    Node* next;
};

int main()
{
    Node* p = new Node;
    p->value = 42;
    p->next = nullptr;

    Node* list;
    list = p;
}
