/*
  Implementación de la clase IntList (lista de enteros) y funciones
  auxiliares.

  Copyright (C) 2021 Ariel Ortiz, ITESM CEM

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  See: http://www.gnu.org/licenses/
*/

#include <algorithm>
#include <sstream>
#include <stdexcept>
#include "intlist.h"

IntList::IntList(std::initializer_list<int> args)
{
    _size = args.size();
    _values = new int[_size];
    int i = 0;
    for (int value : args) {
        _values[i] = value;
        ++i;
    }
}

IntList::IntList(const IntList& other)
{
    if (other._values) {
        _size = other._size;
        _values = new int[_size];
        std::copy(other._values, other._values + _size, _values);
    }
}

IntList::~IntList()
{
    delete []_values;
}

IntList& IntList::operator=(const IntList& other)
{
    delete []_values;
    _values = nullptr;
    _size = 0;
    if (other._values) {
        _values = new int[_size];
        std::copy(other._values, other._values + _size, _values);
        _size = other._size;
    }
    return *this;
}

bool IntList::operator==(const IntList& other) const
{
    if (_size != other._size) {
        return false;
    }
    for (int i = 0; i < _size; ++i) {
        if (_values[i] != other._values[i]) {
            return false;
        }
    }
    return true;
}

std::string IntList::to_string() const
{
    std::ostringstream result;
    result << "{";

    bool first_time = true;
    for (int i = 0; i < _size; ++i) {
        if (first_time) {
            first_time = false;
        } else {
            result << ", ";
        }
        result << _values[i];
    }

    result << "}";
    return result.str();
}

int IntList::_first() const
{
    if (_values) {
        return _values[0];
    } else {
        throw std::invalid_argument("Can't call first on an empty list");
    }
}

IntList IntList::_rest() const
{
    if (_values) {
        IntList result;
        result._size = _size - 1;
        result._values = new int[result._size];
        std::copy(_values + 1, _values + _size, result._values);

        return result;
    } else {
        throw std::invalid_argument("Can't call rest on an empty list");
    }
}

IntList IntList::_cons(int value) const
{
    IntList result;
    result._size = _size + 1;
    result._values = new int[result._size];
    result._values[0] = value;
    std::copy(_values, _values + _size, result._values + 1);
    return result;
}

bool IntList::_is_empty() const
{
    return _size == 0;
}

std::ostream& operator<<(std::ostream& out, const IntList& a)
{
    return out << a.to_string();
}

int first(const IntList& a)
{
    return a._first();
}

IntList rest(const IntList& a)
{
    return a._rest();
}

IntList cons(int value, const IntList& a)
{
    return a._cons(value);
}

bool is_empty(const IntList& a)
{
    return a._is_empty();
}
