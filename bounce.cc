#include <iostream>

const int minColumn = 0;
const int maxColumn = 80;               // the real world
const int bufferSize = maxColumn + 1;   // buffer for the screen

void clear_screen(char * const buffer);
void print_screen(char const * const buffer);

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

  void initialize(char const symbol_, int const position_, double const speed_)
  {
    symbol = symbol_;
    position = position_;
    speed = speed_;
  }

  void draw(char * const buffer) {
    buffer[static_cast<int>(position)] = symbol;
  }
};

int main() {
  int timeStep = 0;
  const int stopTime = 60;
  const int nParticles = 2;

  Particle particles[nParticles];
  particles[0].initialize('x', minColumn, 6.3);
  particles[1].initialize('*', maxColumn-1, -5.0);
  
    char* buffer = new char[bufferSize];

  while (timeStep < stopTime) {
    clear_screen(buffer);
    for (int i = 0; i < nParticles; i++) {
      particles[i].draw(buffer);
      particles[i].move();
    }
    
    print_screen(buffer);
    timeStep++;
  }

  // de-allocate memory and destroy objects
  delete [] buffer;
}


void print_screen(char const * const buffer) {
  for (int i = 0; i < bufferSize; i++) {
    std::cout << buffer[i];
  }
  std::cout << std::endl;
}

void clear_screen(char * const buffer) {
  for (int i = 0; i < bufferSize; i++) {
    buffer[i] = ' ';
  }
}
