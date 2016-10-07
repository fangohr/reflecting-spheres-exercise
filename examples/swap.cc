#include <iostream>


template<typename T>
void myswap(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}



int main() {
  int a = 1;
  int b = 2;
  std::cout << "a = " << a << " ";
  std::cout << "b = " << b << std::endl;
  myswap<int>(a, b);
  // std::swap(a, b);
  std::cout << "a = " << a <<  " ";
  std::cout << "b = " << b << std::endl;
}

    
