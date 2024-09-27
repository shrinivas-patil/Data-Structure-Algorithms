#include<iostream>
using namespace std;

int x=2;//global variable
void fun(){
    int x=60;
    cout<<x<<endl;
    ::x=40;//changing x
    cout<<::x<<endl;//printing global variable
}
int main() {
    ::x=4;//global
    int x=20;
    //cout<<x<<endl;
    //cout<<::x<<endl;//acccesing global variable
    {
        int x=50; {
            int x=44;
            cout<<x<<endl;
        }
        cout<<x<<endl;
        cout<<::x<<endl;
    }
    //fun();
    return 0;
}