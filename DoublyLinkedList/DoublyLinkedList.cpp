#include<iostream>
using namespace std;
class Node
{
	public:
		Node* next;
		Node* previous;
		int data;
};

Node* head = NULL;
Node* tail = NULL;

void Insert(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	temp->previous = NULL;
	if(head == NULL)
	{
		head = temp;
		tail = temp;
		return;
	}
	Node* temp1 = head;
	while(temp1->next !=NULL)
	{
		temp1=temp1->next;
	}
	temp->previous=temp1;
	temp1->next=temp;
	tail = temp;
}

void Print()
{
	if(head == NULL)
	{
		return;
	}
	Node* temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"\n";
		temp = temp->next;
	}
}

int getLength()
{
	if(head == NULL)
	{
		return 0;
	}
	int count=0;
	Node* temp = head;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
}

void insertAtPosition(int position,int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	temp->previous = NULL;
	if(head == NULL)
	{
		if(position == 1)
		{
			head=temp;
			tail=temp;
		}
		return;
	}
	if(position == 1)
	{
		temp->next = head;
		head->previous = temp;
		head = temp;
		return;
	}
	if(position==1+getLength())
	{
		tail->next = temp;
		temp->previous = tail;
		tail = temp;
		return;
	}
	Node* temp1 = head;
	while(temp1->next!=NULL && position > 2)
	{
		position--;
		temp1=temp1->next;
	}
	Node* Next = temp1->next;
	temp->next = temp1->next;
	temp->previous = temp1;
	temp1->next = temp;
	Next->previous = temp;
	
}


int main()
{
	int option , position, data, choice=1;
	while(choice == 1)
	{
		cout<<"\nEnter the option. \n1.Insert a new node \n2.Print the list \n3.Insert at position \n4.Get Length \nAny other values to exit...";
		cin>>option;
		switch(option)
		{
			case 1:
				cout<<"Enter the data";
				cin>>data;
				Insert(data);
				break;
			case 2:
				Print();
				break;
			case 3:
				cout<<"Enter the data";
				cin>>data;
				cout<<"Enter the position";
				cin>>position;
				insertAtPosition(position,data);
				break;
			case 4:
				int count;
				count=getLength();
				cout<<"\n"<<count;
				break;
			default:
				choice=0;
				break;
		}
	}
}
