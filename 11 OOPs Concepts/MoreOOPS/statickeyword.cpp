// #include<iostream>
// using namespace std;

// class abc{
//     public:
//     int x,y;
//     void print() const {
//         //this
//         cout<<this->x<<" "<<this->y<<endl;
//     }
// };
// int main(){
//     abc obj1={1,2};
//     abc obj2={4,5};
//     obj1.print();
//     obj2.print();
//     return 0;
// }

// //static data memory

// #include<iostream>
// using namespace std;

// class abc{
//     public:
//     static int x,y;
//     void print() const 
//     {
//         //this
//         cout<<x<<" "<<y<<endl;
//     }
// };
// int abc::x;
// int abc::y;

// int main(){
//     abc obj1;
//     obj1.x=1;
//     obj1.y=2;
//     obj1.print();
//     abc obj2;
//     obj2.x=10;
//     obj2.y=20;
//     obj2.print();
//     return 0;
// }

//static memory function

#include<iostream>
using namespace std;

class abc{
    public:
    int x,y;
    abc():x(0) , y(0) {}
    static void print()
    {
        //no this pointer is accesiable
        printf("I am in static %s\n",__FUNCTION__);
    }
};

int main(){
    abc obj1;
    obj1.x=1;
    obj1.y=2;
    obj1.print();
    abc obj2;
    obj2.x=10;
    obj2.y=20;
    obj2.print();
    return 0;
}