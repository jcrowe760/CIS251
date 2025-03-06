/*Calculate a Running Total for user defined set of numbers to be entered
Ask the user how many numbers they would like to enter to be added together for a running total
and perform the specified operation on the numbers and output the result of the operation.
Choose the type of repetition structure (loop) to be used for input of the numbers.
Remember to verify and validate your input*/
//Josh Crowe
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    int total = 0;
    int count = 0;
    int amountNum;
    int nums;
    //Create file to later append numbers to it
    ofstream outFile("numbers.txt", ios::app);
    //Determine how many numbers the user would like to enter
    cout << "How many numbers would you like to enter? " << endl;
    //Input validation. While user input is invalid, continue asking for a number.
    while(!(cin >> amountNum))
    {
        cout << "Invalid input. Please enter how many numbers you would like to input." << endl;
        cin.clear(); //Clears fail flag
        cin.ignore(); //Need cin.ignore to clear input buffer, otherwise cin will continue to read the invalid input forever
        continue;
    }
    cout << "You requested to enter " << amountNum << " numbers" << endl;
    cout << "Enter the numbers: " << endl;
    cout << "-------------------" << endl;
    //Main loop that has the user input numbers as long as the amount of numbers entered-
    //-does not equal the amount of numbers the user requested to enter
    while (count != amountNum)
    {
        cin >> nums;
        //Input validation. Check if user inputs number, if not, tell them to enter number and restart loop
        if (cin.fail()) //.fail returns true if the data type of the input doesn't match the variable's data type
        {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear(); //Clears fail flag
            cin.ignore(); //Need cin.ignore to clear input buffer, otherwise cin will continue to read the invalid input forever
            continue;
            
        }
        else //Creates a running total by adding valid input to total
        {
            total += nums;
            cout << "The running total is: " << total << endl;
            //Add numbers to a text file
            outFile << nums << ", ";
            count += 1;
        }
    }
    //Close file
    outFile.close();
    //Formatting and output    
    cout << "------------------------" << endl;
    //Open file, loop through each item in the file and print
    ifstream inFile("numbers.txt");
    string lines;
    //Getline retrieves the contents of the file and stores it in the 'lines' variable
    while (getline(inFile, lines))
        {
            cout << "You entered these numbers: " << lines << endl;
        }
    inFile.close();
    cout << "The final total is: " << total << endl;

return 0;
}