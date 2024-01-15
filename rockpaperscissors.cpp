/*Program to play rock paper scissors between two players*/

#include <iostream>
#include <random>
#include <cctype>
#include <algorithm>

using namespace std;

char toLower(char c);

int main() {
    cout << "This program lets you play rock paper scissors between two players.\n";
    cout << "Choose a side of the coin to determine which player plays first.\n\n";

    string choice1, choice2, gameChoice1, gameChoice2;
    cout << "Player 1 choice (Heads or Tails): ";
    cin >> choice1;
    // Transforms the input string in the case the user inputs uppercase
    transform(choice1.begin(), choice1.end(), choice1.begin(), toLower); 

    cout << "Player 2 choice (Heads or Tails): ";
    cin >> choice2;
    transform(choice2.begin(), choice2.end(), choice2.begin(), toLower); 

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




}

char toLower(char c) {
    // static_cast<unsigned char> is used to convert c to an unsigned char data type.
    /* unsigned char ensures that the value of c is treated as an unsigned character
    (to handle the possibility of negative char values correctly) before being passed to tolower.*/
    return tolower(static_cast<unsigned char>(c));
}