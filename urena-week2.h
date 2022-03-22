//Score class declaration. Member functions are defined in urena-week2.cpp
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string> //needed to use getline()
#include <iomanip>//used for setw()

using namespace std;

//prevent multiple inclusions of the header
#ifndef URENA_WEEK2_H
#define URENA_WEEK2_H

//class definition
class Score
{
 public:
  void userInput();
  void Continue();
  void results(string fileName, string fullName, int score);
  void checkFile (ofstream& outStream);
  void setFile ();
  void outputHigestScore ();
  
  ofstream outStream;
  string fileName;
  string fullName;
  int score;
};
#endif
