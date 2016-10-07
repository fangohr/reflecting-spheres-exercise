#ifndef Array_hh
#define Array_hh

#include "particle.hh"

class Array {
private:
  Particle* buffer;
  unsigned N;
public:
  Array();
  ~Array() { delete [] buffer; }
  Array(const Array&);
  Array& operator=(Array);
  void push_back(Particle&);
  unsigned size() { return N; }
  Particle& operator[](const unsigned);
  friend void swap(Array& lhs, Array& rhs);
};

#endif // Array_hh
