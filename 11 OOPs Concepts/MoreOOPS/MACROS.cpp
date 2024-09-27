#include<iostream>
using namespace std;

#define PI 3.14
#define MAXX(x,y) (x>y?x:y)

float circlearea(float r)
{
    return PI*r*r;
}
float circleperimeter (float r) {
    return 2*PI*r;
}
void fun(){
    int x=6;
    int b=17;
    int C=MAXX(x,b);
}
void fun2(){
    int a=6;
    int b=17;
    int C=MAXX(a,b);
}
void fun3(){
    int x=6;
    int y=17;
    int C=MAXX(x,y);
}
int main() {
    cout<<circlearea(65.4)<<endl;
    cout<<circleperimeter (65.4)<<endl;
    return 0;
}