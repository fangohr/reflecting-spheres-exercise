
#include <cstdlib>   
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;

#include "screen.hh"


class Particle {
public:
  Particle() : symbol('-'), position(0.), speed(0.) {}; 
  Particle(char const symbol, int const position, double const speed):
    symbol(symbol), position(position), speed(speed) {};

  void move();
  void initialize(char const symbol, int const position, double const speed);
  void draw(Screen &screen) const; 

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








void Particle::move() {
  position += speed;
  if (position >= maxColumn) {
    position = maxColumn;
    speed = -speed;
  } else if (position < minColumn) {
    position = minColumn;
    speed = -speed;
  }    
}

void Particle::initialize(char const symbol, int const position, double const speed)
{
  this->symbol = symbol;
  this->position = position;
  this->speed = speed;
}

void Particle::draw(Screen &screen) const {
  screen[this->position] = this->symbol;
}




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

