#include <iostream>

using namespace std;


class node {

public:

int data;

node *next;


node(int d) {

data = d;

next = NULL;

}

};


node *first = NULL;

node *ss = NULL;

// node *second = NULL;


void create(int arr[], int n) {

node *last;

node *t;

first = new node(arr[0]);

last = first;

for (int i = 1; i < n; i++) {

t = new node{arr[i]};

last->next = t;

last = t;

}

}


void ReverseLL(node *&ss) {

node *curr = ss;

node *next = NULL;

node *prev = NULL;


while (curr) {

next = curr->next;

curr->next = prev;

prev = curr;

curr = next;

}

ss = prev;

// return prev;

}
/*void Display(Node *p){

p = head;

do

{

printf("%d ",p->data);

p=p->next;

}while(p != head);

cout << endl;

}
*/
void Rprint(node *&head) {

node *temp = head;

if (temp == NULL) {

return;

}

cout << temp->data << " ";

Rprint(temp->next);

}


bool IsPalindrome(node *&head,int n) {

node *p = head;

int A[n];


for(int i=0;p;i++)

{

A[i]= p->data;

p=p->next;

}

p=head;

for(int i=n-1;i>=0;i--)

{

if(p->data!=A[i])

return false;

p=p->next;

}

return true;


}


int main(int argc, char const *argv[])

{
cout<< "Enter number of Elements" <<endl;

int n;

cin >> n;

int arr[n];

cout<< "Enter the Elements";


for (int i = 0; i < n; i++) {

cin >> arr[i];

}


create(arr, n);

Rprint(first);

cout << endl;

if (IsPalindrome(first,n) == 1) {

cout << "True" << endl;

} else cout << "False" << endl;

return 0;

}


