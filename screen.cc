#include <iostream>
#include <algorithm>

using std::cout; using std::endl;

#include "Screen.hh"

Screen::Screen(const Screen& other) : buffer(new char[other.size]), size(other.size) {
  std::copy(other.buffer, other.buffer + other.size, this->buffer);
}

Screen& Screen::operator=(Screen other) {
  std::swap(*this, other);
  return *this;
}

void Screen::put(char symbol, int position) {
  buffer[position] = symbol;
}

char& Screen::operator[](unsigned const pos) {
  return this->buffer[pos];
}

void Screen::clear() {
  for (unsigned i=0; i<this->size; ++i) {
    this->buffer[i] = ' ';
  }
}

void Screen::print() const {
  for (unsigned i=0; i<this->size; ++i) {
    cout << this->buffer[i];
  }
  cout << endl;
}

void swap(Screen& lhs, Screen& rhs) {
  using std::swap;
  swap(lhs.size,   rhs.size);
  swap(lhs.buffer, rhs.buffer);
}
