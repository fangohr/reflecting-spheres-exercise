
#include <cstdlib>                      // access to 'abort' -- there must be a more C++ like replacement?
#include <iostream>

const int minColumn = 0;
const int maxColumn = 80;               // the real world

struct Screen {
private:
  char* buffer;
  unsigned int size;        // number of columns
public:
  void initialize(int size) {
    this->size = size;
    this->buffer = new char[size];
  }

  void destroy() {
    delete [] this->buffer;
  }
  
  void put(int const position, char const symbol) {
    //assert(position < this->size);
    if (position >= this->size) {
      std::cout << "position is " << position << " but screen max column is " << this->size << std::endl;
      abort();
    }
    if (position < 0) {
      std::cout << "position is " << position << " but should be positive" << std::endl;
      abort();
    }
    
    this->buffer[position] = symbol;
  }

  void print() {
    for (int i = 0; i < this->size; i++) {
      std::cout << this->buffer[i];
    }
    std::cout << std::endl;
  }

  void clear() {
    for (int i = 0; i < this->size; i++) {
      this->buffer[i] = ' ';
    }
  }
};


struct Particle {
  char symbol;
  double position;
  double speed;
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

  void draw(Screen * const screen)  {
    screen->put(static_cast<int>(this->position), this->symbol);
  }
};

int main() {
  int timeStep = 0;
  const int stopTime = 60;
  const int nParticles = 2;

  Particle particles[nParticles];
  particles[0].initialize('x', minColumn, 6.3);
  particles[1].initialize('*', maxColumn-1, -5.0);
  
  Screen screen;
  screen.initialize(maxColumn+1);

  while (timeStep < stopTime) {
    screen.clear();
    for (int i = 0; i < nParticles; i++) {
      particles[i].draw(&screen);
      particles[i].move();
    }
    
    screen.print();
    timeStep++;
  }

  // de-allocate memory and destroy objects
  screen.destroy();
}


