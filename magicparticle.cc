#include "magicparticle.hh"

void MagicParticle::move() {
  position += speed;
  if (position >= maxColumn) {
    position = minColumn;
  } else if (position < minColumn) {
    position = maxColumn;
  }
}

