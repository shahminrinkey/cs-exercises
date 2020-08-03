#include<iostream>
#include<algorithm>

using namespace std;

int mst[10],adj[10][10],vno,eno,d,cost[10][10],color[10];

enum color{WHITE,GREY,BLACK};
int *heap;
int size=0;
void min_push(int data)
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

int min_pop()
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
void init()
{

	int vertex,edge,i;
	cout<<"\nEnter vertex number:";
	cin>>vno;
	cout<<"Enter edge number:";
	cin>>eno;
    heap=new int[vno];
	for(i=1;i<=eno;i++)
	{
		cin>>vertex>>edge;
		cout<<"Cost:";
		cin>>cost[vertex][edge];
		cost[edge][vertex]=cost[vertex][edge];

		min_push(cost[vertex][edge]);
	    adj[vertex][edge]=1;
		adj[edge][vertex]=1;
	}

      
}

int find_vert(int data)
{
    int index;

    for(int i=1;i<=vno;i++)
    {
		for(int j=1;j<=vno;j++)
		{
        if(data==cost[i][j])
            {

                index=i;
				
                break;
            }
		}
	}

    
    return index;


}
int find_edge(int data,int vertex)
{
    int index;

    for(int i=1;i<=vno;i++)
    {
		if(adj[vertex][i]==1)
		{
        if((data==cost[vertex][i])&&(color[i]==0))
            {

                index=i;
                break;
            }
		}

    }
    return index;


}

int is_visited(int v,int e)
{
	int f=0;
	int j;
         for(j=1;j<=vno;j++)
			{
			 if(mst[j]==v){
				 f=1;
			    
			    if(color[e]==1)
					f=-1;
			 
				 
			 }

		 }

		 cout<<"\nf:"<<f;

		 return f;
}



void shortest()
{


	int vertex,edge,min_cost,i,f,count;
    i=1;
	count=1;
	while(count<=eno)
	{
	min_cost=min_pop();
	cout<<"\nMin cost:"<<min_cost;
	vertex=find_vert(min_cost);
cout<<"\nvertex:"<<vertex;
     edge=find_edge(min_cost,vertex);
cout<<"\nedge:"<<edge;
             f=is_visited(vertex,edge);

			 if(f==0)
			 {
			  mst[i++]=vertex;
              mst[i++]=edge;
			  d+=min_cost;
			 }

			 else if(f==1)
			 {
				 mst[i++]=edge;
				 d+=min_cost;
			 }

			 if(count==vno-1)
				 break;

			 color[edge]=1;

			 count++;
	}
}


int main()
{
   int i;
	init();
	shortest();

	cout<<"\nCost:"<<d;
	
	cout<<"\n";

	for(i=1;i<=vno;i++)
	{
		cout<<mst[i];
	}


return 0;
}




			
           
            


    











