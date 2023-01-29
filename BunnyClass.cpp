// Bunny source file
// Autumn Clark

#include <string>
#include <random> // For random numbers
#include "BunnyClass.h"
#include "EnumsClass.h"


  // Constructor
  Bunny::Bunny() :
  age(0) // Age: starts at 0, dies after 10
  {
    std::random_device rd; // Random numbers based on time for random seed
    std::default_random_engine generator(rd()); // Define the generator for random numbers
    // Gender: 0.47/0.47/0.06
    std::uniform_int_distribution<int> distg(0,99); // Specify the distribution of random numbers
    int g = distg(generator); // Returns a random number between 0 and 99
    if(g < 47){
      Bunny::gender = Gender::Male;
    } else if(g < 94){
      Bunny::gender = Gender::Female;
    } else {
      Bunny::gender = Gender::GenderX;
    }
    // Color: equal prob.
    std::uniform_int_distribution<int> distc(0,3); // Specify the distribution of random numbers
    int c = distc(generator); // Returns a random number between 0 and 3
    if(c==0){
      Bunny::color = Color::White;
    } else if(c==1){
      Bunny::color = Color::Brown;
    } else if(c==2){
      Bunny::color = Color::Black;
    } else {
      Bunny::color = Color::Spotted;
    }
    // Name: equal prob.
    std::uniform_int_distribution<int> distn(0,(Bunny::namesList.size()-1)); // Specify the distribution of random numbers
    int n = distn(generator); // Returns a random number between 0 and the last index of namesList
    Bunny::name = Bunny::namesList.at(n);
    // Initial Bunnies are not radioactive
    Bunny::radioactive_mutant_vampire_bunny = false;

  }

  // Constructor that passes a reference to a new Bunny's parents
  Bunny::Bunny(Bunny const& b1, Bunny const& b2) :
  age(0) // Age: starts at 0, dies after 10 -- unless radioactive then after 50
  {
    std::random_device rd; // Random numbers based on time for random seed
    std::default_random_engine generator(rd()); // Define the generator for random numbers
    // Gender: 0.47/0.47/0.06
    std::uniform_int_distribution<int> distg(0,99); // Specify the distribution of random numbers
    int g = distg(generator); // Returns a random number between 0 and 99
    if(g < 47){
      Bunny::gender = Gender::Male;
    } else if(g < 94){
      Bunny::gender = Gender::Female;
    } else {
      Bunny::gender = Gender::GenderX;
    }
    // Color: equal prob.
    std::uniform_int_distribution<int> distc(0,1); // Specify the distribution of random numbers
    int c = distc(generator); // Returns a random number between 0 and 1
    if(c==0){
      Bunny::color = b1.GetColor();
    } else {
      Bunny::color = b2.GetColor();
    }
    // Name: equal prob.
    std::uniform_int_distribution<int> distn(0,(Bunny::namesList.size()-1)); // Specify the distribution of random numbers
    int n = distn(generator); // Returns a random number between 0 and the last index of namesList
    Bunny::name = Bunny::namesList.at(n);
    // Radioactive: 0.03
    std::uniform_int_distribution<int> distr(0,99); // Specify the distribution of random numbers
    int r = distr(generator); // Returns a random number between 0 and 99
    if(r < 2){
      Bunny::radioactive_mutant_vampire_bunny = true;
    } else {
      Bunny::radioactive_mutant_vampire_bunny = false;
    }
  }

  // Method that increments a Bunny's age up a year; returns true if the bunny died
  bool Bunny::IncrementAge() {
    age++;
    if(radioactive_mutant_vampire_bunny){
      if(age > 50){
        return true;
      }
    } else if(age > 10){
      return true;
    }
    return false;
  }
