// Jenna Nandlall
// CS 2124
// rec02

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main () {
  ifstream gamefile("life.txt");
  
  vector<string> initialGen;
  string line;
  while (getline(gamefile, line)) {
    initialGen.push_back(line);
  }
  cout << "Initial World:" << endl;
  for (size_t row = 0; row < initialGen.size(); row++) {
    for (size_t col = 0; col < initialGen[row].size(); col++) {
        cout << initialGen[row][col];
    }
    cout << endl;
  }
  


for (int genNum = 1; genNum <= 10; genNum++) {
  vector<string> newGen;
  for (size_t row = 0; row < initialGen.size(); row++) {
    string newline;
    for (size_t col = 0; col < initialGen[row].size(); col++) {
      int aliveNeighbors = 0;
      if (row > 0) {
          if (initialGen[row-1][col] == '*') { // top neighbor
            aliveNeighbors +=1 ;
          }
        
          if (col > 0) {
            if (initialGen[row-1][col-1] == '*') { // top left neighbor
              aliveNeighbors +=1;
          }
        }
          if (col + 1 < initialGen[row].size()) {
            if (initialGen[row-1][col + 1]  == '*') { //top right neighbor
              aliveNeighbors +=1;
          } 
        }
      }

      if (col > 0) {
        if (initialGen[row][col - 1]  == '*') { // left neighbor
          aliveNeighbors +=1;
        }
      }

      if (col + 1 < initialGen[row].size()) {
        if (initialGen[row][col + 1]  == '*') { // right diagonal
          aliveNeighbors +=1;
        } 
      }

      if (row + 1 < initialGen.size()) {
          if (initialGen[row + 1][col]  == '*') { // bottom right diagonal
            aliveNeighbors +=1; 
          }
          if (col > 0) {
            if (initialGen[row+1][col-1] == '*') { //top left diagonal
            aliveNeighbors +=1; 
            }
          }
          if (col + 1 < initialGen[row].size()) {
            if (initialGen[row+1][col+1] == '*') { //top right diagonal
              aliveNeighbors +=1;
            }
          }
      }
      
      if (initialGen[row][col] == '*') {
        if(aliveNeighbors == 2 || aliveNeighbors == 3) {
          newline = newline + '*';
      }
      else {
          newline = newline + '-';
       }
      }
      
      else {
        if (aliveNeighbors == 3) {
          newline = newline + '*';
          }
        else {
          newline = newline + '-';
        }
      }
    }
    newGen.push_back(newline); 
  }
    initialGen = newGen;
    cout << "====================" << endl;
    cout << "Generation: " << genNum << endl;
    for (size_t row = 0; row < initialGen.size(); row++) {
    for (size_t col = 0; col < initialGen[row].size(); col++) {
        cout << initialGen[row][col];
        }
          cout << endl;

        }

        
}
    cout << "====================" << endl;
    gamefile.close();
    
    }