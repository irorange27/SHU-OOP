#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
class Vector
{
public:
    Vector(int a=1);
    Vector(const Vector &);
    Vector & operator=(const Vector &);
    virtual ~Vector();
    void show() const;
    friend double InMultiply(const Vector &,const Vector &);
private:
    double *vec;
    int n;
};


#endif // VECTOR_H_INCLUDED
