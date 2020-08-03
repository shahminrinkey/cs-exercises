#include<iostream>
using namespace std;

int adj[10][10],vno,eno,color[10],d[10],parent[10],set[10];

int q[10];
int rear=-1;
int front=-1;
int bip=1;
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
		 parent[j]=0;
		 set[j]=-1;
	 }

}

void BFS(int src)
{
   int i,u,v;
   color[src]=GRAY;
   parent[src]=0;
   d[src]=0;
   Enq(src);
   set[src]=1;
   while(empty()!=0)
   {
      u=Dq();

	  for(i=1;i<=vno;i++)
	  {
		  if(adj[u][i]==1)
		  {
			  v=i;
			  if(set[u]==set[v])
				  bip=0;
			  else{
				  if(set[u]==1)
			  set[v]=2;
				  else if(set[u]==2)
					  set[v]=1;
			  }

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

void print_path(int s,int v)
{
    if(v==s)
    cout<<"\t"<<s;
    else if(parent[v]==0)
    cout<<"\nNo path";
    else
    {
         cout<<"\t"<<v;
         print_path(s,parent[v]);

    }


}

int main()
{
	int source,p;
	init();
	cout<<"\nEnter sousce vertex:";
	cin>>source;
	cout<<"Graph traversal:\n";

	BFS(source);

    for(int j=1;j<=vno;j++)
    {
        cout<<"\nDistence of vertex "<<j<<":"<<d[j];

    }

	if(bip==1)
		cout<<"\nGraph is bipartite";
	else
		cout<<"\nGraph is not bipertite";
     cout<<"\nEnter vertex:";
     cin>>p;
    cout<<"\nShortest path between the source vertex and given vertex:\n";
    print_path(1,p);

	return 0;
}





















