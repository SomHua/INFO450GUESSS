# INFO450GUESSS

Functional Requirements:
Write a Program that builds an 8x8 board game with 5 pieces of hidden gold and 1 hidden BOMB.

The user gets 5 chances (guesses) to find the gold,  earning a point for each found Gold	

After each guess, the user is informed if they found Gold or not and how many guesses they have left.	

If the user finds the BOMB before finding all the gold, the game is over. LOSER! No more guesses.	

The game starts with presenting a game board with the contents hidden	

The game allows the user to guess 5 times, by entering an x-coordinate and an y-coordinate for each guess

At the end of the game, 
The player is presented with the number of Points earned  (gold that was found)

The player is presented with the game board with the Contents showing  “G” = Gold,  “F” =  found Gold  “B” = bomb

The player is asked if they want to play again.

If the player selects to play again, games starts over by presenting the hidden board.

The game will repeat for as long as the player wants to play

Each piece of gold found rewards a user with an extra guess




Non-Functional Requirements:
The game must use a 2-D array as the Game Board.
The program must use at least 2 functions for the game (can be more!)
To initialize the game board with Gold and Bomb.
To present the game board to the user.
The board 2-D array should be declared in the main() function and passed to the initialize and show functions.
The program should use const variables for the game board size.
The game should use the rand() function to randomly set the gold and bomb at different x,y positions in the array for each game played  (Note:  srand( time(NULL));  can be used to seed the rand function);
The user should be allowed to continue to play games until they decide to quit.
