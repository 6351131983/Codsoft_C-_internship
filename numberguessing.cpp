#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

int main() {
    int number, guess, attempts = 0;
    char playAgain;

    // Initialize random seed
    srand(time(0));

    do {
        // Generate a random number between 1 and 100
        number = rand() % 100 + 1;
        attempts = 0;
        
        cout << "I have chosen a number between 1 and 100." << endl;

        // Start guessing loop
        do {
            cout << "Enter your guess: ";
            cin >> guess;
            attempts++;

            if (guess > number) {
                cout << "Too high! Try again." << endl;
            } else if (guess < number) {
                cout << "Too low! Try again." << endl;
            } else {
                cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;
            }
        } while (guess != number);

        // Ask if the user wants to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while(playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!" << endl;

    return 0;
}
