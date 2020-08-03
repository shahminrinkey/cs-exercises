#include<iostream>

using namespace std;

int cost[6][6];
int vcost;
int visited[6];

int vert_cost[6];
int size=0;
int *heap;


void insert(int data)
{

    int parent,curr,temp;
	size++;
	heap[size]=data;

	parent=size/2;
    curr=size;

	while(heap[parent]<heap[curr])
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

void display()
{
   for(int i=1;i<=size;i++)
   {
      cout<<heap[i]<<"\t";
	  }
}


int main()
{

	int vno,eno,i,j,k;

	int vertex,edge;

	cin>>vno>>eno;
     heap=new int[vno];
	for(i=1;i<=eno;i++)
	{   cin>>vertex>>edge;
	cout<<"cost:\n";
	cin>>vcost;
	    cost[vertex][edge]=vcost;
	    vert_cost[vertex]+=vcost;


	}


   for(i=1;i<=vno;i++)
   {
     insert(vert_cost[i]);
   }




  display();

  int limit=size;
  int d,f;

  cout<<"\nVisited nodes according to priority queue:\n";
  for(i=1;i<=limit;i++)
  {
             d=del();

            for(j=1;j<=vno;j++)
            {
                    if(vert_cost[j]!=-1){
                 if(vert_cost[j]==d){
                        cout<<j<<" ";

                     vert_cost[j]=-1;
                 break;
                 }

                }

            }

  }



	return 0;
}





