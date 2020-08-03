#include<iostream.h>

int heap[20];
int size=0;


void insert(int data)
{

    int parent,curr,temp;
	size++;
	heap[size]=data;

	parent=size/2;
    curr=size;

	while(size>1&&heap[parent]<heap[curr])
	{
       temp=heap[parent];
	   heap[parent]=heap[curr];
	   heap[curr]=temp;
	   curr=parent;
	   parent=curr/2;
	}
}

int del()
{
	int lc,rc,temp,curr,target,ans;
     
	ans=heap[1];
	heap[1]=heap[size];
	size--;

	curr=1;
       


     do
	{
		lc=heap[2*curr];
		rc=heap[2*curr+1];

		if(lc>rc){
			target=2*curr;
		}
		else{
			target=2*curr+1;
		}
		
		temp=heap[curr];
		heap[curr]=heap[target];
		heap[target]=temp;
         curr=target;
	

		
	}while(heap[curr]<heap[target]);
	return ans;
}

void min()
{
   cout<<"\nMinimum value:";
	cout<<heap[size-1];
}


void max()
{    
	
	cout<<"\nMax:"<<heap[1];
}


void find(int value)
{
int i=1;
int f=0;	
if(value==heap[1]){
	   cout<<"\nValue found in index:"<<i;
	   f=1;
}
   	
   while(1)
	{
	   if(value==heap[2*i]){
          cout<<"\nValue found in index:"<<2*i;
           f=1;
           break;
	   }
        else if(value==heap[2*i+1])
		{
          cout<<"\nValue found in index:"<<2*i+1;
           f=1;
           break;
		}
          
		else
		{
			if(value>heap[2*i])
				i=2*i+1;
			else
				i=2*i;
		}
	}
    
   if(f==0)
	   cout<<"\nValue not found";

}





void display()
{
   for(int i=1;i<size;i++)
   {
      cout<<heap[i]<<"\t";
	  }
}

int main()
{

    int d;
	insert(5);
	insert(10);
	insert(13);
	insert(6);
    insert(8);
	insert(9);

	display();
    find(9);
	d=del();

    cout<<"\nDelete element:"<<d<<"\n";
	display();

	min();
	max();

	
	return 0;
}


















	

