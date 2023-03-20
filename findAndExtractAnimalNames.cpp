#include <iostream>
#include <fstream>
#include <string>
#include <exception>
using namespace std;

// genAnimalName.cpp
// dH 9/28/22
// demo file for midterm program Fall '22 CIT-66 C++ Programming
//
// Use this file to help you write the genAnimalName() function in
// your midterm program.
//
// Common Programming Errors:
//   No error handling for file IO
//   File not found error not reported
//   Miscounting number of lines in the file (open the file by hand, if possible, and check!)
//   Miscalculating array element length. the sizeof() method returns the number of bytes, not the number of elements.
//
// References:
//   https://www.w3schools.com/cpp/cpp_files.asp
//   https://www.w3schools.com/cpp/cpp_arrays_size.asp
//   https://www.w3schools.com/cpp/cpp_exceptions.asp
//

// text files are in the directory: C:/cStuff/midProgFiles/


int main(){
  ifstream myFile;
  string myStr = "";
  string fileName = "";
  int myPause = 0;
  int num1 = 0;

  // Open a file for reading.
  try {
    myFile.open("/Users/forgotenorb/Documents/Midterm/midterm-program-Forgotenorb/animalNames.txt");
  } catch (const ifstream::failure& e) {
      cout << "\n Cannot open file! ";
  }


  // What happens here if this file does not exist?
  // Not a lot it'll show you the prompt with nothing in it.
  // get this code working!
  try {
    getline(myFile, myStr);
  } catch (...) {
     cout << "\n Cannot open file (second try) " << endl;
  }


  // Read the file one line at a time.
  // TODO: Remove the file and see what happens...
  // TODO: Add error handling here to check for the file
  //if(remove("/Users/forgotenorb/Documents/Midterm/midterm-program-Forgotenorb/animalNames.txt") !=0) perror("Error removing file");
  // same thing happens when file doesn't exist it just shows mw the prompt it alos deleted the file.
  myPause = 0;
  while (getline(myFile, myStr) && myPause < 2) {
    cout << "\n  " << myStr;
    cout << " \n Enter 1 for next line, 2 to stop: ";
    cin >> myPause;
  }
  cout << "\n\n *********** end of while loop reading file a line at a time **********\n\n";

  // return to top of file
  myFile.clear();
  myFile.seekg(0);

  // Create an array for the file names
  // Examine the input file and see how many lines with Hyena names
  string fileNames[15];
  int linesHyenaNames = 3; 
  

  // Create an array with all lines
  string animals[15];
  int elementNum = 0;
  while (getline(myFile, myStr)) {
    animals[elementNum] = myStr;
    elementNum++;
  }

  // Output the new array
  for (int i=0; i<15; i++)
  {
      cout << "\n animals[" << i << "] = " << animals[i];
  }

  // Create an array without blank lines
  string betterAnimalNameArray[8];

  int subForNewArray = 0;
  for (int i=0; i<15; i+=2)
  {
      betterAnimalNameArray[subForNewArray] = animals[i];

      // increment because there are only eight elements in the better animal name array!
      subForNewArray++;
  }

  // Output the new array
  for (int i=0; i<8; i++)
  {
      cout << "\n betterAnimalNameArray[" << i << "] = " << betterAnimalNameArray[i];
  }


  // Use this array to demonstrate the find function
  string aAnimalStr = ",";
  aAnimalStr = betterAnimalNameArray[3];
  // looks like this:
  // Scar, Mufasa, Simba, Kiara, King, Drooper, Kimba, Nala, Leo, Samson, Elsa, Cecil

  cout << "\n\n\n The lion names: " << aAnimalStr << endl;

  int posOfcomma = 0;

  posOfcomma = aAnimalStr.find(",");
  cout << "\n\n posOfcomma = " << posOfcomma << "\n\n";
  // a comma was found at position number 4
  // remember that strings are numbered starting at 0
  // Use substr to extract characters in the string starting
  // at startPosition and with a size of subStrSize
  // Note: find() will return -1 if the argument is not found


  // Scar, Mufasa, Simba, Kiara, King, Drooper, Kimba, Nala, Leo, Samson, Elsa, Cecil

  // create three variables
  int startPosition = 14;
  int subStrSize = 5;
  string myLionName = "";

  // the first lion name starts at 0 and is 5 characters wide
  myLionName = aAnimalStr.substr(startPosition, subStrSize);

  cout << "\n\n myLionName = " << myLionName << "\n\n";







    // Close the file.
  myFile.close();

  // Where are the Hyena names in the array?
  //they are in animals[2]


}
