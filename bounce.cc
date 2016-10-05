
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
    : size(size)
  {
    // cout << "Hello from the Screen constructor" << endl;
    // this->size = size;
    this->buffer = new char[size];
  }

  Screen(const Screen & other) {
    cout << "Hello from the Screen copy constructor" << endl;
    // other is the existing instance
    this->size = other.size;
    this->buffer = new char[this->size];
    // copy buffer data
    std::copy(other.buffer, other.buffer + other.size, this->buffer);

    // // manual version
    // for (int i=0; i< this->size; i++) {
    //   this->buffer[i] = other.buffer[i];
    // }
  }

  
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

private:
  char* buffer;
  unsigned int size;        // number of columns

};


class Particle {
public:
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
    screen.put(static_cast<int>(this->position), this->symbol);
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

  Particle particles[nParticles];
  particles[0].initialize('x', minColumn, 6.3);
  particles[1].initialize('*', maxColumn-1, -5.0);
  
  Screen screen(maxColumn+1);
  
  while (timeStep < stopTime) {
    screen.clear();
    for (int i = 0; i < nParticles; i++) {
      particles[i].draw(screen);
      particles[i].move();
    }
    
    screen.print();
    timeStep++;
  }
}


