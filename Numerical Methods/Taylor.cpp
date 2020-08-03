#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float *f=new float[];
int fact(int a)
{
	if(a<=1)
		return 1;
	return a*fact(a-1);
}

void init(int m)
{
    
	for(int i=m;i>=0;i--)
	{  
		cout<<"\nCoeff:";
	   cin>>f[i];
	   }
}

float poly(int m,int d,float y)
{
	float fn=0;
	float temp;
	int power=d;
	for(int j=m;j>=m-d;j--)
	{  
       
      f[j]=f[j]*power;
	  power=power-1;
	  fn+=f[j]*pow(y,power);

	  
	}

	return fn;
}

	



void taylor()
{
     
	float fx,fx1,Xi,Xj,h,temp,fx_prev,Ea;
	int n,degree;
    int factor;

    printf("\nXi:");
    scanf("%f",&Xi);
	printf("\nXi+1:");
	scanf("%f",&Xj);
	printf("\nn:");
	scanf("%d",&n);

	init(n);
	h=Xj-Xi;

	
int count=1;
	  fx=0;
	  degree=n;
      for(int k=n;k>=0;k--)
	  {

	  fx+=f[k]*pow(Xi,k);
	  }

      fx_prev=fx;
          
      printf("\nOrder:%d\tf(x)=%f",count,fx);

	  
	  while(count<=n)
	  {
          
		 factor=fact(count);

		 temp=pow(h,count);

		 fx1=poly(n,degree,Xi);

		 fx+=fx1*(temp/factor);

         Ea=((fx-fx_prev)/fx)*100;

		 printf("\nOrder:%d\tf(x)=%f\tEa=%f",count,fx,Ea);

		 count++;

		 degree--;

		 fx_prev=fx;
	  }

}


int main()
{
	taylor();

	return 0;
}