#include <iostream>
using namespace std;

bool guessTheWord (string correct) {
    cout << "Guess the word!";
    string guess;
    cin >> guess;
    
    if (guess == correct) {
        cout << "That's it!";
    }
    else {
        guessTheWord(correct);
    }
    
    return true;
}

int main()
{
    string correct_word = "blah";
    guessTheWord( correct_word );
    return 1;
}

