  
#include<iostream.h>

char array[5][5];
int size=1;

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

int find(char value)
    {
        node *current=new node;
        int found=0;
        int count=1;
        current=head;
        while(current->next!=NULL)
        {
            if(current->data==value)
            {
                found=1;
                break;
            }
            current=current->next;
            count++;
        }

        if(found==0)
        return -1;

        else
        return 1;
    }


	int graph(char vertex,int edgeno)
	{
        int i=1;
		char edge;
        
        insert(vertex,1);

		while(i<=edgeno)
		{
			cout<<"\nEdge:";
			cin>>edge;

			insert(edge,i+1);

			array[size][i]=edge;

			i++;

			
		}

		size++;

		return i-1;

	}


void del(char value)
    {
        node *current=new node;
        node *prev=new node;
        prev=NULL;
        current=head;

        while(current->data!=value&&current!=NULL)
        {
           prev=current;
         current=current->next;

        }
        if(current!=NULL){
            if(prev!=NULL){
        prev->next=current->next;
        delete current;
            }
            else
            {
                head=current->next;
                delete current;
            }
        }

        else
        cout<<"\nValue not found";



    }

char head_data()
{
	return head->data;
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


void outdegree(int a[],int list_size)
	{
       
		 for(int h=1;h<list_size;h++){

			if(h==1)

			 cout<<"A degree:"<<a[h];

			else if(h==2)
				cout<<"B degree:"<<a[h];
			else if(h==3)
				cout<<"C degree:"<<a[h];
			else if(h==4)
				cout<<"D degree:"<<a[h];
			else if(h==5)
				cout<<"E degree:"<<a[h];
		 }



	   
    }




void indegree()
{
    
    int incount[6]={0,0,0,0,0,0}; 
	int n;
for(int p=1;p<=size;p++)
{
	for(int g=1;array[p][g]!=NULL;g++)
	{
		if(array[p][g]=='A'){
			n=1;
		   incount[n]++;
		}
		else if(array[p][g]=='B'){
			n=2;

			incount[n]++;
		}

		else if(array[p][g]=='C'){
			n=3;
			incount[n]++;
		}

		else if(array[p][g]=='D'){
				n=4;
			incount[n]++;
		}
			else if(array[p][g]=='E')
			{
				n=5;
				incount[n]++;
			}

		}
	}


	for(int m=1;m<=size;m++)
	{
		if(m==1)
		{
			cout<<"A indegree:"<<incount[m];
		}

else if(m==2)
		{
			cout<<"B indegree:"<<incount[m];
		}

else if(m==3)
		{
			cout<<"C indegree:"<<incount[m];
		}

else if(m==4)
		{
			cout<<"D indegree:"<<incount[m];
		}

else if(m==5)
		{
			cout<<"E indegree:"<<incount[m];
		}


	}
	
			
         
}







  


int main()
{
	
  node ob[5],obk;
	int eno,i,j,m,n,h,f,lnum,degree[5];
  char ch,v,e,dvalue,Head;
   i=1;
   j=1;
  cout<<"\nWant to enter vertex and edge?y/n";
  cin>>ch;
  while(ch!='n'){

        cout<<"\nVertex:";
		cin>>v;
		cout<<"\nEdge No:";
		cin>>eno;

		degree[i]=ob[i].graph(v,eno);

   

		
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

outdegree(degree,i);
indegree();



cout<<"\nEnter value and and list number for delete\n";
  cin>>dvalue>>lnum;

  ob[lnum].del(dvalue);

cout<<"\nAfter deleteing\n";

m=1;

while(m<=i)
  {
	  ob[m].dispaly();
	  cout<<"\n";
	  m++;
  }

cout<<"\nAdd an edge and list number for the edge\n";
cin>>e>>lnum;
i++;
ob[lnum].insert(e,i);

cout<<"\nAfter Inserting\n";

n=1;

while(n<=i)
  {
	  ob[n].dispaly();
	  cout<<"\n";
	  n++;
  }






  return 0;
  }








