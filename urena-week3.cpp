//This program asks the user to input an integer value and displays a message stating if the number is the largest value entered since the program started. 

#include "urena-week3.h"

int main()
{
  list<int> values = {};
  int largest;

  do
    {
      //adds a separation line for readability
      separator();
      cout << "Please enter a value" << endl;
      
      istream_iterator<int> inputStream{cin};
      int userInt = *inputStream;

      //user value goes to the back of the list
      values.push_back(userInt);

      //sort the list
      values.sort();
      
      //determines whether user input is the largest value
      valueComparison(userInt, values.back());
            
      cout << endl;
      separator();
      
    }while (!stop());
}

//determines whether the program stops or continues
bool stop ()
{
  ostream_iterator<string> userPrompt {cout};
  *userPrompt = "Please press the Y key if you'd like to continue\n";
  
  istream_iterator<string> response{cin};
  if (*response == "Yes" || *response == "yes" || *response== "y" || *response == "Y")    
    return false;

  else
    {
      return true;
        ostream_iterator<string> goodbye {cout};
	*goodbye = "See you later! \n";
      exit(EXIT_SUCCESS);
    }
}

  //compares user values
void valueComparison(int userValue, int largestValue)
{
  //informs the user the latest input is not the largest value
  if (userValue < largestValue)
    {
      ostream_iterator<string> notLargest {cout};
      *notLargest = "This is not the largest value since the program started. That distinction belongs to ";
      ostream_iterator<int> largest {cout};
      *largest = largestValue;
    }

  //informs the user the latest input is the largest value
  else if (userValue > largestValue)
    {
      ostream_iterator<string> confirmedLargest {cout};
      *confirmedLargest = "This is the largest value since the program started\n";
    } 

  //informs the user their latest value is equal to the largest value
  else if (userValue == largestValue)
    {
      ostream_iterator<string> confirmedLargest {cout};
      *confirmedLargest = "This is the same value as the largest value\n";
    } 
}


void separator()
{
  ostream_iterator<string> lineSeparation {cout};
  *lineSeparation = "__________________________________________________________________\n";
}
