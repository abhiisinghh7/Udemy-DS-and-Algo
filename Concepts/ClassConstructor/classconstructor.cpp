#include<iostream>
using namespace std;
class Rectangle{
private:
int length,breadth;
public:
Rectangle(){length=breadth=1;}
Rectangle(int l,int b);
int area();
int perimeter();
int getlength(){return length;}
void setlength(int l){length=l;}
//To free up any memory which is dynamically alloted we use a destructor
~Rectangle();
};
Rectangle::Rectangle(int l,int b){
length=l;
breadth=b;}
int Rectangle::area(){
return length*breadth;}
int Rectangle::perimeter(){
return 2*(length+breadth);}
Rectangle::~Rectangle(){}
int main(){
Rectangle r(10,5);
cout<<r.area();
cout<<r.perimeter();
r.setlength(20);
cout<<r.getlength();
}
