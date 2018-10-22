#include <iostream>
#include <time.h> // Using time to seed
#include <iomanip>
using namespace std;
// Declaring ROWs and Columns as constant so it's easier to change the lenght of the array if needed to.
const int ROWS = 8;
const int COLUMNS = 8;

// method declaration
int initializeTable(char arrayTable[ROWS][COLUMNS]);
int displayTable(char arrayTable[ROWS][COLUMNS]);
int populateTable(char arrayTable[ROWS][COLUMNS]);
int appLogic(char arrayTable[ROWS][COLUMNS], int &points, int remainingGuesses);
int printResult (char arrayTable[ROWS][COLUMNS], int &points);


int main()
{
    char arrayTable[ROWS][COLUMNS]; // Create the 2D array
    char answer; //Main Function Loop control
    int points = 0;
    int remainingGuesses = 5; // The numbers of guesses user have left
    
    do
    {
        // Calling all the methods
        initializeTable(arrayTable);
        displayTable(arrayTable);
        populateTable(arrayTable);
        appLogic(arrayTable, points, remainingGuesses);
        printResult (arrayTable, points);
        
        // Browse to ask whether the user wants to play the game again
        cout << "Would you like to play Again? Enter 'Y' or 'y'" << endl;
        cin >> answer;
        
        // reset the remainingGuesses to 5 if user decides to play again
        if (answer == 'y' || answer == 'Y')
        {
            remainingGuesses = 5;
        }
        
    } while (answer == 'Y' || answer == 'y');
    // If user press Y or y, the Do..While loop in the main function will re-start by calling all the methods in the main function
    return 0;
    
}

// This method is used to initialize the array tables with question marks.
int initializeTable(char arrayTable[ROWS][COLUMNS])
{
    int row, column;
    
    // We need two for loops, one loop is for the rows and one is for the columns
    for (row = 0; row < ROWS; row++)
    {
        for (column = 0; column < COLUMNS; column++)
        {
            arrayTable[row][column] = '?';
        }
    }
    return 0;
}

// This method is used to print the array Table with question marks and Game rule!
int displayTable(char arrayTable[ROWS][COLUMNS])

{
    int row, column;
    cout << "   ";
    // print the column numbers
    for (column = 0; column < COLUMNS; column++)
    {
        // add two spaces between every column
        cout << "  " << column + 1 ;
        // The array lenght is always the lenght -1 because the array starts with ZERO. We add 1 so the first column can start at 1
    }
    cout << endl;
    cout << "  " << "-------------------------" << endl;
    
    for (row = 0; row < ROWS; row++)
    {
        cout << "  " << row + 1 << "|";
        // We wants the row to start at 1, and then we add the "|" for formatting purposes
        for (column = 0; column < COLUMNS; column++)
        {
            cout  << "  "<< arrayTable[row][column];
            // add two spaces between every column so the table can be neatly aligned
        }
        cout << endl;
    }
    
    cout << "  " << "--------------------------" << endl;
    // add straight dashed to the end of the table
    
    
    // Print the game rule
    cout << "**" << " ********************* " << "**" << endl;
    cout << "**" << "      Find Gold!!!     " << "**" << endl;
    cout << "**" << "  You have 5 guesses,  " << "**" << endl;
    cout << "**" << "  5 pieces of gold,    " << "**" << endl;
    cout << "**" << "     and 1 bomb        " << "**" << endl;
    cout << "**" << "  Earn 1 Xtra Point    " << "**" << endl;
    cout << "**" << "  When Find Gold!!!   " << "**" <<  endl;
    cout << "**" << "      Good Luck!       " << "**" << endl;
    cout << "**" << " ********************* " << "**" << endl;
    cout << endl;
    
    return 0;
}


// This method is used to assign bomb and GOLD to the array table
int populateTable(char arrayTable[ROWS][COLUMNS])

{
    static int nCalls = 0;
    int x, y;
    int goldCounter = 0;
    int bombCounter = 0;
    
    if(nCalls==0)
        srand(time(NULL));
    nCalls++;
    // We seed with time so that we get random numbers everytime, if we dont seed then we will get the same random everytime (Psuedo random)
    
    do {
        x = (rand() % ROWS) + 1;
        // assign a random number between 1-8 to the X cordinate
        y = (rand() % COLUMNS) + 1;
        // assign a random number between 1-8 to a Y cordinate
        
        
        // this statment is used to assign Gold to the array table. So every position in the tables will be part of the random assignment because the table has already been intilized with QUESTION MARKS
        if (arrayTable[x][y] == '?')
        {
            arrayTable[x][y] = 'G'; // Assigning G to the array
            goldCounter++; // add one to the counter everytime a Gold get assigned
        }
        
    } while (goldCounter < 5);
    // After five golds get assigned, the loop will stop
    
    
    do
    {
        x = (rand() % ROWS) + 1;
        // assign a random number between 1-8 to the X cordinate
        y = (rand() % COLUMNS) + 1;
        // assign a random number between 1-8 to a Y cordinate
        
        // This statement is used to make sure that we dont assign both B and G in the same position
        if (arrayTable[x][y] != 'g')
        {
            arrayTable[x][y] = 'B'; // Assigning B to the array
            bombCounter++; // add one to the counter everytime a Bomb get assigned
        }
        
        
    } while (bombCounter < 1);
    // the loop will stop after one BOMB get assigned
    
    
    return 0;
    
}


//
int appLogic(char arrayTable[ROWS][COLUMNS], int &points, int remainingGuesses)
{
    int row, column;
    // variables for the X and Y cordinate inputs from the user
    
    
    // Prompt the user for the X cordinate
    do
    {
        cout << "Enter an X coordinate between 1 and 8: ";
        cin >> row;
        
        // The while condition is used to control the error in case user type in the wrong datatype, the number bigger than 8 or smaller than 1. I used while loop instead of the IF statement because otherwise the error control only work ONCE.
        while ( row < 1 || row > 8)
        {
            cout << "Please enter an integer that is between 1 and 8: ";
            cin.clear();
            // Use to clear the first input that isn't integer and prevent errors
            cin.ignore();
            // use to clear the next 1000 inputs that isn't integer
            cin >> row;
        }
        row--;
        // because our array lenght starts at zero and not one, we need to subtract one from the cordinate that the user pick in order for it to match our array rows
        
        
        // This code works the same as the code above, but for COLUMN/Y cordinate
        cout << endl;
        cout << "Enter a Y coordinate between 1 and 8: ";
        cin >> column;
        
        while (column < 1 || column > 8)
        {
            cout << "Please enter an integer that is between 1 and 8: ";
            cin.clear();
            cin.ignore();
            cin >> column;
        }
        column --;
        cout << endl;
        
        
        
        if (arrayTable[row][column] == 'G')
        {
            cout << "Yeah!! You Found Gold! " << remainingGuesses << " guesses left!";
            points += 1;
            continue; // go back to the beginning of the Do...While loop
            /* also, because i didn't decrement remainingGuesses, user shouldnt lose any guess if they found the gold. adding remaining+=1 will give user an extra guess, while not taking away any guess  */
        }
        
        // If the user finds bomb, break out of loop and end game.
        else if (arrayTable[row][column] == 'B')
        {
            cout << endl;
            cout << "BOMB... GAME OVER!!!" << endl << endl;
            break;
            // If the user finds the BOMB, then the loop will break and the game will end.
        }
        // subtract one from remainingGuesses if the user finds nothing
        else
        {
            cout << "Too bad...." << endl;
            remainingGuesses--; // minus one from the guess
            cout << "You have " << remainingGuesses << " guesses left!" << endl << endl;
        }
        
    } while (remainingGuesses > 0);
    // the loop will end when remainingGuesses is zero
    
    
    return 0;
}



//This method is used to print where the G and B are on the table and the points the user have earned. I have to pass "points" by reference because otherwise we will get the number that get initized in the MAIN FUNCTION, which is zero, instead of the points the user have earned
int printResult (char arrayTable[ROWS][COLUMNS], int &points)
{
    
    int row, column; // Loop counters
    
    cout << "You've earned " << points << " points!" << endl;
    //  print the points the user has earned
    cout << "Better luck next time!" << endl;
    cout << "Here's your board:" << endl << endl;
    
    
    for (row = 0; row < ROWS; row++)
    {
        
        for (column = 0; column < COLUMNS; column++)
        {
            // Take out the question marks from the Array Table.
            if (arrayTable[row][column] == '?')
                
            {
                arrayTable[row][column]=' ';
            }
        }
    }
    cout << endl;
    cout << "   ";
    
    // print columns, one is added so column can start at one.
    for (column = 0; column < COLUMNS; column++)
    {
        cout << "  " << column + 1;
    }
    cout << endl;
    // add a dashed line after columns
    cout << "  " << "--------------------------" << endl;
    
    for (row = 0; row < ROWS; row++)
    {
        // print rows, one is added so row can start at one.
        cout << " " << row + 1 << "|";
        for (column = 0; column < COLUMNS; column++)
        {
            cout << "  " << arrayTable[row][column];
            // this cout prints where all the Gs and B are located.  conditional statement isn't needed because all the QUESTION MARKS already got taken out
        }
        cout << endl;
    }
    cout << "  " << "--------------------------" << endl;
    
    return 0;
}


