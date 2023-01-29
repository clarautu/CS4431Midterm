// Mid Project
// Autumn Clark
// Program that simulates a small bunny ecosystem

#include <iostream>
#include <vector>
#include <string>
#include "BunnyClass.h"
#include "BunnyFarm.h"

int main() {
  // Initialize a Farm of 10 Bunnies -- Farm class runs the simulation
  Farm f = Farm(10);





  /* // Test code -- Bunny methods
  Bunny b1 = Bunny();
  std::cout << b1.GetAge() << std::endl;
  std::cout << b1.GetName() << std::endl;
  std::cout << rand() % 99 << std::endl;
  std::cout << "b1's aging:" << std::endl;
  for(int i=0; i<11; i++){
    bool didDie = b1.IncrementAge();
    std::cout << b1.GetAge() << " Dead? " << (didDie ? "True" : "False") << std::endl;
  }
  Bunny b1 = Bunny();
  std::cout << "Bunny b1 is " << b1.GetName() << std::endl;
  std::cout << "Radioactive: " << (b1.GetRadioactivity() ? "True" : "False") << std::endl;
  for(int i=0;i<11;i++){
    std::cout << "Round " << i+1 << std::endl;
    b1.IncrementAge();
  }
  */
  /* // Test code -- vector.erase()
  std::vector<Bunny> bunnies;
  for(int i=0; i<10; i++){
    Bunny temp = Bunny();
    std::cout << "Bunny " << temp.GetName() << " was born! #" << i << std::endl;
    bunnies.push_back(temp);
  }
  std::cout << "Size of vector: " << bunnies.size() << std::endl;
  bunnies.erase(bunnies.begin() + 3);
  bunnies.erase(bunnies.begin() + 4);
  for(int i=0; i<bunnies.size(); i++){
    std::cout << "Bunny " << bunnies.at(i).GetName() << " is still alive." << std::endl;
  }
  std::cout << "Size of vector now: " << bunnies.size() << std::endl;
  */
  /* // Test code -- Initial test of Farm class
  for(int i=0;i<f.GetBunnies().size();i++){
    std::cout << f.GetBunnies().at(i).GetName() << std::endl; // Print all Bunny names
  }
  */

  return 0;
}
