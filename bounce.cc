
#include <cstdlib>                      // access to 'abort' -- there must be a more C++ like replacement?
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;

const int minColumn = 0;
const int maxColumn = 80;               // the real world

class Screen {
public:
  Screen(int size)
    : buffer(new char[size]), size(size)
  {
    // cout << "Hello from the Screen constructor" << endl;
  }

  Screen(const Screen & other)
    :  buffer(new char[other.size]), size(other.size)
  {
    cout << "Hello from the Screen copy constructor" << endl;
    // copy buffer data
    std::copy(other.buffer, other.buffer + other.size, this->buffer);

    // // manual version
    // for (int i=0; i< this->size; i++) {
    //   this->buffer[i] = other.buffer[i];
    // }
  }

  Screen& operator=(Screen other) {
    swap(*this, other);
    return *this;
  }

  friend void swap(Screen& lhs, Screen& rhs);

  ~Screen() {
    cout << "Hello from the Screen deconstructor" << endl;
    delete [] this->buffer;
  }
  
  void put(int const position, char const symbol) {
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

  void print() {
    for (int i = 0; i < this->size; i++) {
      cout << this->buffer[i];
    }
    cout << endl;
  }

  void clear() {
    for (int i = 0; i < this->size; i++) {
      this->buffer[i] = ' ';
    }
  }

  char& operator[](unsigned int const pos) {
    return this->buffer[pos];
  }

  unsigned int get_size() {
    return this->size;
  }

private:
  char* buffer;
  unsigned int size;        // number of columns

};


void swap(Screen& lhs, Screen& rhs) {
  using std::swap;
  swap(lhs.size, rhs.size);
  swap(lhs.buffer, rhs.buffer);
}


class Particle {
public:
  Particle() : symbol('-'), position(0.), speed(0.) {}; 
  Particle(char const symbol, int const position, double const speed):
    symbol(symbol), position(position), speed(speed) {};

  void move() {
    position += speed;
    if (position >= maxColumn) {
      position = maxColumn;
      speed = -speed;
    } else if (position < minColumn) {
      position = minColumn;
      speed = -speed;
    }    
  }

  void initialize(char const symbol, int const position, double const speed)
  {
    this->symbol = symbol;
    this->position = position;
    this->speed = speed;
  }

  void draw(Screen &screen) const {
    screen[this->position] = this->symbol;
  }

  Particle& operator=(const Particle& other) {
    //cout << "In Particle::operator=" << endl;
    
    if (this != &other) {  // only if this and other are different,
                           // avoid self assignment.
      this->symbol = other.symbol;
      this->position = other.position;
      this->speed = other.speed;
    }
    return *this;
  }
  

private:
  char symbol;
  double position;
  double speed;
};

int main() {
  int timeStep = 0;
  const int stopTime = 60;
  const int nParticles = 2;

  Particle particles[nParticles] = {
    Particle('x', minColumn, 6.3),
    Particle('*', maxColumn-1, -5.0)
  };

  // do initialisation again to use assignment operator
  particles[0] = Particle('x', minColumn, 6.3);
  particles[1] = Particle('*', maxColumn-1, -5.0);
  
  Screen screen(maxColumn+1);
  // cout << "size of screen = " << screen.get_size() << endl;
  // Screen screen2(3);
  // screen2 = screen;
  // cout << "size of screen2 = " << screen2.get_size() << endl;
  
  while ((timeStep < stopTime) && true) {
    screen.clear();
    for (int i = 0; i < nParticles; i++) {
      particles[i].draw(screen);
      particles[i].move();
    }
    
    screen.print();
    timeStep++;
  }


  // // would be nice to have some tests
  Screen screen2(3);
  Screen screen3(5);
  if (screen2.get_size() != 3) {
    cout << "error (mark 0)" << endl;
    abort();
  }

  if (screen3.get_size() != 5) {
    cout << "error (mark 0)" << endl;
    abort();
  }

  screen3 = screen2;
  
  if (screen2.get_size() != 3) {
    cout << "error (mark 1)" << endl;
    abort();
  }
  if (screen3.get_size() != 3) {
    cout << "error (mark 2)" << endl;
    abort();
  }
    
  
  
}

