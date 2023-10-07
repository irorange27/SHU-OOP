#include <iostream>
#include <vector>
#include "string.h"
#include <algorithm>
#include <cctype>
#include <Windows.h>
using namespace std;
const int WORD_LENGTH = 5;
const int NOT_MATCH = 0;
const int PARTIAL_MATCH = 1;
const int MATCH = 2;

void markMatch(vector<vector<int>> &matches, int tryIndex, string target, string guess)
{
    for (int i = 0; i < guess.length(); i++)
    {
        matches[tryIndex][i] = NOT_MATCH;
    }

    for (int j = 0; j < guess.length(); j++)
    {
        for (int i = 0; i < target.length(); i++)
        {
            if (guess[j] == target[i])
            {
                if (i == j)
                {
                    matches[tryIndex][j] = MATCH;
                    break;
                }
                else
                {
                    matches[tryIndex][j] = PARTIAL_MATCH;
                }
            }
        }
    }
}

bool isAllMatch(String target,String guess)
{
    for (int i = 0; i < strlen(guess.str); i++)
    {
        if (guess[i] != target[i])
            return false;
    }

    return true;
}


int main()
{
    int numberOfTries = 6;

    vector<string> tries(numberOfTries);
    vector<vector<int>> matches(numberOfTries, vector<int>(WORD_LENGTH));
    String targetWord = getRandomWord();

    toUpperCase(targetWord);

    String input;

    int currentTry = 0;

    printWordle(tries, matches, -1);

    while (currentTry < numberOfTries)
    {
        do
        {
            cout << "Please enter your guess (word length must be " + to_string(WORD_LENGTH) + ") or type Q to quit: ";
            getline(cin, input);
            toUpperCase(input);

        } while (input != "Q" && !isValid(input));

        if (input == "Q")
        {
            cout << "Quit game" << endl;
            break;
        }

        tries[currentTry] = input;

        markMatch(matches, currentTry, targetWord, input);

        printWordle(tries, matches, currentTry);

        if (isAllMatch(targetWord, input))
        {
            cout << "Found the word" << endl;
            break;
        }
        else if (currentTry == numberOfTries)
        {
            cout << "You didn't find the word" << endl;
        }

        currentTry++;
    }

    return 0;
}
