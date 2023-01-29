// Header file
// Autumn Clark

#pragma once
#include <string>
#include <vector>
#include "BunnyClass.h"

class Farm {
private:
  std::vector<Bunny> bunnies;
  int roundsPast = 0;
  // Private methods for the simulation
  void Write(std::string& s);
  void BreedingRound();
  void RiseOfVampireBunnies();
  void ReportRound();
  void EndSimulation();
  void StartSimulation();
public:
  // Constructor
  Farm(int colonySize);
  // Methods
  std::vector<Bunny> GetBunnies() {return bunnies;}
};
