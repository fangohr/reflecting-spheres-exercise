#include <iostream>

const int nParticles 2
const int minColumn = 0;
const int maxColumn = 80;

void draw(const double pos, const char sym);
void move(double &particlePosition, double &particleSpeed);
void clear_screen(void);
void print_screen(void);
void draw(double const particlePosition, char const particleSymbol);
char screen[maxColumn];


int main() {
  int timeStep = 0;
  const int stopTime = 60;
  double particlePositions[] = {minColumn, maxColumn-1};
  double particleSpeeds[] = {6.3, -5.0};
  const char particleSymbols[] = {'x', '*'};

  while (timeStep < stopTime) {
    clear_screen();
    for (int i = 0; i < nParticles; i++) {
      draw(particlePositions[i], particleSymbols[i]);
      move(particlePositions[i], particleSpeeds[i]);
    }
    
    print_screen();
    timeStep++;
  }
}


void draw(const double pos, const char sym) {
  screen[static_cast<int>(pos)] = sym;
  
}

void print_screen(void) {
  for (int i = 0; i < maxColumn; i++) {
    std::cout << screen[i];
  }
  std::cout << std::endl;
}

void clear_screen(void) {
  for (int i = 0; i < maxColumn; i++) {
    screen[i] = ' ';
  }
}

void move(double &particlePosition, double &particleSpeed) {
  particlePosition += particleSpeed;
  if (particlePosition >= maxColumn) {
    particlePosition = maxColumn;
    particleSpeed = -particleSpeed;
  } else if (particlePosition < minColumn) {
    particlePosition = minColumn;
    particleSpeed = -particleSpeed;
  }    
}

