#include<iostream>
#include<iomanip>
#include<cstring>
#include"string.h"
using namespace std;
String::String(const char *a)
{
    str=new char[strlen(a)+1];
    strcpy(str,a);
    cout<<"Constructing an object of String \""<<str<<"\"."<<endl;
}
String::String(const String &a)
{
    str=new char[strlen(a.str)+1];
    strcpy(str,a.str);
    cout<<"Copy constructing an object of String \""<<str<<"\"."<<endl;
}
String::~String()
{
    cout<<"Destructing an object of String \""<<str<<"\"."<<endl;
    if(str)
        delete [] str;
}
String & String::operator=(const String &a)
{
    cout<<"Assign an object of String \""<<a.str<<"\"."<<endl;
    if(&a!=this)
    {
        if(str)
            delete [] str;
        str=new char[strlen(a.str)+1];
        strcpy(str,a.str);
    }
    return *this;
}
void String::show()const
{
    cout<<str<<endl;
}
void String::UpperString()
{
    cout<<"Upper \""<<str<<"\"->\"";
    strupr(str);
    cout<<str<<"\"."<<endl;
}
int String::Find_First_Not_Of(const char &a,const char &b)
{
    for(int i=0;i<strlen(this.str);i++)
    {
        if(this.str[i]>a||this.str[i]<b)
            break;
    }
    return i;
}
String operator+(const String &a,const String &b)
{
    String temp;
    temp.str=new char[strlen(a.str)+strlen(b.str)+1];
    strcpy(temp.str,a.str);
    strcat(temp.str,b.str);
    return temp;
}
String operator*(const int &a,const String &b)
{
    String temp;
    int i=0;
    temp.str=new char[a*strlen(b.str)+1];
    strcpy(temp.str,b.str);
    for(i=1;i<=a;i++)
        strcat(temp.str,b.str);
    return temp;
}
void toUpperCase(String &input)
{
    input.UpperString();
}
String getRandomWord()
{
    // TODO fetch random word from API (e.g. WordsAPI)
    return "ready";
}
bool isValid(String word)
{
    // TODO check word correctness from API (e.g. WordsAPI)
    return strlen(word.str) == WORD_LENGTH && word.Find_First_Not_Of('A','Z') == strlen(word.str);
}
void printWordle(vector<string> tries, vector<vector<int>> matches, int currentTry)
{
    system("cls");

    cout << "=================================================================" << endl;
    cout << "|                                                               |" << endl;
    cout << "|   $$\\      $$\\                           $$\\ $$\\   |" << endl;
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
        String separator = "-";
        String padding = "|";
        String text = "|";

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
