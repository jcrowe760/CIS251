//Program that emulates a slot machine at a casino
//THE Group 2: Josh Crowe, Kaleb Hankerson, Logan Carlson
#include <iostream>
#include <cctype>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

//Function to generate a random symbol
//Selects a random item from a vector of symbols
char spin()
{
    vector <char> symbols = {'A', 'B', 'C', 'D'};
    return symbols[rand() % symbols.size()];
}
//Displays the results of the spin
void display(char s1, char s2, char s3, char s4, char s5, char s6, char s7, char s8, char s9)
{
    cout << "-----------------" << endl;
    cout << "| " << s1 << " | " << s2 << " | " << s3 << " |" << endl;
    cout << "-----------------" << endl;
    cout << "| " << s4 << " | " << s5 << " | " << s6 << " |" << endl;
    cout << "-----------------" << endl;
    cout << "| " << s7 << " | " << s8 << " | " << s9 << " |" << endl;
    cout << "-----------------" << endl;
}
//Function to check for a win
bool checkWin(char s1, char s2, char s3, char s4, char s5, char s6, char s7, char s8, char s9)
{
    //A win is returned if any of these conditions are met:
    //symbols match across each row, or along a diagonal
    return (s1 == s2 && s2 == s3 || s4 == s5 && s5 == s6 || s7 == s8 && s8 == s9 || s1 == s5 && s5 == s9 || s7 == s5 && s5 ==s3);
}
//Main function
int main()
{
    srand(time(0)); //Seed for the random number generator
    char symbol1, symbol2, symbol3, symbol4, symbol5, symbol6, symbol7, symbol8, symbol9;
    int balance;
    int bet;
    cout << "Enter your balance: " << endl;
    //Input validation loop- asks for balance until user enters a number that is greater than 0
    while(!(cin >> balance) || balance <= 0)
    {
        cout << "Invalid input, please enter a number greater than zero. " << endl;
        cin.clear();
        cin.ignore();
    }
    cout << "Your balance is $" << balance << endl;
    //Main loop. Runs until user balance is 0, or until user enters 0 or a non-numeric character as their bet
    while (balance > 0)
    {
        cout << "Enter the amount you would like to bet: (Enter 0 or a non-numeric character to quit)" << endl;
        cin >> bet;
        //Need to add input validation for this part
        if (bet == 0) {
            break; //Break if user enters 0 as their bet
        }
        else if (bet > balance) {
            cout << "Error. You cannot bet an amount greater than your current balance." << endl;
            continue; //Reset loop
        }
        else if (bet < 0) {
            cout << "Error. You cannot bet a negative amount." << endl;
            continue;
        }
        //Subtract bet from balance
        balance -= bet;
        //Spin the slot machine by calling spin function and assigning results to each symbol variable
        symbol1 = spin();
        symbol2 = spin();
        symbol3 = spin();
        symbol4 = spin();
        symbol5 = spin();
        symbol6 = spin();
        symbol7 = spin();
        symbol8 = spin();
        symbol9 = spin();
        //Passing the results to the display function
        display(symbol1, symbol2, symbol3, symbol4, symbol5, symbol6, symbol7, symbol8, symbol9);
        //Check for a win- if checkWin, returns true, bet*2.5 is added to the balance
        if (checkWin(symbol1, symbol2, symbol3, symbol4, symbol5, symbol6, symbol7, symbol8, symbol9))
        {
            cout << "Congratulations, you won " << bet*2.5 << " dollars!" << endl;
            balance += bet*2.5;
        }
        else {
            cout << "Try again!" << endl;
            cout << "Current balance: $" << balance << endl;
        }
    }

    cout << "Thanks for playing! Final balance: $" << balance << endl;
    return 0;
}