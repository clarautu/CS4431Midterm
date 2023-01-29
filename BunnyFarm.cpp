// Source file
// Autumn Clark

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include "BunnyClass.h"
#include "BunnyFarm.h"

// Private methods for the simulation

// Method that writes a string to a file and the command line
void Farm::Write(std::string& s){
  std::ofstream file; // Assigns the filestream as file
  static bool isNotFirstWrite; // Static boolean to determine if this is the first write
  if(!isNotFirstWrite){ // If first write, overwrite file -- don't append
    file.open("Mid_Clark_Output.txt"); // Open the file to write to
    isNotFirstWrite = true;
  } else{ // Else, append string to file
    file.open("Mid_Clark_Output.txt", std::fstream::app); // Open the file to write to
  }
  file << s << std::endl; // Write the string to the file
  file.close(); // Close the file
  std::cout << s << std::endl; // Also write to the command line
}

// Method that handles the breeding of Bunnies for each round
void Farm::BreedingRound(){
  std::string s; // String that anything printed will be assigned to before being passed to Write()
  std::vector<Bunny> sutors; // Vector of references to Bunnies that can mate
  // loop through bunnies
  for(int i=0; i<Farm::bunnies.size(); i++){
    Bunny& temp = Farm::bunnies.at(i); // Grab a reference to each Bunny for simplicity of code
    // Bunnies can't be radioactive and must be between 2 and 8
    if(!temp.GetRadioactivity() && temp.GetAge()>1 && temp.GetAge()<9){
      sutors.push_back(temp);
    }
  }
  // Pair Bunnies with each other
  // Loop through sutors until it is empty
  // std::cout << "There are " << sutors.size() << " sutors available." << std::endl;
  while(sutors.size() > 2){ // There needs to be at least 2 sutors to mate
    std::random_device rd; // Random numbers based on time for random seed
    std::default_random_engine generator(rd()); // Define the generator for random numbers
    std::uniform_int_distribution<int> dist(0,1); // Specify the distribution of random numbers
    bool didMate = false; // Boolean to track if a Bunny has mated yet

    Bunny& temp = sutors.back(); // Get a Bunny that wants to mate
    sutors.pop_back(); // Remove Bunny from the sutor pool

    if(temp.GetGender() == Gender::Male){ // Check gender of Bunny
      int index = 0; // Count for looping through sutors

      do{ // Infinite loop until a mate is found
        didMate = false; // Bunny has not mated
        Bunny& mate = sutors.at(index); // Grab a reference to a potentional mate
        if(mate.GetGender() == Gender::Female){ // Check if mate's gender is compatable
          Bunny b = Bunny(temp, mate); // If it is, mate and create a new Bunny
          Farm::bunnies.push_back(b); // Then add new bunny to colony
          s = "Bunny " + b.GetName() + " was born!";
          Farm::Write(s);
          sutors.erase(sutors.begin() + index); // Remove the mate from sutor list
          didMate = true; // Mark that this Bunny has mated
        } else if(mate.GetGender() == Gender::GenderX){ // If mate is GenderX
          int success = dist(generator);
          if(success == 1){ // They only have a 50% chance of mating
            Bunny b = Bunny(temp, mate); // If successful, mate and create a new Bunny
            Farm::bunnies.push_back(b); // Then add new bunny to colony
            s = "Bunny " + b.GetName() + " was born!";
            Farm::Write(s);
            sutors.erase(sutors.begin() + index); // Remove mate from sutor list
          }
          didMate = true; // Mark taht this Bunny has mated, even if it was unsuccessful
        }
        index++; // Increment index to try the next sutor
        if(index == sutors.size()){ // If the index has rached the end of sutors
          didMate = true; // All sutors have been checked -- no one to mate with
        }
      } while(!didMate);

    } else if(temp.GetGender() == Gender::Female){
      int index = 0; // Count for looping through sutors

      do{ // Infinite loop until a mate is found
        didMate = false; // Bunny has not mated
        Bunny& mate = sutors.at(index); // Grab a reference to a potentional mate
        if(mate.GetGender() == Gender::Male){ // Check if mate's gender is compatable
        Bunny b = Bunny(temp, mate); // If it is, mate and create a new Bunny
        Farm::bunnies.push_back(b); // Then add new bunny to colony
        s = "Bunny " + b.GetName() + " was born!";
        Farm::Write(s);
          sutors.erase(sutors.begin() + index); // Remove the mate from sutor list
          didMate = true; // Mark that this Bunny has mated
        } else if(mate.GetGender() == Gender::GenderX){ // If mate is GenderX
          int success = dist(generator);
          if(success == 1){ // They only have a 50% chance of mating
            Bunny b = Bunny(temp, mate); // If successful, mate and create a new Bunny
            Farm::bunnies.push_back(b); // Then add new bunny to colony
            s = "Bunny " + b.GetName() + " was born!";
            Farm::Write(s);
            sutors.erase(sutors.begin() + index); // Remove mate from sutor list
          }
          didMate = true; // Mark that this Bunny has mated, even if it was unsuccessful
        }
        index++; // Increment index to try the next sutor
        if(index == sutors.size()){ // If the index has rached the end of sutors
          didMate = true; // All sutors have been checked -- no one to mate with
        }
      } while(!didMate);

    } else{ // Bunny is GenderX -- will mate with first sutor available
      int index = 0; // Count for looping through sutors

      do{ // Loop until a mate is found
        didMate = false; // Bunny has not mated
        Bunny& mate = sutors.at(index); // Grab a reference to a potentional mate
        int success = dist(generator);
        if(success == 1){ // They only have a 50% chance of mating
          Bunny b = Bunny(temp, mate); // If successful, mate and create a new Bunny
          Farm::bunnies.push_back(b); // Then add new bunny to colony
          s = "Bunny " + b.GetName() + " was born!";
          Farm::Write(s);
          sutors.erase(sutors.begin() + index); // Remove mate from sutor list
        }
        didMate = true; // Mark that this Bunny has mated, even if it was unsuccessful
      } while(!didMate);
    }
  }
}

// Method that handles the vampire Bunnies converting of other Bunnies
void Farm::RiseOfVampireBunnies(){
  int vampireCount = 0; // Count how many vampire Bunnies there are
  // loop through bunnies
  for(int i=0; i<Farm::bunnies.size(); i++){
    Bunny& temp = Farm::bunnies.at(i); // Grab a reference to each Bunny for simplicity of code
    if(temp.GetRadioactivity()){ // If a vampire Bunny
      vampireCount++; // Increment vampireCount
    }
  }
  while(vampireCount > 0){ // Loop until all vampire Bunnies have changed another Bunny
    for(int i=Farm::bunnies.size()-1; i>=0; i--){ // Vampires get the youngest Bunny, as they are easy targets
      Bunny& temp = Farm::bunnies.at(i); // Grab a reference to each Bunny for simplicity of code
      if(!temp.GetRadioactivity()){ // If a Bunny isn't a vampire
        // Change into vampire Bunny
        temp.MakeRadioactive();
        break; // Break out of for loop -- this vampire has changed one Bunny
      }
    }
    vampireCount--;
  }
}

// Method that increments Bunny ages, round count,
  // removes dead Bunnies, and records everything
void Farm::ReportRound(){
  std::string s; // String that anything printed will be assigned to before being passed to Write()
  // Increment round count
  Farm::roundsPast++;
  s = "\nRound " + std::to_string(Farm::roundsPast); // Print out what round it is on
  Farm::Write(s);

  // Increment all Bunnies' ages
  std::vector<int> indexes; // Create a vector to hold the indexes of Bunnies that have died
  for(int i=0; i<Farm::bunnies.size(); i++){ // Loop through bunnies and increment all ages
    bool didBunnyDie = Farm::bunnies.at(i).IncrementAge(); // Catch if the Bunny died
  if(didBunnyDie){ //If the Bunny died, save the index to indexes
      indexes.push_back(i);
    }
  }
  // Report how many Bunnies have died this turn
  s = std::to_string(indexes.size()) + " bunnies have died this round:";
  Farm::Write(s);
  // Remove dead Bunnies separately from aging them -- avoids index complications
  for(int i=indexes.size()-1; i>=0; i--){ // Loop through indexes backwards -- indexs change for every Bunny after the Bunny removed, so going backwards fixes this complication
    s = "\tBunny " + Farm::bunnies.at(indexes.at(i)).GetName()
      + " has died at age " + std::to_string(Farm::bunnies.at(indexes.at(i)).GetAge());
    Farm::Write(s); // Report the Bunny's death
    Farm::bunnies.erase(Farm::bunnies.begin() + indexes.at(i)); // Erase each dead Bunny
  }

  s = "There are " + std::to_string(Farm::bunnies.size()) + " bunnies left:";
  Farm::Write(s);
  // Ints to count how many of each gender and how many are radioactive
  int maleCount=0, femaleCount=0, genXCount=0, radCount=0;
  for(int i=0; i<Farm::bunnies.size(); i++){
    Bunny& temp = Farm::bunnies.at(i);
    std::string gender;
    if(temp.GetGender() == Gender::Male){
      maleCount++;
      gender = "(M)"; // For optional detailed Bunny information
    } else if(temp.GetGender() == Gender::Female){
      femaleCount++;
      gender = "(F)"; // For optional detailed Bunny information
    } else{
      genXCount++;
      gender = "(X)"; // For optional detailed Bunny information
    }
    if(temp.GetRadioactivity()){
      radCount++;
    }
    /* // This code prints more detailed information for each round, but makes the simulation time go up drastically
    s = "\t" + temp.GetName() + ":    \t" + std::to_string(temp.GetAge())
      + gender + "\tRadioactive: " + (temp.GetRadioactivity() ? "True" : "False");
    Farm::Write(s);
    */
  }
  s = "\t\tThere are " + std::to_string(maleCount) + " male bunnies,\n\t\t"
    + std::to_string(femaleCount) + " female bunnies,\n\t\t"
    + std::to_string(genXCount) + " genderX bunnies, and\n\t\t"
    + std::to_string(radCount) + " radioactive mutant vampire bunnies.\n\n\n";
  Farm::Write(s);
}

// Method that reports the end of the colony and ending stats
void Farm::EndSimulation(){
  // All Bunnies have turned radioactive and then died
  // Print out simulation stats
  std::string s; // String that anything printed will be assigned to before being passed to Write()
  s = + "The simulation has ended.";
  Farm::Write(s);
  s = "It took " + std::to_string(Farm::roundsPast)
    + " rounds rounds for the Bunny colony to die off\n\tdue to radioactive mutant vampire Bunnies.";
  Farm::Write(s);
}

// Method that starts the simulation, calls other methods,
  // and determines when the simulation should be ended
void Farm::StartSimulation(){
  do { // Run the simulation until all Bunnies have died
    Farm::BreedingRound();
    Farm::RiseOfVampireBunnies();
    Farm::ReportRound();
  } while(Farm::bunnies.size() > 0);
  Farm::EndSimulation();
}

// Constructor
Farm::Farm(int colonySize) : bunnies(std::vector<Bunny>())
{
  for(int i=0;i<colonySize;i++) { // Add colonySize number of Bunnies to the vector bunnies
    bunnies.push_back(Bunny()); // Initial Bunnies can't be mutants
  }
  for(int i=0; i<Farm::bunnies.size(); i++){ // Announce each Bunny's birth
    std::string s = "Bunny " + Farm::bunnies.at(i).GetName() + " was born!";
    Farm::Write(s);
  }

  Farm::StartSimulation(); // Start the simulation
}
