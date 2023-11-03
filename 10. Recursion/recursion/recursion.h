#pragma once

#include "intlist.h"

int size(const IntList& a);

IntList cons_end(int value, const IntList& a);

int sum(const IntList& a);

IntList duplicate(const IntList& a);

int last(const IntList& a);

IntList but_last(const IntList& a);

int maximum(const IntList& a);

IntList append(const IntList& a, const IntList& b);

IntList repeat(int n, int value);

IntList reverse(const IntList& a);

IntList merge(const IntList& a, const IntList& b);

bool is_prefix(const IntList& a, const IntList& b);

IntList insert(int value, const IntList& a);

IntList insertion_sort(const IntList& a);

IntList binary(int n);
