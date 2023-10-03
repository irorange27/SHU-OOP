#ifndef OOP_EX4_STRING_STRING_H
#define OOP_EX4_STRING_STRING_H

class MyString {
public:
    MyString(const char *s = "");
    MyString(const MyString &other);
    ~MyString();
    MyString &operator=(const MyString &other);

    void show() const;
    int length() const;
    const char *c_str() const;

    MyString &operator+=(const MyString &other);
    friend MyString operator+(const MyString &str1, const MyString &str2);

private:
    char *str;
};

#endif OOP_EX4_STRING_STRING_H
