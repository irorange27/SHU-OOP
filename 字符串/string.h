#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
class String
{
public:
    String(const char *);
    String(const String &);
    virtual ~String();
    String & operator=(const String &);
    void show()const;
    void UpperString();
    String operator+(const String &,const String &);
    String operator*(const int &,const String &);
private:
    char *str;
};


#endif // STRING_H_INCLUDED
