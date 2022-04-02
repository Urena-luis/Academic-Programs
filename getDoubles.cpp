//Assignment details: https://screenshot.googleplex.com/67FAm8tS3iXEirP

#include <iostream>
using namespace std;

void addOne(int *ptrNum);
double* getDoubles (int numDoubles)
{
  int size = numDoubles;
  double * arr = new double[size];
  double temp = 1;
  for (int i = 0; i < size; i++)
    {
      arr[i] = temp/3;
      temp += 1;
      //cout << temp << endl;
      //cout << arr[i] << endl;
    }
  return arr;
}

int main ()
{
  int *inputPtr; //create a pointer
  int input = 0; // create an int with a value of 0
  inputPtr = &input; //assign the pointer the value of variable input
  
  addOne(inputPtr);
  getDoubles(4);
  
  return 0;
}

void addOne(int *ptrNum)
{
  *ptrNum += 1; //add one to the value of the variable that ptrNum is pointing to
  cout << *ptrNum;
}
