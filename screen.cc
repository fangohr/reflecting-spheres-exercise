#include <iostream>
#include <algorithm>

#include "screen.hh"

using std::cout;
using std::endl;


Screen::Screen(const Screen & other)
  :  buffer(new char[other.size]), size(other.size)
{
  cout << "Hello from the Screen copy constructor" << endl;
  std::copy(other.buffer, other.buffer + other.size, this->buffer);
}

unsigned int Screen::get_size() {
  return this->size;
}

Screen& Screen::operator=(Screen other) {
  swap(*this, other);
  return *this;
}

void Screen::put(int const position, char const symbol) {
  //assert(position < this->size);
  if (position >= this->size) {
    cout << "position is " << position << " but screen max column is " << this->size << endl;
    abort();
  }
  if (position < 0) {
    cout << "position is " << position << " but should be positive" << endl;
    abort();
  }
    
  this->buffer[position] = symbol;
}

void Screen::print() {
  for (int i = 0; i < this->size; i++) {
    cout << this->buffer[i];
  }
  cout << endl;
}

void Screen::clear() {
  for (int i = 0; i < this->size; i++) {
    this->buffer[i] = ' ';
  }
}

char& Screen::operator[](unsigned int const pos) {
  return this->buffer[pos];
}

void swap(Screen& lhs, Screen& rhs) {
  using std::swap;
  swap(lhs.size, rhs.size);
  swap(lhs.buffer, rhs.buffer);
}

