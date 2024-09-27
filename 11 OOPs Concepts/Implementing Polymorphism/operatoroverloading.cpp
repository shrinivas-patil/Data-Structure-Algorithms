#include<iostream>
using namespace std;

class complex {
    public:
    int real;
    int imag;

    complex () {
        real = imag = -1;
    }
    complex(int r,int i):real(r),imag(i){};

    complex operator + (const complex&A)
    {
        //this->A instance
        complex temp;
        temp.real=this->real+A.real;
        temp.imag=this->imag+A.imag;
        return temp;
    }
    complex operator - (const complex&B)
    {
        //this->A instance
        complex temp;
        temp.real=this->real-B.real;
        temp.imag=this->imag-B.imag;
        return temp;
    }
    bool operator == (const complex &B){
        //this-> A instance
        return (this->real==B.real) && (this->imag==B.imag);
    }
    void print() {
        printf("[%d+%id]\n",this->real,this->imag);
    }
};

int main() {
    complex A(3,3);
    A.print();
    complex B(3,3);
    B.print();

    complex C = A+B;
    C.print();

    complex D = A-B;
    D.print();

    bool a = A == B;
    cout<<a<<endl;

    return 0;

}