#include<iostream>
using namespace std;
class Node
{
	public:
		int data;
		Node* next;
};

Node* head = NULL;
//Function to insert node at End
void insertNode(int value)
{
	Node* temp = new Node;
	temp->data = value;
	temp->next = NULL;
	if(head == NULL)
	{
		head=temp;
		return;
	}
	Node* temp1 = head;
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
	}
	temp1->next = temp;
}
//Function to insert node at End
void deleteData()
{
	if(head == NULL)
	{
		return;
	}
	if(head->next==NULL)
	{
		head=NULL;
		return;
	}
	Node* temp = head;
	Node* previous = head;
	while(temp->next!=NULL)
	{
		previous=temp;
		temp=temp->next;
	}
	previous->next=NULL;
}

//Function to print the linked list

void printList()
{
	if(head==NULL)
	{
		return;
	}
	Node* temp = head;
	cout<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
	cout<<"\n";
	while(temp!=NULL)
	{
		cout<<temp->data<<" -> ";
		temp=temp->next;
	}
	cout<<"NULL\n";
	cout<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
}

//Function to get the length of linked list

int getCount()
{
	Node* temp = head;
	int count=0;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
}

//Function to insert node at Nth postion

void insertNodeAtPosition(int position,int data)
{
	if(position>getCount()+1)
	{
		return;
	}
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	if(head==NULL)
	{
		head=temp;
		return;
	}
	Node* temp1 = head;
	if(position == 1)
	{
		temp->next=head;
		head=temp;
		return;
	}
	while(position>2&&temp1->next!=NULL)
	{
		temp1=temp1->next;
		position--;
	}
	temp->next=temp1->next;
	temp1->next=temp;
}

//Function to delete node at Nth position

void deleteAtPosition(int position)
{
	if(position>getCount())
	{
		return;
	}
	Node* current = head;
	Node* previous = NULL;
	Node* next = NULL;
	if(position==1)
	{
		head=head->next;
		return;
	}
	while(position>1)
	{
		previous=current;
		current=current->next;
		next=current->next;
		position--;
	}
	previous->next=next;
	
}
int main()
{
	int option,choice=1;
	cout<<"\n******************************************************************************";
	while(choice)
	{
		cout<<"\nEnter your option \n\n1.Insert Node at End \n\n2.Delete Node at End \n\n3.Print the Linked list \n\n4.Insert Node at specific Position \n\n5.Delete Node at specific position \n\n6.Get length of the list  \n\nAny other value to exit...";
		cin>>option;
		switch(option)
		{
			case 1:
				int data;
				cout<<"\nEnter the data";
				cin>>data;
				insertNode(data);
				break;
			case 2:
				deleteData();
				break;
			case 3:
				printList();
				break;
			case 4:
				int position;
				cout<<"\nEnter the position";
				cin>>position;
				cout<<"\nEnter the data";
				cin>>data;
				insertNodeAtPosition(position,data);
				break;
			case 5:
				cout<<"\nEnter the position";
				cin>>position;
				deleteAtPosition(position);
				break;
			case 6:
				int count;
				count=getCount();
				cout<<count<<"\n";
				break;
			default:
				choice = 0;
				break;
			
		}
	cout<<"\n******************************************************************************";
	}
}
