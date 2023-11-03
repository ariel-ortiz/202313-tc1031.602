/*
  Declaración de la interfaz de la clase IntList (lista de enteros)
  y funciones auxiliares.

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

#pragma once

#include <initializer_list>
#include <iostream>
#include <string>

class IntList {
public:
    IntList() {}
    IntList(std::initializer_list<int> args);
    IntList(const IntList& other);
    ~IntList();
    IntList& operator=(const IntList& other);
    bool operator==(const IntList& other) const;
    std::string to_string() const;
private:
    int* _values {};
    int _size {};
    int _first() const;
    IntList _rest() const;
    IntList _cons(int value) const;
    bool _is_empty() const;
    friend int first(const IntList& a);
    friend IntList rest(const IntList& a);
    friend IntList cons(int value, const IntList& a);
    friend bool is_empty(const IntList& a);
};

std::ostream& operator<<(std::ostream& out, const IntList& a);

int first(const IntList& a);

IntList rest(const IntList& a);

IntList cons(int value, const IntList& a);

bool is_empty(const IntList& a);
