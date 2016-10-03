#include <iostream>

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
  const char particleSymbol = 'x';
  double particlePosition = minColumn;
  double particleSpeed = 6.3;

  const char particleSymbol2 = '*';
  double particlePosition2 = maxColumn-1;
  double particleSpeed2 = -5.0;

  while (timeStep < stopTime) {
    clear_screen();
    draw(particlePosition, particleSymbol);
    draw(particlePosition2, particleSymbol2);
    move(particlePosition, particleSpeed);
    move(particlePosition2, particleSpeed2);
    print_screen();
    timeStep++;
  }
}


void draw(const double pos, const char sym) {
  // screen[static_cast<int>(pos)] = sym;
  screen[(int)pos] = sym; 
  // screen[pos] = sym;
  
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

