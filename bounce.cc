#include <iostream>

const int minColumn = 0;
const int maxColumn = 80;

void move(double &particlePosition, double &particleSpeed);
void clear_screen(char screen[]);
void print_screen(char screen[]);
void draw(char screen[], double const particlePosition, char const particleSymbol);

int main() {
  int timeStep = 0;
  const int stopTime = 60;

  const int nParticles = 2;
  double particlePositions[nParticles] = {minColumn, maxColumn-1};
  double particleSpeeds[nParticles] = {6.3, -5.0};
  const char particleSymbols[nParticles] = {'x', '*'};

  char screen[maxColumn];

  while (timeStep < stopTime) {
    clear_screen(screen);
    for (int i = 0; i < nParticles; i++) {
      draw(screen, particlePositions[i], particleSymbols[i]);
      move(particlePositions[i], particleSpeeds[i]);
    }
    
    print_screen(screen);
    timeStep++;
  }
}


void draw(char screen[], const double pos, const char sym) {
  screen[static_cast<int>(pos)] = sym;
  
}

void print_screen(char screen[]) {
  for (int i = 0; i < maxColumn; i++) {
    std::cout << screen[i];
  }
  std::cout << std::endl;
}

void clear_screen(char screen[]) {
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

