#include <iostream>

const int minColumn = 0;
const int maxColumn = 80;


void draw(double pos, char sym) {
  for (int i = 0; i < pos; i++) {
    std::cout << " ";
  }
  std::cout << sym << std::endl;
}

void move(double particlePosition, double particleSpeed) {
  particlePosition += particleSpeed;
  if (particlePosition >= maxColumn) {
    particlePosition = maxColumn;
    particleSpeed = -particleSpeed;
  } else if (particlePosition < minColumn) {
    particlePosition = minColumn;
    particleSpeed = -particleSpeed;
  }    
}

int main() {
  char particleSymbol = 'x';
  double particlePosition = minColumn;
  double particleSpeed = 6.3;
  int timeStep = 0;
  int stopTime = 60;
  
  while (timeStep < stopTime) {
    draw(particlePosition, particleSymbol);
    move(particlePosition, particleSpeed);
    timeStep++;
  }
}
