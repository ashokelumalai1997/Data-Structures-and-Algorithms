#include<iostream>
using namespace std;

class Node
{
	public:
		Node* next;
		int data;
};

Node* head = NULL;

void push(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->next = head;
	head = temp;
}

void pop()
{
	if(head==NULL)
	{
		return;
	}
	head = head->next;
}

void print()
{
	Node* temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"\n";
		temp=temp->next;
	}
}

int count()
{
	Node* temp = head;
	int count_val=0;
	while(temp!=NULL)
	{
		count_val++;
		temp=temp->next;
	}
	return count_val;
	
}

int main()
{
	int option,choice=1;
	while(choice)
	{
		cout<<"\nEnter your Option. \n1.Push \n2.Pop \n3.Print \n4.Count \n Any other value to exit";
		cin>>option;
		switch(option)
		{
			case 1:
				int data;
				cout<<"\nEnter the data";
				cin>>data;
				push(data);
				break;
			case 2:
				pop();
				break;
			case 3:
				print();
				break;
			case 4:
				int stack_count;
				stack_count=count();
				cout<<stack_count<<"\n";
				break;
			default:
				choice = 0;
				break;
		}
	}
}
