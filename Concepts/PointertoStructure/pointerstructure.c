struct Rectangle
{
int length,breadth;
};
int main(){
struct Rectangle r={10,5};
struct Rectangle *q=&r;
(*q).length=15;
q->breadth=10;
struct Rectangle *p;
p=(struct Rectangle *)malloc(sizeof(struct Rectangle));
p->breadth=100;
p->length=50;
}
//Malloc function returns Void
