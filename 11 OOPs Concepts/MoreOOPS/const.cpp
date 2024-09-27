#include<iostream>
using namespace std;

int main()
{
    // const int x=5; //x is constant
    // //intialization can be done
    // //but we cant reassign it
    // // x=10;
    // cout<<x<<endl;

    // //2. const with pointers
    // // const int *a=new int(2);//const data non const pointer
    // int const *a=new int (2);
    // cout<<*a<<endl;
    // // *a=20;
    // // cout<<*a<<endl;
    // int b= 20;
    // a=&b;
    // cout<<*a<<endl;

    // //3.const pointer.but non const data
    int * const a= new int (2);
    cout<<*a<<endl;
    *a=20; //cal jayega
    cout<<*a<<endl;
    // // int b=50;
    // // a=&b;//nahi chalega const pointer

    // //4.const pointer const data
    // const int * const a =new int(10);
    // cout<<*a<<endl;
    // *a=50;
    // int b=100;
    // a=&b;//does not run blc const data and pointer
    return 0;
}
