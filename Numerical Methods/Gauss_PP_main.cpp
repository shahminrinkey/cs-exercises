#include<iostream.h>
#include<math.h>

float **a;
int col,row;



void init(int n,int m)

{   

	a=new float*[m+1];
	for(int k=0;k<m+1;k++)
	{
      a[k]=new float[m+1];
	}
	cout<<"Enter co-effecients of the equations:\n";

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m+1;j++)
		{
			cout<<"a"<<i<<j<<":";
			cin>>a[i][j];
		}
	}

	col=0;
	row=1;
}

void pivoting(int n,int m)
{
   int pe,f;
  
   float temp,max;
   
   f=0;
   max=a[col][col];
	for(int i=row;i<n;i++)
	{   
		
		if(max<a[i][col])

		{    
			max=a[i][col];
			pe=i;
			f=1;
		}
	}
    
	if(f==1){
	for(int j=0;j<m+1;j++)
	{
		
		temp=a[col][j];
		a[col][j]=a[pe][j];
		a[pe][j]=temp;
		

	}
	}

	col++;
	row++;

}


void show(int n,int m)
{
	for(int g=0;g<n;g++)
	{
		for(int q=0;q<m+1;q++)
		{
			cout<<a[g][q]<<"\t";
		}
		cout<<"\n";
	}
}


void elimination()
{
   int r,c,i,j,k,h,n,m,f,count1,count2,count3; 
   
   float temp,temp1,tmp;
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

      pivoting(n,m);
        
	  cout<<"\nAfter pivoting:\n";
       show(n,m);
		temp1=a[r][r];

	for(i=c;i<m+1;i++)
	{
        a[r][i]=(a[r][i])/temp1;
	}
     
	r++;

	cout<<"\nAfter getting 1:\n";
  show(n,m);

   	for(j=r;j<n;j++)
	{
	    tmp=a[j][c];
		for(k=c;k<m+1;k++)
		{
			
			a[j][k]=((-1)*tmp)*(a[r-1][k])+a[j][k];

		}
	}
    
	c++;
    
	cout<<"\nAfter forward elimination:\n";
    show(n,m);
    
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

for(int z=1;z<=m;z++)
{
	x[z]=0;
}

x[m]=a[n-1][m];

count1=n-2;
count2=m;
count3=m;

while(count1>=0)
{   
    temp=0;
	while(count2>=1){
     temp+=a[count1][count2-1]*x[count2];

	 count2--;
	}
	count2=m;
x[count3-1]=a[count1][m]-temp;


    count1--;
	count3--;

	


}

for(i=1;i<m+1;i++)
{
	cout<<"\nX"<<i<<": "<<x[i];


}

}

int main()
{
	elimination();

	return 0;
}
	

       


     



