/*Program to play rock paper scissors between two players*/

#include <iostream>
#include <random>
#include <cctype>
#include <algorithm>

using namespace std;

char toLower(char c);

int main() {
    cout << "This program lets you play rock paper scissors between two players.\n";
    cout << "Choose a side of the coin to determine which player plays first.\n";

    string choice1, choice2;
    cout << "Player 1 choice (Heads or Tails): ";
    cin >> choice1;
    transform(choice1.begin(), choice1.end(), choice1.begin(), toLower);

    cout << "Player 2 choice (Heads or Tails): ";
    cin >> choice2;
    transform(choice2.begin(), choice2.end(), choice2.begin(), toLower);

    random_device rd;

    // Create a random number engine using the random_device
    default_random_engine engine(rd());

    // Create a distribution for the range of random numbers you want
    uniform_int_distribution<int> distribution(1, 2);

    // Generate a random number
    int coinRand = distribution(engine);

    cout << choice1 << endl << choice2;

    switch (coinRand){
        case 1:
            cout << "\nHeads wins.";
            if (choice1 == "heads"){
                cout << "\nPlayer 1 will go first.";
            } else if (choice2 == "heads"){
                cout << "Player 2 will go first.";
            }
            break;
        case 2:
            cout << "\nTails wins.";
            if (choice1 == "tails"){
                cout << "\nPlayer 1 will go first.";
            } else if (choice2 == "tails"){
                cout << "Player 2 will go first.";
            }
            break;
    }

}

char toLower(char c) {
    // static_cast<unsigned char> is used to convert c to an unsigned char data type.
    /* unsigned char ensures that the value of c is treated as an unsigned character
    (to handle the possibility of negative char values correctly) before being passed to tolower.*/
    return tolower(static_cast<unsigned char>(c));
}