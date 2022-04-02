//assignment details: https://screenshot.googleplex.com/3qZRDSLtN3PQth5

#include <iostream>
using namespace std;

void swap (int *xp, int *yp)
{
  int temp;

  temp = *xp;
  *xp = *yp;
  *yp = temp;
}

int main ()
{
  int size = 6;
  int lst[] = {19,2, 20, 1, 0, 18};

  swap(&lst[0], &lst[1]);

  return 0;
}
