#include<iostream.h>

#include<math.h>

float **b;
float *a;
float *x;
float *y;

float sr,st,Syx;

void init(int n,int m)
{

  int i,j,k,l;
  float sum;

   
  a=new float[m+1];
  x=new float[n];
  y=new float[n];

  b=new float*[m+1];
  for(k=0;k<m+1;k++)
  {
	 b[k]=new float[m+1];
  }

  for(i=0;i<n;i++)
  {   
	  cout<<"X"<<i<<":";
	  cin>>x[i];
	  cout<<"Y"<<i<<":";
	  cin>>y[i];
  }
  



b[0][0]=n;
 
  
  for(i=0;i<m+1;i++)
  {
	l=0;
	  for(j=0;j<m+1;j++){

		  l=j;
		  if(i==0){
			  l=j+1;
		  }

		  sum=0;
		  for(k=0;k<n;k++){
           sum+=pow(x[k],l+i);
		  }
		  b[i][l]=sum;
		 
	  }
	  

	 
  }


  for(i=0;i<m+1;i++)
  {   
	  sum=0;
	  for(int j=0;j<n;j++)
	  {
		  sum+=(pow(x[j],i)*y[j]);
	  }
	  b[i][m+1]=sum;
  }

for(i=0;i<m+1;i++)
{
	for(j=0;j<=m+1;j++)
	{
		cout<<"\nb"<<i<<j<<":";
		cout<<b[i][j];

}
}
}

  
void elimination(int n,int m)
{
   int r,c,i,j,k,h,f,count1,count2,count3; 
   
   float temp,temp1,tmp;



f=0;
r=0;
c=0;



	
	while(1){
        
	  
		temp1=b[r][r];

	for(i=c;i<m+1;i++)
	{
        b[r][i]=(b[r][i])/temp1;
	}
     
	r++;


   	for(j=r;j<n;j++)
	{
	    tmp=b[j][c];
		for(k=c;k<m+1;k++)
		{
			
			b[j][k]=((-1)*tmp)*(b[r-1][k])+b[j][k];

		}
	}
    
	c++;
    
    
	for(h=0;h<m-1;h++)
	{
        if(b[n-1][h]==0&&b[n-1][m-1]==1)
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
		cout<<b[j][k]<<"\t";
	}
	cout<<"\n";
}

for(int z=1;z<=m;z++)
{
	a[z]=0;
}

a[m]=b[n-1][m];

count1=n-2;
count2=m;
count3=m;

while(count1>=0)
{   
    temp=0;
	while(count2>=1){
     temp+=b[count1][count2-1]*a[count2];

	 count2--;
	}
	count2=m;
a[count3-1]=b[count1][m]-temp;


    count1--;
	count3--;

	


}

for(i=1;i<m+1;i++)
{
	cout<<"\na"<<i-1<<": "<<a[i];


}

}

void poly_reg()
{
   int n,m,i,j;
	float X,r,Ymin,sum;
	  


     cout<<"\nEnter the order of the polynomial:";
	 cin>>m;
	 cout<<"\nNumber of data points:";
	 cin>>n;


	init(n,m);

	elimination(m+1,m+1);
	
   cout<<"\nEnter value of x to find the corresponding value of y:";
	   cin>>X;
  sum=0;
   for(i=1;i<=m+1;i++)
   {    
	  sum+=a[i]*pow(X,i-1);
   }

   cout<<"Y:"<<sum;

Ymin=0;
sr=0;
st=0;
for(i=0;i<n;i++)
   {    
	   sum=y[i];
	   for(j=1;j<=m+1;j++)
	   {
          sum-=a[j]*pow(x[i],j-1);
	   }

	   sr+=pow(sum,2);
	   Ymin+=y[i];
   }

Syx=sr/(n-(m+1));
Syx=sqrt(Syx);
sum=0;
for(j=0;j<n;j++)
{
	sum=(Ymin-y[j]);
	st+=pow(sum,2);

}

r=(st-sr)/st;
r=sqrt(r);

cout<<"\nSyx:"<<Syx<<"\nr:"<<r;
}




int main()
{
  poly_reg();

  return 0;
}







    



  
