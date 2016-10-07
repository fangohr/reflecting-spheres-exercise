#ifndef MagicParticle_hh
#define MagicParticle_hh

#include <iostream>
#include "particle.hh"


class MagicParticle : public Particle {
public:
  MagicParticle () : Particle() {};
  MagicParticle(char s, double p, double sp) : Particle(s, p, sp) {};
  virtual void move();
};

#endif
