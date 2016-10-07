#ifndef Screen_hh
#define Screen_hh

class Screen {
public:
  Screen(unsigned size) : buffer(new char[size]), size(size) {}
  Screen(const Screen& other);
  ~Screen() { delete [] this->buffer; }
  Screen& operator=(Screen other);
  void put(char symbol, int position);
  char& operator[](unsigned const pos);
  void clear();
  void print() const;
  friend void swap(Screen& lhs, Screen& rhs);
private:
  char* buffer;
  unsigned size;
};

#endif
