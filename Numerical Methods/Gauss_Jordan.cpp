#include<iostream.h>
#include<math.h>

float a[10][10];



void init(int n,int m)
{
	cout<<"Enter co-effecients of the equations:\n";

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m+1;j++)
		{
			cout<<"\na"<<i<<j<<":";
			cin>>a[i][j];
		}
	}
}






void elimination()
{
   int r,c,i,j,k,j1,j2,k1,k2,h,n,m,f,count1,count2,count3; 
   
   float temp,temp1,tmp1,tmp2;
   float x[10];

cout<<"\nNumber of equations:";
cin>>n;
cout<<"\nNumber of unknowns:";
cin>>m;

init(n,m);




f=0;
r=0;
c=0;


	
	
	while(1){

		temp1=a[r][r];

	for(i=c;i<m+1;i++)
	{
        a[r][i]=(a[r][i])/temp1;
	}
     
	

    if(c>0)
	{
		for(j1=0;j1<=c-1;j1++)
		{
            tmp1=a[j1][c];
			for(k1=c;k1<m+1;k1++)
			{
				a[j1][k1]=((-1)*tmp1)*(a[c][k1])+a[j1][k1];
			}
		}

	}
	if(c!=m){
			r++;


   	for(j2=r;j2<n;j2++)
	{
	    tmp2=a[j2][c];
		for(k2=c;k2<m+1;k2++)
		{
			
			a[j2][k2]=((-1)*tmp2)*(a[r-1][k2])+a[j2][k2];

		}
	}
	
	}
    
    
	c++;


    
	for(h=0;h<m-1;h++)
	{
        if(a[n-1][h]==0&&a[n-1][m-1]==1)
		{
			f=1;
		}
	}

if(f==1)
break;

}

cout<<"\nAfter Elimination:\n";

for(j=0;j<n;j++)
{
	for(k=0;k<m+1;k++)
	{
		cout<<a[j][k]<<"\t";
	}
	cout<<"\n";
}

for(int z=0;z<=m;z++)
{   
     	x[z]=a[z][m];
}



for(i=0;i<m+1;i++)
{
	cout<<"\nX"<<i<<": "<<x[i];


}

}

int main()
{
	elimination();

	return 0;
}
	

       


     



