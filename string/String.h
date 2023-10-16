#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include <vector>

class String
{
public:
    String(const char *a="");
    String(const String &);
    virtual ~String();
    String & operator=(const String &);
    void show()const;
    void UpperString();
    int Find_First_Not_Of(const char &,const char &)const;
    friend String operator+(const String &,const String &);
    friend String operator*(const int &,const String &);
private:
    char *str;
};
void toUpperCase(String &);
String getRandomWord();
bool isValid(String word);
void printWordle(vector<string> tries, vector<vector<int>> matches, int currentTry);


#endif // STRING_H_INCLUDED
