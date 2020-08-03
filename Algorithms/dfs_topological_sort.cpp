#include<iostream>
#include<queue>

using namespace std;


int color[8],start[8],finish[8],parent[8],time;
int adj[8][8]={{0,0,0,0,0,1,1,0},{1,0,1,0,0,1,0,0},{0,0,0,0,0,1,0,1},{0,0,1,0,1,0,0,1},{0,0,0,0,0,1,0,0},{0,0,0,0,0,0,1,0},{0,1,0,0,0,0,0,0},{0,0,0,0,0,1,0,0}};

enum COLOR {WHITE,GRAY,BLACK};

priority_queue<int> maxQueue;

void dfs_visit(int u)
{
int v;
	color[u]=GRAY;
	time++;
     start[u]=time;

	 for(int i=0;i<8;i++)
	 {
	     if(adj[u][i]==1)
         {
		 v=i;
         if(color[v]==WHITE)
		 {
			 parent[v]=u;
			 dfs_visit(v);
		 }
         }

	 }

	 color[u]=BLACK;
	 time++;
	 finish[u]=time;
	 maxQueue.push(finish[u]);

}


void DFS()
{
     int i;

    for(i=0;i<8;i++)
	{
		color[i]=WHITE;
		start[i]=0;
		finish[i]=0;
    }

    for(i=0;i<8;i++)
	{
        if(color[i]==WHITE)
			dfs_visit(i);
	}
}




void topological_sort()
{
	int n,w;
	cout<<"\n";
	for(int k=0;k<8;k++)
	{
		n=maxQueue.top();
		maxQueue.pop();
		for(int j=0;j<8;j++)
		{
			if(n==finish[j])
				w=j;
		}

		cout<<w<<"\t";
	}
}





int main()
{
   DFS();
   for(int j=0;j<8;j++)
   cout<<"\nVertex:"<<j<<"\tStart time:"<<start[j]<<"\tFinish time:"<<finish[j];
   cout<<"\nTopological sort:";
   topological_sort();
   return 0;
}






