#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>

#include "particle.hh"
#include "magicparticle.hh"
#include "screen.hh"
// #include "array.hh"
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
    Particle *p = new Particle;
    config >> *p;
    if (!config) break;
    particle.push_back(p);
  }


 // load magic particles
 std::string filename_magic("config_magic.txt");
 std::ifstream config_magic(filename_magic.c_str());
 if (!config_magic) {
   std::cerr << "Could not open file " << filename_magic << std::endl;
   return EXIT_FAILURE;
 }
 
 while (config_magic) {
   //std::cout << "Here" << std::endl;
   MagicParticle *m = new MagicParticle;
   config_magic >> *m;
   if (!config_magic) break;
   particle.push_back(m);
 }


  Screen screen(maxColumn + 1);
  
  int       timeStep = 0;
  int const stopTime = 60;
  
  while (timeStep < stopTime) {
    //std::cout << "timestep = " << timeStep;
    //std::cout << "particle.size() = " << particle.size() << std::endl;
    //std::cout << "particle[0] = " << particle[0]->position << std::endl;
    screen.clear();
    for (int p=0; p<particle.size(); ++p) {
      particle[p]->draw(screen);
      particle[p]->move();
    }
    screen.print();
    timeStep++;
  }
}
