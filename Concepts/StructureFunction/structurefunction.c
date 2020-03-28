struct Rectangle
{
int length,breadth;
};
void initialize(struct Rectangle *r,int l,int b){
r -> length=l;
r -> breadth=b;}
void changelength(struct Rectangle *p,int l)
{
p -> length = l; }
int area(struct Rectangle r1)
{
return r1.length*r1.breadth;
}
int main(){
struct Rectangle r;
initialize(&r,10,5);
area(r);
changelength(&r,20);
}
