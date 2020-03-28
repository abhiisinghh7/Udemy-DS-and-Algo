//Structure converts to Class
class Rectangle
{private:
int length,breadth;
public:
Rectangle(int l,int b)
//Constructor
{length=l;
breadth=b;}
void changelength(int l)
{length = l; }
int area()
{
return length*breadth;
}
};
int main(){
Rectangle r(10,5);
//Now in C++ r is a object
r.area();
r.changelength(20);
}
