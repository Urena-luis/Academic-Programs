//assignment details: https://screenshot.googleplex.com/3Cxrcg5ybtPbfRy

#include <iostream>
using namespace std;

int linear_search (int search, int arr[], int elements)
{
  int result;
  for (int i = 0; i< elements; i++)
    {
      if (search == arr[i])
	{
	  result = i + 1;
	  return result;
	}
      else
	result = i+1;
    }
  return result;
}

int main ()
{

  int lst[] = {19, 2, 20, 1, 0, 18};

  cout << linear_search(210, lst, 6) << endl;

  return 0;
}
