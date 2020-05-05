#include <iostream>
using namespace std;
void heapify(int H[],int n)
{
    int i=n/2-1; int dummy;
    int largest,left,right;
    for(int l=i;l>=1;l--)
    {
        dummy=l;
        largest=dummy;
        left=2*dummy;
        right=left+1;
        do
        {
        if(left<=n-1 && H[left]>H[largest])
            largest=left;
        if(right<=n-1 && H[right]>H[largest])
            largest=right;
        if(largest!=dummy)
            {
                int t=H[dummy];
                H[dummy]=H[largest];
                H[largest]=t;
                dummy=largest;
                left=2*dummy;
                right=left+1;
            }
        }while(left<=n-1);
    }
}
void heapsort(int H[],int n)
{
    int x=H[1];
    H[1]=H[n];
    int i=1; int j=2*i;
    while(j<=n-1)
    {
        if(H[j]<H[j+1])
            ++j;
        if(H[j]>H[i])
        {
            int t=H[i];
            H[i]=H[j];
            H[j]=t;
            i=j;
            j=2*i;
        }
        else break;
    }
    H[n]=x;
}
int main()
{
    int H[]={0,5,10,30,20,35,40,15};
    heapify(H,8);
    for(int i=1;i<=7;i++)
        cout<<H[i]<<" ";
        cout<<endl;
    for(int i=7;i>1;i--)
    heapsort(H,i);
    for(int i=1;i<=7;i++)
        cout<<H[i]<<" ";
    return 0;
}
