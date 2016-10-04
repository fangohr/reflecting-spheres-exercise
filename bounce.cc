#include <iostream>

const int minColumn = 0;
const int maxColumn = 80;               // the real world
const int screenSize = maxColumn + 1;   // buffer for the screen

void move(struct Particle &particle);
void clear_screen(char screen[]);
void print_screen(char screen[]);
void draw(char screen[], const struct Particle particle);

struct Particle {
  char symbol;
  double position;
  double speed;
};

int main() {
  int timeStep = 0;
  const int stopTime = 60;
  const int nParticles = 2;

  struct Particle particles[nParticles];
  particles[0].position = minColumn;
  particles[0].speed = 6.3;
  particles[0].symbol = 'x';
  particles[1].position = maxColumn-1;
  particles[1].speed = -5.0;
  particles[1].symbol = 'x';
  
  //chascreen[screenSize];
  char* screen = new char[screenSize];

  while (timeStep < stopTime) {
    clear_screen(screen);
    for (int i = 0; i < nParticles; i++) {
      draw(screen, particles[i]);
      move(particles[i]);
    }
    
    print_screen(screen);
    timeStep++;
  }

  // de-allocate memory and destroy objects
  delete [] screen;
}


void draw(char screen[], const struct Particle particle) {
  screen[static_cast<int>(particle.position)] = particle.symbol;
}

void print_screen(char screen[]) {
  for (int i = 0; i < screenSize; i++) {
    std::cout << screen[i];
  }
  std::cout << std::endl;
}

void clear_screen(char screen[]) {
  for (int i = 0; i < screenSize; i++) {
    screen[i] = ' ';
  }
}

void move(struct Particle &particle) {
  particle.position += particle.speed;
  if (particle.position >= maxColumn) {
    particle.position = maxColumn;
    particle.speed = -particle.speed;
  } else if (particle.position < minColumn) {
    particle.position = minColumn;
    particle.speed = -particle.speed;
  }    
}

