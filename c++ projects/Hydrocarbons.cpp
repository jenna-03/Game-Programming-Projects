// Jenna Nandlall 
// CS 2124
// rec03

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Hydrocarbon {
  vector<string> form_names;
  int num_hydrogens;
  int num_carbons;

};

//Function Prototypes

void OpenFile(ifstream& myStream);
void fillVector(ifstream&, vector<Hydrocarbon>& Hydrocarbons);
void insertInfo(vector<Hydrocarbon>& Hydrocarbons, string& new_name, int carbons, int hydrogens);
size_t find_duplicates(const vector<Hydrocarbon>& Hydrocarbons, int carbons, int hydrogens);
void sort_formulas(vector<Hydrocarbon>& Hydrocarbons);
void displayFormula(vector<Hydrocarbon> Hydrocarbons, size_t ind);
void displayVector(const vector<Hydrocarbon>& Hydrocarbons);



int main() {
  ifstream myStream;
  vector<Hydrocarbon> hydros;
  OpenFile(myStream);
  fillVector(myStream, hydros);
  myStream.close();
  sort_formulas(hydros);
  displayVector(hydros);
  
}


// Opens File (takes in input)
void OpenFile(ifstream& myStream) {
    do {
      myStream.clear();
      string myfile;
      cout << "Filename: " << endl;
      cin >> myfile;
      myStream.open(myfile);
    } while (!myStream);
  }
  

// Reads contents of file 
// Calls insertInfo function to fill the vector with the compounds in their respective locations

void fillVector(ifstream& myStream, vector<Hydrocarbon>& Hydrocarbons) {
    string new_name;
    int carbons;
    int hydrogens;
    char c;
    char h;

    while (myStream >> new_name >> c >> carbons >> h >> hydrogens) {
      insertInfo(Hydrocarbons, new_name, carbons, hydrogens);
  }
}


// Inserts the compund name and its carbon and hydrogen counts into new struct, then is added to Hydrocarbon vector
void insertInfo(vector<Hydrocarbon>& Hydrocarbons, string& new_name, int carbons, int hydrogens) {
    size_t formula_location;
    formula_location = find_duplicates(Hydrocarbons, carbons, hydrogens);
    Hydrocarbon newHydro;
    // If no duplicates, insert name and element counts into new struct then push back into vector
    if (formula_location == Hydrocarbons.size()) { 
      newHydro.form_names.push_back(new_name);
      newHydro.num_carbons = carbons;
      newHydro.num_hydrogens = hydrogens;
      Hydrocarbons.push_back(newHydro);
    }
    else {
      Hydrocarbons[formula_location].form_names.push_back(new_name); // if duplicates exist, push back name into vector
    }
  }

// Used to find if any duplicates of element counts exist in vector (returns index), if no duplicates then return size of vector
size_t find_duplicates(const vector<Hydrocarbon>& Hydrocarbons, int carbons, int hydrogens) {
    for (size_t i = 0; i < Hydrocarbons.size(); i++) {
          if (Hydrocarbons[i].num_carbons == carbons && Hydrocarbons[i].num_hydrogens == hydrogens) {
            return i;
          }
        }
        return Hydrocarbons.size();
      }

// Uses bubble sort to sort the elements from smallest Carbon count to largest; if carbon counts are the same then sort by hydrogen count
void sort_formulas(vector<Hydrocarbon>& Hydrocarbons) {
  for (size_t i = 0; i < Hydrocarbons.size(); i++) {
    for (size_t j = 0; j < Hydrocarbons.size()-1; j++) {
      if (Hydrocarbons[j].num_carbons > Hydrocarbons[j+1].num_carbons) {
        Hydrocarbon temp = Hydrocarbons[j];
        Hydrocarbons[j] = Hydrocarbons[j+1];
        Hydrocarbons[j+1] = temp;
      }
      else if (Hydrocarbons[j].num_carbons == Hydrocarbons[j+1].num_carbons && 
      Hydrocarbons[j].num_hydrogens > Hydrocarbons[j+1].num_hydrogens){
        Hydrocarbon temp = Hydrocarbons[j];
        Hydrocarbons[j] = Hydrocarbons[j+1];
        Hydrocarbons[j+1] = temp;
      }
    }
  }
}

// Prints out a single formula of a Hydrocarbon
void display_formula(const vector<Hydrocarbon>& Hydrocarbons, size_t ind) {
  cout << 'C' << Hydrocarbons[ind].num_carbons << 'H' << Hydrocarbons[ind].num_hydrogens << " ";
}


// Prints list of Hydrocarbons from vector 
void displayVector(const vector<Hydrocarbon>& Hydrocarbons) {
  for (size_t i = 0; i < Hydrocarbons.size(); i++) {
    display_formula(Hydrocarbons, i);
    for (size_t j = 0; j < Hydrocarbons[i].form_names.size(); j++) {
      cout << Hydrocarbons[i].form_names[j] << " ";
    }
    cout << endl;
  }
}
 
          




