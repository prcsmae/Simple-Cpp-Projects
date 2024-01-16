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

int main() {
    Clear();
    cout << "This program lets you play rock paper scissors between two players.\n";
    cout << "Choose a side of the coin to determine which player plays first.\n\n";
    
    string choice1, choice2, gameChoice1, gameChoice2;
     cout << "Player 1 choice (Heads or Tails): ";
    cin >> choice1;
    int turn = coinToss(choice1), score1 = 0, score2 = 0;

    cout << "\n\n---------------------------------------------";
    cout << "\n\tGame will now start.\n";
    cout << "---------------------------------------------\n";

    for (int rounds = 0; rounds <3 ; rounds ++){
        switch (turn){
            case 1:
                cout << "\nPlayer 1 choice (rock, paper, or scissors): ";
                cin >> gameChoice1;
                transform(gameChoice1.begin(), gameChoice1.end(), gameChoice1.begin(), toLower); 

                cout << "\nPlayer 2 choice (rock, paper, or scissors): ";
                cin >> gameChoice2;
                transform(gameChoice2.begin(), gameChoice2.end(), gameChoice2.begin(), toLower);

                break;
            case 2:
                cout << "\nPlayer 2 choice (rock, paper, or scissors): ";
                cin >> gameChoice2;
                transform(gameChoice2.begin(), gameChoice2.end(), gameChoice2.begin(), toLower);

                cout << "\nPlayer 1 choice (rock, paper, or scissors): ";
                cin >> gameChoice1;
                transform(gameChoice1.begin(), gameChoice1.end(), gameChoice1.begin(), toLower); 

                break;
        }

        if (gameChoice1 == gameChoice2){
            cout << "It's a tie!\n";
            rounds--;
        } else if (gameChoice1 == "rock" && gameChoice2 == "scissors" || gameChoice1 == "paper" && gameChoice2 == "rock" ||
                    gameChoice1 == "scissors" && gameChoice2 == "paper"){
                        score1++;
                        cout << "\nPlayer 1 wins!\n";
                        cout << "\nCurrent score: \nPlayer 1: " << score1 << "\nPlayer 2: " << score2;
                        turn = 2;
                    }
        else{
            cout << "\nPlayer 2 wins!\n";
            score2++;
            cout << "\nCurrent score: \nPlayer 1: " << score1 << "\nPlayer 2: " << score2;
            turn = 1;
        }
    }
    if (score1 > score2){
        cout << "\n\nPlayer 1 is the ultimate winner! Try again next time player 2.";
    } else if (score2 > score1){
        cout << "\n\nPlayer 2 is the ultimate winner! Try again next time player 1.";
    }
}

char toLower(char c) {
    // static_cast<unsigned char> is used to convert c to an unsigned char data type.
    /* unsigned char ensures that the value of c is treated as an unsigned character
    (to handle the possibility of negative char values correctly) before being passed to tolower.*/
    return tolower(static_cast<unsigned char>(c));
}

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