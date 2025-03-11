// -Create a program that calculates student grades using functions. This assignment will help you practice function creation,
// parameter passing, and return values.
// -Ask the user to input:
// -The number of assignments to be entered to find the course average
// -The numeric grade for each of the assignments
// -As a suggestion the program should include the following functions:
// -‘getscore’ – executed the number of times to correspond to the number of assignments input by the user to find the course average.
// -‘calcaverage’ – calculates the average of the student scores entered.
// -‘getletter’ – determines the letter grade associated with the calculated averaged according to the table below:
// -A: 100-90, B: 89-80, C: 79-70, D: 69-60, F: 59-0
// -‘displayresult’ – display result in nicely presented and formatted output.           
// -Be sure to verify that assignment scores are valid entries, i.e. 100 – 0
// -Be sure to verify that the number of requested assignment scores were entered.  EX: If user input 5 assignments to be entered, verify 5 valid numeric entries were made.

//Josh Crowe- 3/11/2025
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Function to have user input scores
float getScore()
{
    float scores;
    cout << "Please enter the score(s): " << endl;
    //Loop to validate user input
    while (!(cin >> scores))
        {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear(); //Clears fail flag
            cin.ignore(); //Need cin.ignore to clear input buffer, otherwise cin will continue to read the invalid input forever
        }
    return scores;
}
//Function to get the sum of all scores. Receives file as argument.
float getSum()
{
    ifstream inFile("scores.txt");

    float total;
    string lines;
    //Getline retrieves the contents of the file and stores it in the 'lines' variable
    while(getline(inFile, lines))
    {
        //stof takes lines, which is a string variable used to store the contents of the file, and converts to float
        total = total + stof(lines);
    }
    inFile.close();
      
    return total;
}
//Function to calculate average. Requires a sum and the amount of numbers (count)
float calcAverage(float sum, int count)
{
    float avg = sum/count;
    return avg;
}
//Receives an average and returns a letter grade based on that 
char getLetter(float avg)
{
    char letter = ' ';
    if (avg >= 90)
    {
        letter = 'A';
        return letter;
    }
    else if (avg <= 89 && avg >= 80)
    {
        letter = 'B';
        return letter;
    }
    else if (avg <= 79 && avg >= 70)
    {
        letter = 'C';
        return letter;
    }
    else if (avg <= 69 && avg >= 60)
    {
        letter = 'D';
        return letter;
    }
    else
    {
        letter = 'F';
        return letter;
    }   
}

int displayResults(float sum, float avg, char letter)
{
    cout << "The sum of the score(s) is: " << sum << endl;
    cout << "The average score is: " << avg << endl;
    cout << "The letter grade based on this average is: " << letter << endl;
    return 0;
}
 
//All functions called in main
int main()
{
    int amtScores;
    cout << "How many scores would you like to enter?" << endl;
    //Ask for the number of scores to enter until user enters valid input
    while(!(cin >> amtScores))
    {
        cout << "Invalid input. Please enter how many scores you would like to input." << endl;
        cin.clear(); 
        cin.ignore(); 
    }    
    //Create file to later write scores to
    ofstream outFile("scores.txt");
    //Loop to call the getScore function the amount of times based on above user input
    //Loops until i = amtScores
    for (int i=0; i != amtScores; i++)
    {
        //Values returned by getScore are appended to the file
        outFile << getScore() << endl;
    }
    //Close file after for loop writes all numbers to file
    outFile.close();

    /*
    Calling all functions and assigning their return values to variables as needed:
    ---------------------------------------------------------------------------------
    */

    //Assign the results of getSum to sum variable
    float sum = getSum();
    //Call calcAverage, passing results of getSum and amtScores, assign to variable
    float average = calcAverage(sum, amtScores);
    char letterGrade = getLetter(average);
    displayResults(sum, average, letterGrade);
    
    return 0;
}