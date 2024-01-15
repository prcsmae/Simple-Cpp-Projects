/*Basic calculator*/

#include <iostream>
using namespace std;

int addition(int firstNum, int secondNum);
int subtraction(int firstNum, int secondNum);
int multiplication(int firstNum, int secondNum);
int division(int firstNum, int secondNum);
void userInput(int &firstNum, int &secondNum);

int main() {
  cout << "This program is a basic calculator capable of addition, subtraction, multiplication, and division of two numbers.\n";
  int choice, firstNum, secondNum, choice1;
  while(1){
    cout << "[1] Addition\n[2] Subtraction\n[3] Multiplication\n[4] Division\n[5] Exit program\n";
    cout << "Choice: ";
    cin >> choice;
    switch(choice){
      case 1:
        userInput(firstNum, secondNum);
        cout << "The result is: " << addition(firstNum, secondNum);
        break;
      case 2:
        userInput(firstNum, secondNum);
        cout << "The result is: " << subtraction(firstNum, secondNum);
        break;
      case 3:
        userInput(firstNum, secondNum);
        cout << "The result is: " << multiplication(firstNum, secondNum);
        break;
      case 4:
        userInput(firstNum, secondNum);
        cout << "The result is: " << division(firstNum, secondNum);
        break;
      case 5:
        cout << "Exiting program...";
        return 0;
      default:
        cout << "Input invalid.";
        return 0;
    }
    cout << "\nDo you wish to use the calculator again?\n[1] Yes\n[2] No\nChoice: ";
    cin >> choice1;
    switch (choice1){
      case 1:
        continue;
      case 2:
        cout << "Exiting program...";
        return 0;
    }
    break;
  }
}

void userInput(int &firstNum, int &secondNum){
  cout << "Enter first number: ";
  cin >> firstNum;
  cout << "Enter second number: ";
  cin >> secondNum;
}

int addition(int firstNum, int secondNum){
  return firstNum + secondNum;
}

int subtraction(int firstNum, int secondNum){
  return firstNum - secondNum;
}

int multiplication(int firstNum, int secondNum){
  return firstNum * secondNum;
}

int division(int firstNum, int secondNum){
  return firstNum / secondNum;
}