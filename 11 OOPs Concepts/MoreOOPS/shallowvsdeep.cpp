// #include<iostream>

// using namespace std;

// class abc 
// {
//     public:
//     int x;
//     int *y;
//     abc(int _x,int _y) : x(_x),y(new int(_y)) {}

//     void print() const
//     {
//         printf("x:%d\nptr Y:%p\nconstent of y(*y):%d\n\n", x, y, *y);
//     }
// };

// int main() 
// {
//     abc a(1,2);
//     cout<<"print int a\n";
//     a.print();
//     //abc b(a);
//     abc b=a;
//     cout<<"print b\n";
//     b.print();
//     *b.y=20;
//     cout<<"print int b\n";
//     b.print();
//     cout<<"print int a\n";
//     a.print();
//     return 0;
// }

// #include<iostream>

// using namespace std;

// class abc 
// {
//     public:
//     int x;
//     int *y;
//     abc(int _x,int _y) : x(_x),y(new int(_y)) {}

//     //default dumb copy constructor it does shallow copy
//     //abc const abc & obj

//     {
//         x=obj.x;
//         y=obj.y;
//     }
//     //our smart deep copy
//     abc(const abc & obj) {
//         x=obj.x;
//         y=new int (*obj.y);
//     }
//     void print() const
//     {
//         printf("x:%d\nptr Y:%p\nconstent of y(*y):%d\n\n", x, y, *y);

//         ~abc (){
//             delete y;
//         }
//     }
// };

// int main() {
//     abc *a = new abc(1,2);
//     abc a=*a;
//     delete a;
//     b.print();
//     return 0;
// }