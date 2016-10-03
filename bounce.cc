#include <iostream>


void draw(double pos, char sym) {
  for (int i = 0; i < pos; i++) {
    std::cout << " ";
  }
  std::cout << sym << std::endl;
}

void move(double &particlePosition, double &particleSpeed, int maxColumn, int minColumn) {
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
  int minColumn = 0;
  int maxColumn = 80;
  char particleSymbol = 'x';
  double particlePosition = minColumn;
  double particleSpeed = 6.3;
  int timeStep = 0;
  int stopTime = 60;
  
  while (timeStep < stopTime) {
    draw(particlePosition, particleSymbol);
    move(particlePosition, particleSpeed, maxColumn, minColumn);
    timeStep++;
  }
}
