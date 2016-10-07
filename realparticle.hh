#ifndef RealParticle_hh
#define RealParticle_hh

#include <iostream>
#include "particle.hh"


class RealParticle : public Particle {
public:
  RealParticle () : Particle() {};
  RealParticle(char s, double p, double sp) : Particle(s, p, sp) {};
  virtual void move();
};

#endif
