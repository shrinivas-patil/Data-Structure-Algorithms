// //friend class 
// #include<iostream>
// using namespace std;
//  class A {
//     private:
//     int x;

//     public:
//     A(int _val):x(_val) {}

//     int getx() const {
//         return x;
//     }
//     void setx(int _val) {
//         x=_val;
//     }

//     friend class B;
//     friend void print(const A&B);
//  };
//  class B
//  {
//     public:
//     void print(const A&a) {
//         //cout<<a.getx()<<endl;
//         cout<<a.x<<endl;
//     }
//  };
//  void print(const A&a) {
//     cout<<a.x<<endl;
//  }
//  int main() {
//     A a(5);
//     B b;
//     b.print(a);
//     print(a);
//     return 0;
//  }

// without friend we can send the values

#include<iostream>
using namespace std;
 class A {
    private:
    int x;

    public:
    A(int _val):x(_val) {}

    int getx() const {
        return x;
    }
    void setx(int _val) {
        x=_val;
    }
    void print() const {
        cout<<x<<endl;
    }
 };
 class B
 {
    public:
    void print(const A&a) {
        //cout<<a.getx()<<endl;
       a.print();
    }
 };

 int main() {
    A a(5);
    B b;
    b.print(a);
    return 0;
 }