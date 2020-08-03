#include<iostream.h>

#define INFINITY 1000000;

int adj[10][10],vno,eno,d[10],parent[10],cost[10][10];

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
		cout<<"Cost:";
		cin>>cost[vertex][edge];
	    adj[vertex][edge]=1;
	}

     for(int j=1;j<=vno;j++)
	 {
		 d[j]=INFINITY;
		 parent[j]=0;
	 }

}


int Bellman_Ford()
{
	int u,v,i;
	init();
   
	for(i=1;i<=vno-1;i++)
	{
		for(u=1;u<=vno;u++)
		{
			for(v=1;v<=vno;v++)
			{
				if(adj[u][v]==1){
				if(d[v]>d[u]+cost[u][v])
					d[v]=d[u]+cost[u][v];
				}
			}
		}
	}
	for(u=1;u<=vno;u++)
	{
		for(v=1;v<=vno;v++)
		{
			if(d[v]>d[u]+cost[u][v])
				return 0;
		}
	}

	return 1;
}


int main()
{
	int f;

	f=Bellman_Ford();

	if(f==1)
	{
		for(int i=1;i<=vno;i++)
			cout<<d[i];
	}
	else
		cout<<"unstable";
	return 0;
}
