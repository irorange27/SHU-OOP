#include <iostream>
#include <cstring>
#include <vector>
#include <Windows.h>
#include "wordle.h"
#include <cctype>
using namespace std;

const int WORD_LENGTH = 5;
const int NOT_MATCH = 0;
const int PARTIAL_MATCH = 1;
const int MATCH = 2;

MyString::MyString(const char *s) // 构造函数
{
    str = new char[strlen(s) + 1];
    strcpy(str, s);
}

MyString::MyString(const MyString &pn) // 深拷贝构造
{
    str = new char[strlen(pn.str) + 1];
    strcpy(str, pn.str);
}

MyString::~MyString() // 析构
{
    if (str)
        delete[] str;
}

MyString &MyString::operator=(const MyString &pn) // 深赋值运算
{
    if (&pn != this)
    {
        delete[] str;
        str = new char[strlen(pn.str) + 1];
        strcpy(str, pn.str);
    }
    return *this;
}

istream &operator>>(istream &in, MyString &guess) // 重载输入运算符
{
    char temp[1000];
    in >> temp;
    guess = temp;
    return in;
}

void MyString::show() const //输出
{
    cout << str << endl;
}

char & MyString::operator[](const int &index)const throw(int)
{
    if (index>=strlen(str))
        throw(int)1;
    return str[index];
}

MyString & MyString::operator+=(const MyString &b) //重载+=
{
    *this =*this + b;
    return *this;
}

MyString operator+(const MyString &s1,const MyString &s2) //重载+
{
    MyString res;
    res.str = new char[strlen(s1.str) + strlen(s2.str) + 1];
    strcpy(res.str, s1.str);
    strcat(res.str, s2.str);
    return res;
}

void MyString::Uppername()
{
    strupr(str);
}

void MyString::getRandomWord()
{
    // 此处导入单词库
    strcpy(str, "ready");
}

bool MyString::isValid()
{
    int i;
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] < 'A' || str[i] > 'Z')
            break;
    }
    return strlen(str) == WORD_LENGTH && i == strlen(str);
}

bool isAllMatch(MyString target, MyString guess)
{
    for (int i = 0; i < strlen(guess.str); i++)
    {
        if (guess.str[i] != target.str[i])
            return false;
    }
    return true;
}

void markMatch(vector<vector<int>> &matches, int tryIndex, MyString target, MyString guess)
{
    for (int i = 0; i < strlen(guess.str); i++)
    {
        matches[tryIndex][i] = NOT_MATCH;
    }

    for (int j = 0; j < strlen(guess.str); j++)
    {
        for (int i = 0; i < strlen(target.str); i++)
        {
            if (guess.str[j] == target.str[i])
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

bool operator==(MyString input, MyString typeQ)
{
    return strcmp(input.str, typeQ.str) == 0;
}

bool operator!=(MyString input, MyString typeQ)
{
    return strcmp(input.str, typeQ.str) != 0;
}

string MyString::getString() const
{
    string temp;
    temp = str;
    return temp;
}

void printWordle(vector<string> tries, vector<vector<int>> matches, int currentTry)
{
    system("cls");

    cout << "=================================================================" << endl;
    cout << "|                                                               |" << endl;
    cout << "|   $$\\      $$\\                           $$\\ $$\\              |" << endl;
    cout << "|   $$ | $\\  $$ |                          $$ |$$ |             |" << endl;
    cout << "|   $$ |$$$\\ $$ | $$$$$$\\   $$$$$$\\   $$$$$$$ |$$ | $$$$$$\\     |" << endl;
    cout << "|   $$ $$ $$\\$$ |$$  __$$\\ $$  __$$\\ $$  __$$ |$$ |$$  __$$\\    |" << endl;
    cout << "|   $$$$  _$$$$ |$$ /  $$ |$$ |  \\__|$$ /  $$ |$$ |$$$$$$$$ |   |" << endl;
    cout << "|   $$$  / \\$$$ |$$ |  $$ |$$ |      $$ |  $$ |$$ |$$   ____|   |" << endl;
    cout << "|   $$  /   \\$$ |\\$$$$$$  |$$ |      \\$$$$$$$ |$$ |\\$$$$$$$\\    |" << endl;
    cout << "|   \\__/     \\__| \\______/ \\__|       \\_______|\\__| \\_______|   |" << endl;
    cout << "|                                                               |" << endl;
    cout << "=================================================================" << endl;

    for (int i = 0; i <= currentTry && i < tries.size(); i++)
    {
        string separator = "-";
        string padding = "|";
        string text = "|";

        for (int j = 0; j < tries[i].length(); j++)
        {
            separator += "------";
            padding += "     |";
            char value = toupper(tries[i][j]);
            text += "  ";

            if (matches[i][j] == PARTIAL_MATCH)
            {
                text += "\033[33m";
            }
            else if (matches[i][j] == MATCH)
            {
                text += "\033[32m";
            }

            text += value;

            if (matches[i][j] == PARTIAL_MATCH || matches[i][j] == MATCH)
            {
                text += "\033[0m";
            }

            text += "  |";
        }

        if (i == 0)
        {
            cout << separator << endl;
        }
        cout << padding << endl;
        cout << text << endl;
        cout << padding << endl;
        cout << separator << endl;
    }
}
