#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() 
{
    srand(time(0)); //seed the random number generator with the current time
    int secretNumber = rand() % 100 + 1; // generate a random number between 1 and 100
    int guess = 0; // initialize the guess variable to 0

    while (guess != secretNumber) {
        cout << "Guess the secret number (between 1 and 100): ";
        cin >> guess;

        if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the secret number." << endl;
        }
    }

    return 0;
}
