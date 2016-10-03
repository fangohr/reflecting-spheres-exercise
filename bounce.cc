#include <iostream>

int main() {

  char particleSymbol = 'x';
  double particlePosition = 0;
  double particleSpeed = 6.3;
  int minColumn = 0;
  int maxColumn = 80;
  int timeStep = 0;
  int stopTime = 60;
  
  while (timeStep < stopTime) {
    for (int i = minColumn; i < particlePosition; i++) {
      std::cout << " ";
    }
    std::cout << particleSymbol << std::endl;
    particlePosition += particleSpeed;
    if (particlePosition >= maxColumn) {
      particlePosition = maxColumn;
      particleSpeed = -particleSpeed;
    } else if (particlePosition < minColumn) {
      particlePosition = minColumn;
      particleSpeed = -particleSpeed;
    }    
    timeStep++;
  }
}
