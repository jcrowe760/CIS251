// Program 2 (Debugging Exercise)
// Objectives: Increment/Decrement, Loops (for, do-while), Nested Loops, File I/O, Break/Continue
//This program attempts to count down from zero and add those numbers to a file...at least I think so?
//I also think it's supposed to output a total of 24 numbers to the file
//Josh Crowe

#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ofstream outFile("data2.txt");
  int count = 0;
  //Set i=0, condition: i<3, increment)
  for (int i = 0; i < 3; i++) {
    //Cout statement to ensure i is being incremented properly
    // cout << "i is equal to: " << i << endl;
    int j = 0;
    //While j<3, test these conditions
    //This while loop is also supposed to run 3 times, once for every iteration of the 'for' loop-
    //-yet the output only displays 8 numbers. This is because "count" is never updated, so-
    //-the while loop does technically run 3 times, but it breaks immediately after the first time through
    do { 
       //This statement is never true because i is being incremented and j is being decremented
       //Additionally, if i+j==3, the loop would run forever
        if (i + j == 3)
      {
        //cout to show infinite loop
        cout << "I and J are equal!";
        continue;
      }
      //Stops once 8 numbers have been added to the file
      //If not for this statement, the loop would run forever
      if (count++ > 7) 
      {
        break;
      }
      //Decrements J and adds to file
      outFile << --j << " ";
      //This while condition is always true, because J starts at 0 and is being decremented it will always be < 3
      //If not for the above if statement, the loop would run forever
      //Should set to: do...while (count++ <= 7)
    } while (j < 3);
  }
  outFile.close();
//This block works!
  ifstream inFile("data2.txt");
  int value;
  while (inFile >> value) {
    cout << value << " ";
  }
  cout << endl;
  inFile.close();
  return 0;
}
