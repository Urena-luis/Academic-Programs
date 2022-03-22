#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm> 
#include <string>
#include <array>
#include <iterator>

using namespace std;

//prevent multiple inclusions of header
#ifndef URENA_WEEK4_H
#define URENA_WEEK4_H

//converts each element from miles to kilometers
void KMConverter ();
  
//reads the contents of a text file containing double values and places them in a vector container
void ReadContents ();

// adds 50 double values to the newly-created file
void CreateTextFile ();

//adds file content if the file is empty
void AddFileContent();

void DisplayVectorContents (vector<double> vElements);

void OpenFile();

//gets the file name. If no file exists, it calls the CreateFile function
void GetFileName();
void FileFailure();

//


string fileName;
ofstream writeData; 
ifstream readData;
vector<double> fileContent;
vector<double> fileContentinKM;

#endif

