#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
class MyString
{
public:
    MyString(const char *s="");
    MyString(const MyString &);
    virtual ~MyString();
    MyString & operator=(const MyString &);

    void show()const;

    MyString & operator+=(const MyString &);
    friend MyString operator+(const MyString &,const MyString &);
    
private:
    char *str;
};
#endif