#include<iostream>
using namespace std;
class Node
{
	public:
		Node* next;
		int data;
};

Node* head = NULL;

void enqueue(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	if(head == NULL)
	{
		head=temp;
		return;
	}
	temp->next = head;
	head=temp;
}

void dequeue()
{
	if(head == NULL)
	{
		return;
	}
	if(head->next==NULL)
	{
		head = NULL;
		return;
	}
	Node* temp = head;
	Node* previous = NULL;
	while(temp->next!=NULL)
	{
		previous = temp;
		temp = temp->next;
	}
	previous->next = NULL;
}

int getLength()
{
	Node* temp = head;
	int count = 0;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
}

void print()
{
	Node* temp = head;
	if(temp==NULL)
	{
		return;
	}
	while(temp!=NULL)
	{
		cout<<temp->data<<"\n";
		temp=temp->next;
	}
	
}

int main()
{
	int choice , option;
	choice=1;
	while(choice)
	{
		cout<<"Enter the option 1.Enqueue 2.Dequeue 3.Length 4.Print ... Any other value to exit...";
		cin>>option;
		switch(option)
		{
			case 1:
				int data;
				cout<<"Enter the data";
				cin>>data;
				enqueue(data);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				int length;
				length =  getLength();
				cout<<length<<"\n";
				break;
			case 4:
				print();
				break;
			default:
				choice=0;
				break;
		}
	}
}
