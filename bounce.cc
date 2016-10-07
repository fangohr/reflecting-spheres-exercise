#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>

#include "particle.hh"
#include "screen.hh"
#include "array.hh"


int main() {

  std::string filename("config.txt");
  std::ifstream config(filename.c_str());
  if (!config) {
    std::cerr << "Could not open file " << filename << std::endl;
    return EXIT_FAILURE;
  }
  
  Array<Particle> particle;
  while (config) {
    Particle p;
    config >> p;
    if (!config) break;
    particle.push_back(p);
  }

  Screen screen(maxColumn + 1);
  
  int       timeStep = 0;
  int const stopTime = 60;
  
  while (timeStep < stopTime) {
    screen.clear();
    for (int p=0; p<particle.size(); ++p) {
      particle[p].draw(screen);
      particle[p].move();
    }
    screen.print();
    timeStep++;
  }
}
