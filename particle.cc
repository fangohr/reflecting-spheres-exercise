#include "particle.hh"
#include "screen.hh"

const int minColumn =  0;
const int maxColumn = 80;


Particle& Particle::operator=(const Particle& other) {
  if (this != &other) {
    this->symbol = other.symbol;
    this->position = other.position;
    this->speed = other.speed;
  }
  return *this;
}

void Particle::draw(Screen& screen) const {
  screen[position] = symbol;
}


std::istream& operator>>(std::istream& in, Particle& p) {
  return in >> p.symbol >> p.position >> p.speed;
}

void Particle::repr() {
  std::cout << "Particle("
            << this->symbol  << ", "
            << this->position << ", "
            << this->speed << ")"
            << std::endl;
}
