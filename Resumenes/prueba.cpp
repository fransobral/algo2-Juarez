#include <iostream>
using namespace std;

int main(){
unsigned char x = 0x6;
unsigned char y=0x10;
unsigned char z=0xb1;
unsigned char u;
unsigned char v;
unsigned char w;

u = ~z;
v = x&y;
w= x|z;

cout <<"hola" << x << y << z<<endl;
cout << u << v << w<< endl;
return 0;
;}