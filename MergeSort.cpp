#include <iostream>
#include <math.h>
using namespace std;

void merge (int arr[], int left, int middle, int right)
{
  int temp;

  for (int i = left; i < middle; i++)
    {
      temp = 0; 
      if (arr[i+1] < arr[i])//arranges the array with lowest values "moving down" the array
	{
	  temp = arr[i+1];
	  arr[i+1] = arr[i];
	  arr[i] = temp;
	}
    }
  
  for (int k = middle; k < right; k++)
    {
      temp = 0; 
      if (arr[k+1] < arr[k])//arranges the array with lowest values "moving down" the array
	{
	  temp = arr[k+1];
	  arr[k+1] = arr[k];
	  arr[k] = temp;
	}
    }
}

void merge_sort(int arr[], int left, int right)
{
  int middle;
  int i =0;
  
  if (right%2 != 0) //if the array has an even number of elements
    middle = (right/2) + (right%2);//assign the middle number to be the higher element

  else
    middle = (left+right)/2;

  
  for (int i = 0; i<right; i++)
    {
      int temp;
      if (arr[i] > arr[i+1])
	{
	  temp = arr[i+1];
	  arr[i+1] = arr[i];
	  arr[i] = temp;
	}
      merge(arr, left, middle, right);
    }

    if (arr[left] > arr[middle])
    merge_sort(arr, left, middle);
  
  else if (arr[middle] > arr[right])
    merge_sort(arr, middle, right);
  
  else
    return;
}

int main ()
{
  int lst[] = {25, 20, 19, 18, 2, 1, 0};
  merge_sort(lst, 0, 6);

  for (int i = 0; i < 7; i++)
    cout << lst[i] << endl;
  return 0;
  }

