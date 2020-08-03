#include<iostream.h>

class node
{

public:
	node *head,*next;
	char data;


	node()
	{
		head=NULL;
		next=NULL;

	}

	void insert(char item,int index)
	{
		node *current=new node;
		node *newnode=new node;

		int currindex=1;

		if(head==NULL||index==1)
		{
			newnode->data=item;
			newnode->next=head;
			head=newnode;
		}

		else

		{
			current=head;

			while(current->next!=NULL&&currindex<index)
			{
				current=current->next;
				currindex++;
			}

			newnode->data=item;
            newnode->next=current->next;
			current->next=newnode;
		}


	}

	void graph(char vertex,int edgeno)
	{
        int i=1;
		char edge;

        insert(vertex,1);

		while(i<=edgeno)
		{
			cout<<"\nEdge:";
			cin>>edge;

			insert(edge,i+1);

			i++;
		}

	}

	void dispaly()
	{
		node *current=new node;

		current=head;

		while(current!=NULL)
		{
			cout<<current->data;
			current=current->next;
		}
	}








};


int main()
{
  node ob[5];
	int eno,i,j;
  char ch,v;
   i=1;
   j=1;
  cout<<"\nWant to enter vertex and edge?y/n";
  cin>>ch;
  while(ch!='n'){

        cout<<"\nVertex:";
		cin>>v;
		cout<<"\nEdge No:";
		cin>>eno;

		ob[i].graph(v);

		i++;


cout<<"\nWant to enter vertex and edge?y/n";
  cin>>ch;
  }


  while(j<=i)
  {
	  ob[j].dispaly();
	  cout<<"\n";
	  j++;
  }

  return 0;
  }








