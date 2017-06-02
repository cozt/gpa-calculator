// This program is designed to calculate the future GPA needed to
// raise a student's current GPA to a certain level
// Created by Ian Annase
// Last modified December 5, 2016
// Copy and paste it to http://cpp.sh/ to run it

#include <iostream>
#include <iomanip>
using namespace std;

// function declarations
void Menu();

// main
int main()
{
    // variables
    double currentGPA, totalGPA;
    double currentCredits, completedCredits, totalCredits, majorCredits;
    double increment, achievement;
    int choice;
    
    // user input
    cout << "C++ GPA Calculator" << endl << endl;

    // display the menu loop
    do
    {
        Menu();
        cout << endl << "Enter your choice (1-5): ";
        cin >> choice;
   
        // determine choice
        switch (choice)
        {
            case 1:
                // semester chart
                cout << "What is your current cumulative GPA? ";
                cin >> currentGPA;
                cout << "How many credits have you completed? ";
                cin >> completedCredits;
                cout << "How many credits are you taking this semester? ";
                cin >> currentCredits;
                cout << "Increment (i.e 0.5 will display 2.0, 2.5, 3.0.....): ";
                cin >> increment;
                
                cout << endl << endl;
                cout << "+---------------+---------------+" << endl;
                cout << "|  Total GPA    | Semester GPA  |" << endl;
                cout << "+---------------+---------------+" << endl;
                
                totalCredits = currentCredits + completedCredits;
                
                for (double x = 2.0; x <= 4.001; x += increment)
                {
                    cout << fixed << showpoint << setprecision(2);
                    totalGPA = (currentGPA * completedCredits + currentCredits * x) / totalCredits;
                    cout << "|     " << totalGPA << "      |      " << x << "     |"<< endl;
                }
                
                cout << "+---------------+---------------+" << endl;
                cout << endl << endl;
                break;
                
            case 2:
                cout << "What is your current cumulative GPA? ";
                cin >> currentGPA;
                cout << "How many credits have you completed? ";
                cin >> completedCredits;
                cout << "How many credits for your major (usually 120)? ";
                cin >> majorCredits;
                cout << "Increment (i.e 0.5 will display 2.0, 2.5, 3.0.....): ";
                cin >> increment;
                
                // graduation chart
                cout << endl << endl;
                cout << "+---------------+---------------+" << endl;
                cout << "|  Final GPA    |  GPA Needed   |" << endl;
                cout << "+---------------+---------------+" << endl;
                
                majorCredits -= completedCredits;
                totalCredits = majorCredits + completedCredits;
                
                for (double x = 2.0; x <= 4.001; x+=increment)
                {
                    cout << fixed << showpoint << setprecision(2);
                    totalGPA = (currentGPA * completedCredits + majorCredits * x) / totalCredits;
                    cout << "|     " << totalGPA << "      |      " << x << "     |"<< endl;
                }
                
                cout << "+---------------+---------------+" << endl;
                cout << endl << endl;
                break;
                
            case 3:
                // total gpa
                cout << "What is your current cumulative GPA? ";
                cin >> currentGPA;
                cout << "How many credits have you completed? ";
                cin >> completedCredits;
                cout << "How many credits are you taking this semester? ";
                cin >> currentCredits;
                cout << "Total GPA you want to achieve: ";
                cin >> achievement;
                cout << endl;
                
                totalCredits = currentCredits + completedCredits;
                
                for (double x = 2.0; x <= 10; x += 0.001)
                {
                    totalGPA = (currentGPA * completedCredits + currentCredits * x) / totalCredits;
                    if (totalGPA >= achievement)
                    {
                        cout << fixed << showpoint << setprecision(3);
                        cout << "You need a GPA of " << x << " to achieve a " << achievement << " this semester.";
                        break;
                    }
                }
                
                cout << endl << endl;
                break;
                
            case 4:
                // final gpa
                cout << "What is your current cumulative GPA? ";
                cin >> currentGPA;
                cout << "How many credits have you completed? ";
                cin >> completedCredits;
                cout << "How many credits for your major (usually 120)? ";
                cin >> majorCredits;
                cout << "Final GPA you want to achieve: ";
                cin >> achievement;
                cout << endl;
                
                majorCredits -= completedCredits;
                totalCredits = majorCredits + completedCredits;
                
                for (double x = 2.0; x <= 10; x += 0.001)
                {
                    totalGPA = (currentGPA * completedCredits + majorCredits * x) / totalCredits;
                    
                    if (totalGPA >= achievement)
                    {
                        cout << fixed << showpoint << setprecision(3);
                        cout << "You need a GPA of " << x << " to achieve a " << achievement << " this semester.";
                        break;
                    }
                }
                
                cout << endl << endl;
                break;
                
            case 5:
                cout << "Goodbye!";
                break;
        }
    }
    while (choice != 5);
    return 0;
}

// menu
void Menu()
{
    cout << "1 - Chart of GPAs to maintain for this semester" << endl;
    cout << "2 - Chart of GPAs to maintain for graduation" << endl;
    cout << "3 - Enter a total GPA you want to achieve this semester" << endl;
    cout << "4 - Enter a final GPA you want to achieve by the end of college" << endl;
    cout << "5 - Exit" << endl;
}

