// Bunny header file
// Autumn Clark

#pragma once
#include <string>
#include <vector>
#include "EnumsClass.h"

class Bunny {
  private:
    Gender gender;
    Color color;
    int age;
    std::string name;
    bool radioactive_mutant_vampire_bunny;
    // Vector of names for bunnies
    std::vector<std::string> namesList = {
      "Bugs","Lola","Olaf","Snowy","Sir Nibles",
      "Fluffy","Sparky","Winter","Summer","Ted Bundy",
      "Blue","The Loaf","Chunk","Lily","Clover",
      "Elmer","Jessica","Roger","Snowball","Pekora",
      "Bunnicula","Bunnicorn","Wererabbit","Bunnessie","Bunitaur"
    };
  public:
    // Constructor
    Bunny();
    // Constructor that passes a reference to a new Bunny's parents
    Bunny(Bunny const& b1, Bunny const& b2);
    // Methods
    Gender GetGender() const {return gender;}
    Color GetColor() const {return color;}
    int GetAge() const {return age;}
    std::string GetName() const {return name;}
    bool GetRadioactivity() const {return radioactive_mutant_vampire_bunny;}
    void MakeRadioactive() {radioactive_mutant_vampire_bunny = true;}
    bool IncrementAge();
};
