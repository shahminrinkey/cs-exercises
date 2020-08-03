#include<iostream>
using namespace std;

int adj[10][10],vno,eno,color[10],d[10],parent[10];

int q[10];
int rear=-1;
int front=-1;

int WHITE=0;
int GRAY=1;
int BLACK=2;

void Enq(int x)
{
	q[++rear]=x;
}

int Dq()
{
   return q[++front];
}

int empty()
{
	if(front==rear)
		return 0;
	else
	return 1;
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
	    adj[vertex][edge]=1;
		adj[edge][vertex]=1;
	}

     for(int j=1;j<=vno;j++)
	 {
		 color[j]=WHITE;
		 d[j]=0;
	 }

}

void BFS(int src)
{
   int i,u,v;
   color[src]=GRAY;
   parent[src]=0;
   d[src]=0;
   Enq(src);
   while(empty()!=0)
   {
      u=Dq();
	  cout<<u<<" ";

	  for(i=1;i<=vno;i++)
	  {
		  if(adj[u][i]==1)
		  {
			  v=i;
			  if(color[v]==WHITE)
			  {
				  Enq(v);
				  color[v]=GRAY;
				  parent[v]=u;
				  d[v]=d[u]+1;
			  }
		  }
	  }

	  color[u]=BLACK;

	  }
}

int main()
{
	int source;
	init();
	cout<<"\nEnter sousce vertex:";
	cin>>source;
	cout<<"Path of graph:\n";

	BFS(source);

	cout<<"Cost of the vertices:\n";
	for(int i=1;i<=vno;i++)
		cout<<i<<" = "<<d[i]<<"\n";




	return 0;
}





















