//This implementation file is to be used in conjunction with main.cpp. The program prompts the user to input two values, a 'name' string and a 'score' integer. The file allows the user to keep entering scores until the user decides to quit.

#include "urena-week2.h"

void Score::setFile()
{
  fileName = " ";
  cout << "Please enter the file name" << endl;
  getline (cin, fileName);
   
  checkFile(outStream);  
}


void Score::checkFile(ofstream& outStream)
{
  int size = 50 - nameHeader.length();

  outStream.open (fileName, ios::app);//opens the file and ensures that new content is appended to the file's existing content.
  
  //exit program if unable to open create file
  if (!outStream)
    {
      cerr << "Output file opening failed. Try again" << endl;
      exit (EXIT_FAILURE);
    }
  
  cout << "File opened successfully" << endl;
  userInput();
}

void Score::userInput()
{
  cout << "Please enter a name"
       << endl;
  getline (cin, fullName);
  cout << "Please enter a score: ";
  cin >> score;
  cin.ignore(1,'\n');//gets rid of the stray newline that affects getline()
  
  results(fileName, fullName, score);
}

void Score::results (string fileName, string fullName, int score)
{
  int size = 50 - fullName.length();//gathers length to set width size
  outStream.seekp(0 , ios::end);//positions the pointer at the end of the file
  outStream << fullName << setw(size)
	    << score 
	    << endl;

  Continue(); //continue after the file's contents have been appended with the new entry
}

 void Score::Continue ()
{
  string cont;
  
  cout << "Press Y if you would like to continue"
       << endl;
  getline (cin, cont);
  
  if (cont == "y" || cont == "Y")
    {
      cont = " ";
      outStream.clear(); //reset eof for next input
      userInput(); //asks for new input for the same file
    }
  else
    {
      outputHigestScore ();
      outStream.close();
      exit (EXIT_SUCCESS);//close file successfully
    }
}

void Score::outputHigestScore ()
{
  ifstream inScoreFile (fileName, ios::in);
  
  int number = 0;
  string str;
  int largest = 0;
  
  if (inScoreFile >> str >> str)//if the file has two strings to begin with e.g, a first name and last name before the score
    {
      while (inScoreFile >> str >> str >> number)//read each iteration where there is a name and a score
	{
	  if (number >= largest)
	    largest = number;//saves the largest score
	}
    }
  else//if the file only has one string to begin e.g. a first name only
     while (inScoreFile >> str >> number)
	{
	  if (number >= largest)
	    largest = number;//saves the largest score
	}
    
  cout << "The highest score is: " << largest << endl;
  inScoreFile.close();
}
