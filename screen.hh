#ifndef Screen_hh
#define Screen_hh

const int minColumn = 0;
const int maxColumn = 80;               // the real world

class Screen {
public:
  Screen(int size)
    : buffer(new char[size]), size(size) {}
  Screen(const Screen & other);
  Screen& operator=(Screen other);
  friend void swap(Screen& lhs, Screen& rhs);
  ~Screen() {delete [] this->buffer;};
  void put(int const position, char const symbol);
  void print();
  void clear(); 
  char& operator[](unsigned int const pos);
  unsigned int get_size();

private:
  char* buffer;
  unsigned int size;        // number of columns

};

#endif   // Screen_hh


