#include <algorithm>
#include "array.hh"

Array::Array() : buffer(NULL), N(0) {}

Array& Array::operator=(Array other) {
  swap(*this, other);
  return *this;
}

Array::Array(const Array& other)
  : buffer(new Particle[other.N]), N(other.N) {
  std::copy(other.buffer, other.buffer + N,
            this->buffer);
}

void swap(Array& lhs, Array& rhs) {
  using std::swap;
  swap(lhs.buffer, rhs.buffer);
  swap(lhs.N, rhs.N);
}

void Array::push_back(Particle& p) {
  Particle* tmp = new Particle[N+1];
  std::copy(buffer, buffer+N, tmp);
  tmp[N] = p;
  delete [] buffer;
  buffer = tmp;
  N++;
}

Particle& Array::operator[](const unsigned n) {
  return this->buffer[n];
}
