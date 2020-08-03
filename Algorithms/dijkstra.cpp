#include<iostream>
using namespace std;

#define INFINITY 1000000;

int adj[10][10],vno,eno,d[10],parent[10],cost[10][10];
int size=0;
int *heap;
void minQ(int data)
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

int DQ()
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

int find_vert(int data,int n)
{
    int index;

    for(int i=1;i<=n;i++)
    {
        if(data==d[i])
            {

                index=i;
                break;
            }

    }
    return index;


}

void init()
{

	int vertex,edge,i;
	cout<<"\nEnter vertex number:";
	cin>>vno;
	cout<<"Enter edge number:";
	cin>>eno;

	for(i=1;i<=eno;i++)
	{
		cin>>vertex>>edge;
		cout<<"\nCost:";
		cin>>cost[vertex][edge];
	    adj[vertex][edge]=1;
	}

     for(int j=1;j<=vno;j++)
	 {
		 d[j]=INFINITY;
		 parent[j]=0;
	 }

}
void display()
{
   for(int i=1;i<=size;i++)
   {
      cout<<heap[i]<<"\t";
	  }
}
void shortest(int src)
{
	int i,u,v,min_d;
	d[src]=0;

	minQ(d[src]);

	while(empty()!=0)
	{
        min_d=DQ();
    u=find_vert(min_d,vno);
      cout<<"\n"<<u;

		for(v=1;v<=vno;v++)
		{
			if(adj[u][v]==1)
			{

				if(d[v]>d[u]+cost[u][v]){

				d[v]=d[u]+cost[u][v];
			parent[v]=u;
            minQ(d[v]);

				}
			}
		}

	}
}



int main()

{
 heap=new int[vno];

init();

shortest(1);

for(int i=1;i<=vno;i++)
cout<<"\n"<<d[i];

return 0;


	}

