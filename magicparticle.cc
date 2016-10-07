#include "magicparticle.hh"

void MagicParticle::move() {
  position += speed;
  if (position >= maxColumn) {
    //position = maxColumn;
    position = minColumn;
    //
    //speed = -speed;
  } else if (position < minColumn) {
    position = maxColumn-1;
    //speed = -speed;
  }
  //std::cout << "Been in MagicParticle:::move()" << std::endl;
}

