#include<iostream>
using namespace std;
class abc {
    int x;
    int *y;
    const int z;

    public:
    // //ctor=old style
    // abc(int _x,int _y ,int _z){
    //     x=_x;
    //     y=new int (_y);
    //     z=_z;
    // }
    //initialization list
    abc(int _x,int _y,int _z=0):x(_x),y(new int(_y)),z(_z) {}
    int getx() const 
    {
        return x;
    }
    void setx(int _val) {
        x = _val;
    }
    int gety() const {
        return *y;
    }
    void sety(int _val) {
        *y=_val;
    }
    int get2() const {
        return 2;
    }
};

void printABC(const abc &a){
    cout<<a.getx()<<" "<<a.gety()<<" "<<a.get2()<<endl;

}
int main(){
    abc a(1,2,3);
    printABC(a);
    return 0;
}