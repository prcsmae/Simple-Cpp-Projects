/*Program to play rock paper scissors between two players*/

#include <iostream>
#include <stdlib.h>
#include <random> // for the random number generator
#include <cctype> // for tolower
#include <algorithm> // for transform

using namespace std;

char toLower(char c);
void Clear() { cout << "\x1B[2J\x1B[H"; }
int coinToss (string choice1);
int correctInput(string gameChoice, string input[3]);

int main() {
    Clear();
    cout << "This program lets you play rock paper scissors between two players.\n";
    cout << "Choose a side of the coin to determine which player plays first.\n\n";
    
    // Declaration of strings
    string choice1, choice2, gameChoice1, gameChoice2, input[3] = {"heads", "tails"};

    // do-while loop that asks for player 1's side of the coin and handles errors
    do{
        cout << "Player 1 choice (Heads or Tails): ";
        cin >> choice1;
    } while(correctInput(choice1, input));

    // calls the coinToss function and assigns the return value to the turn variable, also declares the score variables
    int turn = coinToss(choice1), score1 = 0, score2 = 0;

    // re-assigning new values to the input array to be used in handling errors for the correctInput function
    input[0] = "rock";
    input[1] = "paper";
    input[2] = "scissors";

    cout << "\n\n---------------------------------------------";
    cout << "\n\tGame will now start.\n";
    cout << "---------------------------------------------\n";

    // Game formal
    for (int rounds = 0; rounds <3 ; rounds ++){
        // switch loop that asks for their choice (rock, paper, or scissors)
        switch (turn){
            case 1:
                do{
                    cout << "\nPlayer 1 choice (rock, paper, or scissors): ";
                    cin >> gameChoice1;
                    transform(gameChoice1.begin(), gameChoice1.end(), gameChoice1.begin(), toLower); 
                } while(correctInput(gameChoice1, input));

                do{
                    cout << "\nPlayer 2 choice (rock, paper, or scissors): ";
                    cin >> gameChoice2;
                    transform(gameChoice2.begin(), gameChoice2.end(), gameChoice2.begin(), toLower);
                } while (correctInput(gameChoice2, input));

                break;
            case 2:
                do{
                    cout << "\nPlayer 2 choice (rock, paper, or scissors): ";
                    cin >> gameChoice2;
                    transform(gameChoice2.begin(), gameChoice2.end(), gameChoice2.begin(), toLower);
                } while (correctInput(gameChoice2, input));
            
                do{
                    cout << "\nPlayer 1 choice (rock, paper, or scissors): ";
                    cin >> gameChoice1;
                    transform(gameChoice1.begin(), gameChoice1.end(), gameChoice1.begin(), toLower); 
                } while(correctInput(gameChoice1, input));
                
                break;
        }

        // code snippet that determines who won in the round
        if (gameChoice1 == gameChoice2){
            cout << "It's a tie!\n";
            rounds--;
        } else if (gameChoice1 == "rock" && gameChoice2 == "scissors" || gameChoice1 == "paper" && gameChoice2 == "rock" ||
                    gameChoice1 == "scissors" && gameChoice2 == "paper"){
                        score1++;
                        cout << "\nPlayer 1 wins!\n";
                        cout << "\nCurrent score: \nPlayer 1: " << score1 << "\nPlayer 2: " << score2 << endl;
                        turn = 2;
                    }
        else{
            cout << "\nPlayer 2 wins!\n";
            score2++;
            cout << "\nCurrent score: \nPlayer 1: " << score1 << "\nPlayer 2: " << score2 << endl;
            turn = 1;
        }
    }

    // code snippet that displays the ultimate winner
    if (score1 > score2){
        cout << "\n\nPlayer 1 is the ultimate winner! Try again next time player 2.";
    } else if (score2 > score1){
        cout << "\n\nPlayer 2 is the ultimate winner! Try again next time player 1.";
    }
}

// function to convert input string to lowercase to be able to compare them
char toLower(char c) {
    // static_cast<unsigned char> is used to convert c to an unsigned char data type.
    /* unsigned char ensures that the value of c is treated as an unsigned character
    (to handle the possibility of negative char values correctly) before being passed to tolower.*/
    return tolower(static_cast<unsigned char>(c));
}

// function to determine which player goes first
int coinToss (string choice1){
    string choice2;
    // Transforms the input string in the case the user inputs uppercase
    transform(choice1.begin(), choice1.end(), choice1.begin(), toLower); 

    if (choice1 == "heads"){
        cout << "\nPlayer 2's choice will now be automatically tails.\n";
        choice2 = "tails";
    } else if (choice1 == "tails"){
        cout << "\nPlayer 2's choice will now be automatically heads.\n";
        choice2 = "heads";
    }

    // Creates an object rd of the class random_device
    random_device rd;

    // Create a random number engine using the random_device
    default_random_engine engine(rd());

    // Create a distribution for the range of random numbers you want
    uniform_int_distribution<int> distribution(1, 2);

    // Generate a random number
    int coinRand = distribution(engine);

    int turn;

    switch (coinRand){
        case 1:
            cout << "\nHeads wins.";
            if (choice1 == "heads"){
                cout << "\nPlayer 1 will go first.";
                turn = 1;
            } else if (choice2 == "heads"){
                cout << "\nPlayer 2 will go first.";
                turn = 2;
            }
            break;
        case 2:
            cout << "\nTails wins.";
            if (choice1 == "tails"){
                cout << "\nPlayer 1 will go first.";
                turn = 1;
            } else if (choice2 == "tails"){
                cout << "\nPlayer 2 will go first.";
                turn = 2;
            }
            break;
    }
    return turn;
}

// function that determines whether the input is correct based on the values in the input array
int correctInput(string gameChoice, string input[3]){
    if (!(gameChoice == input[0] || gameChoice == input[1] || gameChoice == input [2])){
        cout << "\nInput incorrect. Try again.\n";
        return 1;
    }
    else {
        return 0;
    }
}