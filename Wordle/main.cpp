#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <Windows.h>
#include "wordle.h"
using namespace std;

const int WORD_LENGTH = 5;
const int NOT_MATCH = 0;
const int PARTIAL_MATCH = 1;
const int MATCH = 2;

int main()
{
    int numberOfTries = 6;
    int currentTry = 0;

    vector<string> tries(numberOfTries);
    vector<vector<int>> matches(numberOfTries, vector<int>(WORD_LENGTH));

    MyString targetWord("");
    MyString input;
    targetWord.getRandomWord();
    targetWord.Uppername();

    printWordle(tries, matches, -1);
    while (currentTry < numberOfTries)
    {
        do
        {
            cout << "Please enter your guess (word length must be " + to_string(WORD_LENGTH) + ") or type Q to quit: ";
            cin>>input;
            input.Uppername();

        } while (input != "Q" && !input.isValid());

        if (input == "Q")
        {
            cout << "Quit game" << endl;
            break;
        }

        tries[currentTry] = input.getString();

        markMatch(matches, currentTry, targetWord, input);
        printWordle(tries, matches, currentTry);
        if (isAllMatch(targetWord, input))
        {
            cout << "Found the word" << endl;
            break;
        }
        else if (currentTry == numberOfTries-1)
        {
            cout << "You didn't find the word" << endl;
        }
        currentTry++;
    }

    return 0;
}