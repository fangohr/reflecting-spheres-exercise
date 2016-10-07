#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>

#include "particle.hh"
#include "magicparticle.hh"
#include "screen.hh"
#include <vector>


int main() {

  std::string filename("config.txt");
  std::ifstream config(filename.c_str());
  if (!config) {
    std::cerr << "Could not open file " << filename << std::endl;
    return EXIT_FAILURE;
  }
  
  std::vector<Particle*> particle;
  while (config) {
    char type;
    config >> type;
    if (!config) break;
    if (type == 'r') {           // real particle
      Particle *p = new Particle;
      config >> *p;
      //p->repr();
      particle.push_back(p);
    }
    else {
      if (type == 'm') {         // magic particle
        MagicParticle *p = new MagicParticle;
        config >> *p;
        particle.push_back(p);
        //p->repr();
      }
      else {
        std::cerr << "expect type r or m in first config file column"
                  << std::endl;
        return EXIT_FAILURE;
      }
    }
  }

  Screen screen(maxColumn + 1);
  
  int       timeStep = 0;
  int const stopTime = 60;
  
  while (timeStep < stopTime) {
    screen.clear();
    for (int p=0; p<particle.size(); ++p) {
      particle[p]->draw(screen);
      particle[p]->move();
    }
    screen.print();
    timeStep++;
  }
}
