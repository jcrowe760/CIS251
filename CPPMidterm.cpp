// The program should prompt the user to enter two numbers and an operator (+, -, *, /).
// The program should perform the corresponding arithmetic operation and display the result.
// The program should handle invalid operators and division by zero.
// This means that your program should do thorough input validation.
// The program should allow the user to perform the process multiple times until they wish
// -to Exit

//3/04/2025
//Josh Crowe

#include <iostream>
using namespace std;

int main()
{
    //Initializing numbers and operator to be used contain user input
    int num1, num2;
    char operate;
    //Initialize a keepGoing variable so user can continue to repeate the process as many times as they wish
    char keepGoing = 'Y';
    //Main loop
    while(keepGoing == 'Y')
    {
        cout << "Please enter the first number: " << endl;
        //Nested while loop continues asking the user for a number until they do so
        while(!(cin >> num1))
        {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear(); //Clear fail flag
            cin.ignore(); //Clear input buffer
            continue;
        }
        //Repeating the process for the second number
        cout << "Please enter the second number: " << endl;
        while(!(cin >> num2))
        {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear(); //Clear fail flag
            cin.ignore(); //Clear input buffer
            continue;
        }
        //Once user has enter 2 valid numbers, gather the desired operation
        cout << "What operation would you like to perform with these numbers? (+, -, *, or /)" << endl;
        cin >> operate;
        //Ensure that user has inputted a valid operator. If so, continue to nested if statements
        {
            if (operate == '+' ||  operate == '-' || operate == '*' || operate == '/')
            {
                //If user enters a valid operator, continue to nested if loops
                //Decision structures to perform the desired operation based on user input
                if (operate == '+')
                {
                    cout << "You requested to add the two numbers." << endl;
                    cout << "The sum of your numbers is: " << num1+num2 << endl;
                    //If user doesn't enter 'Y', keepGoing is updated to reflect this and loop/program ends    
                    cout << "Would you like to do another calculation? (Enter 'Y' if so)" << endl;
                    cin >> keepGoing;
                } else if (operate == '-') 
                {
                    cout << "You requested to subtract the two numbers." << endl;
                    cout << "The difference between your numbers is: " << num1-num2 << endl;
                    //If user doesn't enter 'Y', keepGoing is updated to reflect this and loop/program ends    
                    cout << "Would you like to do another calculation? (Enter 'Y' if so)" << endl;
                    cin >> keepGoing;
                } else if (operate == '*')
                {
                    cout << "You requested to multiply the two numbers." << endl;
                    cout << "The product of your numbers is: " << num1*num2 << endl;
                    //If user doesn't enter 'Y', keepGoing is updated to reflect this and loop/program ends    
                    cout << "Would you like to do another calculation? (Enter 'Y' if so)" << endl;
                    cin >> keepGoing;
                } else if(operate == '/')
                {
                    //If user chooses to divide, but one of their numbers is 0, give error
                    //Was not able to get this to work^
                    //Divide by zero isn't allowed, but it doesn't print the correct error message
                    if (num2 == 0)
                    {
                        cout << "Error, cannot divide by zero" << endl;
                    }
                    else
                    {
                        cout << "You requested to divide the two numbers." << endl;
                        cout << "The quotient of your numbers is: " << num1/num2 << endl;
                        //If user doesn't enter 'Y', keepGoing is updated to reflect this and loop/program ends    
                        cout << "Would you like to do another calculation? (Enter 'Y' if so)" << endl;
                        cin >> keepGoing;
                    }                    
                }
                  
            } else
            {
                cout << "Please enter a valid operator (+, -, *, /)" << endl;
                
            }  
        }        
}    //This is where main loop ends
    return 0;
}
