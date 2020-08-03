#include<iostream>
#include<queue>

using namespace std;

int *heap;
int size=0;

int *max_heap;
int max_size=0;

char array[100];
int frequency[100];

int char_number;

void insert(int data)
{

    int parent,curr,temp;
	size++;
	heap[size]=data;

	parent=size/2;
    curr=size;

	while(heap[parent]>heap[curr])
	{
       temp=heap[parent];
	   heap[parent]=heap[curr];
	   heap[curr]=temp;
	   curr=parent;
	   parent=curr/2;
	}
}

int extract()
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

		if(lc<rc){
			target=2*curr;
		}
		else{
			target=2*curr+1;
		}

		temp=heap[curr];
		heap[curr]=heap[target];
		heap[target]=temp;
         curr=target;



	}while(heap[curr]>heap[target]);
	return ans;
}


int empty()
{
	if(size==0)
		return 0;
	else
		return 1;
}


void max_insert(int data)
{

    int parent,curr,temp;
	max_size++;
	max_heap[max_size]=data;

	parent=max_size/2;
    curr=max_size;

	while(max_heap[parent]<max_heap[curr])
	{
       temp=max_heap[parent];
	   max_heap[parent]=max_heap[curr];
	   max_heap[curr]=temp;
	   curr=parent;
	   parent=curr/2;
	}
}








void init()
{
    cout<<"\nNumber of characters:";
	cin>>char_number;

	heap=new int[char_number];
	max_heap=new int[char_number*2];

	for(int i=0;i<char_number;i++)
	{
		cout<<"\nalphabet:";
		cin>>array[i];
		cout<<"\nfrequency:";
		cin>>frequency[i];

		insert(frequency[i]);
		max_insert(frequency[i]);
	}

}


char find_character(int freq)
{
	int index;

   for(int i=0;i<char_number;i++)
   {
	   if(freq==frequency[i])
	   {
		   index=i;
		   break;
	   }

   }

   return array[index];
}


void huffman()
{

	int top,lft,rght;
	char alphabet;
   
	while(empty()!=0)
	{
	lft=extract();
	rght=extract();

	top=lft+rght;

	insert(top);

	max_insert(top);


    }

	cout<<"\nMinheap:";
	for(int k=1;k<=size;k++)
	{
		cout<<heap[k]<<" ";
	}
	cout<<"\nMaxheap:";
	for(int q=1;q<=max_size;q++)
		cout<<max_heap[q]<<" ";



	for(int i=1;i<=max_size;i++)
	{
       
         if((i*2)>max_size&&((i*2)+1)>max_size)
		 {
             alphabet=find_character(max_heap[i]);
				 cout<<alphabet<<"=";

			 for(int j=1;j<=i;j++)
			 {

                 if(i%2!=0)
					 cout<<"1";
				 else
					 cout<<"0";
			 }

		 }

	}
}


    
int main()
{

	init();

	huffman();

	return 0;
}




     






