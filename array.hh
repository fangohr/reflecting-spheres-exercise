#ifndef Array_hh
#define Array_hh

#include "particle.hh"

template<class T>
class Array {
private:
  T* buffer;
  unsigned N;
public:
  Array();
  ~Array() { delete [] buffer; }
  Array(const Array&);
  Array& operator=(Array);
  void push_back(T&);
  unsigned size() { return N; }
  T& operator[](const unsigned);
  friend void swap(Array& lhs, Array& rhs);
};

//#include "array.cc"

#include <algorithm>
#include "array.hh"

template<typename T>
Array<T>::Array() : buffer(NULL), N(0) {}

template<typename T> Array<T>& Array<T>::operator=(Array other) {
  swap(*this, other);
  return *this;
}

template<typename T> Array<T>::Array(const Array& other)
  : buffer(new T[other.N]), N(other.N) {
  std::copy(other.buffer, other.buffer + N,
            this->buffer);
}

template<typename T>
void swap(Array<T>& lhs, Array<T>& rhs) {
  using std::swap;
  swap(lhs.buffer, rhs.buffer);
  swap(lhs.N, rhs.N);
}

template<typename T>
void Array<T>::push_back(T& p) {
  T* tmp = new T[N+1];
  std::copy(buffer, buffer+N, tmp);
  tmp[N] = p;
  delete [] buffer;
  buffer = tmp;
  N++;
}

template<typename T>
T& Array<T>::operator[](const unsigned n) {
  return this->buffer[n];
}


#endif // Array_hh

