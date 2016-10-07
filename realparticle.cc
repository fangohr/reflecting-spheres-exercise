#include "realparticle.hh"

void RealParticle::move() {
  position += speed;
  if (position >= maxColumn) {
    position = maxColumn;
    speed = -speed;
  } else if (position < minColumn) {
    position = minColumn;
    speed = -speed;
  }
}

