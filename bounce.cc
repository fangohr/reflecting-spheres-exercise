#include <iostream>

const int minColumn = 0;
const int maxColumn = 80;               // the real world
const int screenSize = maxColumn + 1;   // buffer for the screen

void clear_screen(char * const screen);
void print_screen(char const * const screen);

struct Particle {
  char symbol;
  double position;
  double speed;
  void move() {
    this->position += this->speed;
    if (this->position >= maxColumn) {
      this->position = maxColumn;
      this->speed = -this->speed;
    } else if (this->position < minColumn) {
      this->position = minColumn;
      this->speed = -this->speed;
    }    
  }

  void initialize(char const symbol, int const position, double const speed)
  {
    this->symbol = symbol;
    this->position = position;
    this->speed = speed;
  }

  void draw(char * const screen) {
    screen[static_cast<int>(this->position)] = this->symbol;
  }
};

int main() {
  int timeStep = 0;
  const int stopTime = 60;
  const int nParticles = 2;

  Particle particles[nParticles];
  particles[0].initialize('x', minColumn, 6.3);
  particles[1].initialize('*', maxColumn-1, -5.0);
  
    char* screen = new char[screenSize];

  while (timeStep < stopTime) {
    clear_screen(screen);
    for (int i = 0; i < nParticles; i++) {
      particles[i].draw(screen);
      particles[i].move();
    }
    
    print_screen(screen);
    timeStep++;
  }

  // de-allocate memory and destroy objects
  delete [] screen;
}


void print_screen(char const * const screen) {
  for (int i = 0; i < screenSize; i++) {
    std::cout << screen[i];
  }
  std::cout << std::endl;
}

void clear_screen(char * const screen) {
  for (int i = 0; i < screenSize; i++) {
    screen[i] = ' ';
  }
}
