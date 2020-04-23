    #include<iostream>
using namespace std;
    struct Node
    {
    	int data;
    	Node* next;
    };


    class Queue
    {
    public:
    	Node* Front, * Rear;
    	Queue()
    	{
    		Front = Rear = nullptr;
    	}

    	void push(int data)
    	{
    		Node* temp = new Node();
    		temp->data = data;
    		temp->next = nullptr;

    		if (Front == nullptr)
    		{
    			Front = Rear = temp;
    		}

    		else
    		{
    			Rear->next = temp;
    			Rear = temp;
    		}

    	}

    	void pop()
    	{
    	    Node* temp = Front;
    	    Front = Front->next;
    	    std::cout << "\nItem popped: " << temp->data;
    	    delete temp;
    	}

    	void display()
    	{
    		Node* temp = Front;
    		std::cout << "\nQueue : ";
    		while (temp != nullptr)
    		{
    			std::cout << temp->data << " ";
    			temp = temp->next;
    		}
    	}

    	bool empty()
    	{
    		if (Front == nullptr)
    		{
    			return true;
    		}
    		return false;
    	}

    }que1, que2, que3;


    struct PriorityQueNode
    {
    	int data;
    	int priority;
    };


    void popPriority()
    {
    	if (!que1.empty())
    	{
    		que1.pop();
    	}
    	else if (!que2.empty())
    	{
    		que2.pop();
    	}
    	else
    		que3.pop();
    }


    void DisplayPriority()
    {
    	if(!que1.empty())
    	que1.display();

    	if(!que2.empty())
    	que2.display();

    	if(!que3.empty())
    	que3.display();


    }


    int main()
    {
    	PriorityQueNode Ar[8];

    	for (int i = 0; i < 8; ++i)
    	{
    		Ar[i].data = 10 *(i+1);
    	}

    	Ar[0].priority = 1;
    	Ar[1].priority = 1;
    	Ar[2].priority = 2;
    	Ar[3].priority = 3;
    	Ar[4].priority = 2;
    	Ar[5].priority = 1;
    	Ar[6].priority = 2;
    	Ar[7].priority = 3;


    	for (int i = 0; i < 8; i++)
    	{
    		if (Ar[i].priority == 1)
    			que1.push(Ar[i].data);

    		else if (Ar[i].priority == 2)
    			que2.push(Ar[i].data);

    			else
    				que3.push(Ar[i].data);
    	}

    	DisplayPriority();
    	popPriority();
    	popPriority();
    	popPriority();
    	popPriority();
    	popPriority();
    	DisplayPriority();

    }
