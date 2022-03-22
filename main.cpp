#include "urena-week4.h"

int main ()
{
  GetFileName();
  OpenFile();
  ReadContents();
  readData.close();

  ostream_iterator<string> FiletoVector {cout};
  *FiletoVector = "The vector now contains the contents from the file. Elements: \n";

  DisplayVectorContents(fileContent);
  KMConverter();
  
  ostream_iterator<string> Vector_in_KM {cout};
  *Vector_in_KM = "The vector's content has been converted from miles to kilometers and placed in a new vector. Elements:\n";
  DisplayVectorContents(fileContentinKM);

  ostream_iterator<string> copyVectors {cout};
  *copyVectors = "If you wish to copy these values into the original vector, please type Y\n";

  char y;
  cin >> y;  

  if (y == 'Y' | y == 'y')
    {
      fileContent.clear();     
      copy (fileContentinKM.begin(), fileContentinKM.end(), back_inserter(fileContent));//copy the content into the vector named fileContent
    }
  else
    exit (EXIT_SUCCESS);

  *copyVectors = "All Done! See below: \n";
  DisplayVectorContents(fileContent);

  return 0;
}
