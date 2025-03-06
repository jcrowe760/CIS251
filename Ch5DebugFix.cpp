// Program 2 (Debugging Exercise)
// Objectives: Increment/Decrement, Loops (for, do-while), Nested Loops, File I/O, Break/Continue
//Starting from 0, count down by 1 a total of 24 times and ouput these numbers to a text file
//Josh Crowe

#include <iostream>
#include <fstream>
using namespace std;

int main() 
{
  ofstream outFile("data2.txt");
  int j = 0;
  //Set i=0, condition: i<3, increment for each iteration for a total of 3 iterations
  for (int i = 0; i < 3; i++) 
  {
    //Moved count to inside the for loop so it resets everytime the loop runs
    int count = 0;
    //Alternatively, could initialize 'j' outside for loop so it does NOT reset, which I did
    //Otherwise it will simply restart and count from -1 to -8 three times in a row
    //Changed to a plain 'while' loop because I like those better
    while (count <= 7) 
    { 
      //Decrements J and adds to file, then increment count.
      outFile << --j << " ";
      count++;
    }
  }
  outFile.close();
//Open and read the file
  ifstream inFile("data2.txt");
  int value;
  while (inFile >> value) 
  {
    //Added comma to output for readability- was blank space
    cout << value << ", ";
  }
  cout << endl;
  inFile.close();
  return 0;
}