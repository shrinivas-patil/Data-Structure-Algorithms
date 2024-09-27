#include<iostream>
using namespace std;

class base {
    public:
    base(){
        cout<<"base ctr\n";
    }
    virtual ~base(){
        cout<<"base dtor\n";
    }
};

class derived: public base {
    int *a;
    public:
    derived(){
        a=new int[1000];
        cout<<"derived ctor\n";
    }
    ~derived()
    {
        delete[]a;
        cout<<"derived dtor\n";//after virtual in line 9 it will show dtor else not
    }
};
int main(){
    base *b=new derived();
    delete b;
    return 0;
}