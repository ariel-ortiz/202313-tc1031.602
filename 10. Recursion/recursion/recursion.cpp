#include "intlist.h"
#include "recursion.h"

// Complexity: O(N)
int size(const IntList& a)
{
    if (is_empty(a)) {
        return 0;
    } else {
        return 1 + size(rest(a));
    }
}

// Complexity: O(N)
IntList cons_end(int value, const IntList& a)
{
    if (is_empty(a)) {
        return IntList {value};
    } else {
        return cons(first(a), cons_end(value, rest(a)));
    }
}

// Complexity: O(N)
int sum(const IntList& a)
{
    if (is_empty(a)) {
        return 0;
    } else {
        return first(a) + sum(rest(a));
    }
}

// Complexity: O(N)
IntList duplicate(const IntList& a)
{
    if (is_empty(a)) {
        return IntList {};
    } else {
        return cons(first(a),
                    cons(first(a),
                         duplicate(rest(a))));
    }
}

// Complexity: O(N)
int last(const IntList& a)
{
    if (size(a) == 1) {
        return first(a);
    } else {
        return last(rest(a));
    }
}

// Complexity: O(N)
IntList but_last(const IntList& a)
{
    if (size(a) == 1) {
        return IntList {};
    } else {
        return cons(first(a), but_last(rest(a)));
    }
}

// Complexity: O(1)
int max(int x, int y)
{
    return (x > y) ? x : y;
}

// Complexity: O(N)
int maximum(const IntList& a)
{
    if (size(a) == 1) {
        return first(a);
    } else {
        return max(first(a), maximum(rest(a)));
    }
}

// Complexity: O(N), N = size(a)
IntList append(const IntList& a, const IntList& b)
{
    if (is_empty(a)) {
        return b;
    } else {
        return cons(first(a), append(rest(a), b));
    }
}

IntList repeat(int n, int value)
{
    return IntList {};
}

IntList reverse(const IntList& a)
{
    return IntList {};
}

// Complexity: O(N), N = size(a) + size(b)
IntList merge(const IntList& a, const IntList& b)
{
    if (is_empty(a)) {
        return b;
    } else if (is_empty(b)) {
        return a;
    } else if (first(a) < first(b)) {
        return cons(first(a), merge(rest(a), b));
    } else {
        return cons(first(b), merge(a, rest(b)));
    }
}

bool is_prefix(const IntList& a, const IntList& b)
{
    return false;
}

IntList insert(int value, const IntList& a)
{
    return IntList {};
}

IntList insertion_sort(const IntList& a)
{
    return IntList {};
}

IntList binary(int n)
{
    return IntList {};
}
