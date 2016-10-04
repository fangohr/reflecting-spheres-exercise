#include <iostream>

const int minColumn = 0;
const int maxColumn = 80;               // the real world
const int screenSize = maxColumn + 1;   // buffer for the screen

void move(struct Particle * const particle);
void clear_screen(char * const screen);
void print_screen(char const * const screen);
void draw(char * const screen, struct Particle const * const particle);
void initialize(Particle *const particle, char const symbol, int const position, double const speed);

struct Particle {
  char symbol;
  double position;
  double speed;
};

int main() {
  int timeStep = 0;
  const int stopTime = 60;
  const int nParticles = 2;

  Particle particles[nParticles];
  initialize(&particles[0], 'x', minColumn, 6.3);
  initialize(&particles[0], 'x', maxColumn-1, -5.0);
  
  //chascreen[screenSize];
  char* screen = new char[screenSize];

  while (timeStep < stopTime) {
    clear_screen(screen);
    for (int i = 0; i < nParticles; i++) {
      draw(screen, particles+i);
      move(particles+i);
    }
    
    print_screen(screen);
    timeStep++;
  }

  // de-allocate memory and destroy objects
  delete [] screen;
}


//void draw(char screen[], const Particle& particle) {
void draw(char * const screen, Particle const * const particle) {
  screen[static_cast<int>(particle->position)] = particle->symbol;
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

void move(Particle *const particle) {
  particle->position += particle->speed;
  if (particle->position >= maxColumn) {
    particle->position = maxColumn;
    particle->speed = -particle->speed;
  } else if (particle->position < minColumn) {
    particle->position = minColumn;
    particle->speed = -particle->speed;
  }    
}

void initialize(Particle *const particle, char const symbol, int const position, double const speed)
{
  particle->symbol = symbol;
  particle->position = position;
  particle->speed = speed;

}
