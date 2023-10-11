#ifndef WORDLE_H_INCLUDED
#define WORDLE_H_INCLUDED

#include <vector>
using namespace std;

class MyString
{
public:
    MyString(const char *s="");
    MyString(const MyString &);
    virtual ~MyString();
    MyString & operator=(const MyString &);
    void Uppername();
    void getRandomWord();
    bool isValid();
    friend bool isAllMatch(MyString ,MyString );
    friend void markMatch(vector<vector<int> > &, int , MyString , MyString );
    friend bool operator==(MyString , MyString );
    friend bool operator!=(MyString , MyString );
    string getString()const;
    friend istream & operator>>(istream &, MyString &);
private:
    char *str;
};
void printWordle(vector<string> , vector<vector<int> > , int );
#endif