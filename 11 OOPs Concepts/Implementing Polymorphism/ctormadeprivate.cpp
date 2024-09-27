#include<iostream>
using namespace std;
class box 
{
    int width;
    //ctor
    box(int _w):width(_w) {};
    public:
    int getwidth() const {
        return width;
    }
    void setwidth(int _val){
        width=_val;
    }
    friend class boxfactory;
};
class boxfactory
{
    int count;
    public:
    box getbox(int _w){
        count++;
        return box(_w);
    }
};

int main() {
    boxfactory bfact;
    box b=bfact.getbox(5);
    cout<<b.getwidth()<<endl;
    return 0;
}