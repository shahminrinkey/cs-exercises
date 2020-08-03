#include<iostream.h>
#include<math.h>

float *a=new float[];
float *b=new float[];

float deff1(int d,float y){

    float f,temp;
     int power;
	 f=0;
	for(int t=d;t>=0;t--){
		power=t;
     temp=a[t]*power;
	 b[t]=temp;
      power=power-1;
    f+=temp*pow(y,power);
	}
	return f;
}


float deff2(int d,float y)
{
	float f,temp;
	int power;
	f=0;
	for(int t=d;t>0;t--)
	{
		power=t-1;
		temp=b[t]*power;
		power=power-1;
		f+=temp*pow(y,power);
	}
	return f;
}

void init(int n)
{
   for(int i=n;i>=0;i--)
   {
	   cout<<"a"<<i<<":";
	   cin>>a[i];
   }
}
   

void newton()
{


	float x,x_prev,fx,f1x,f2x,Ea,Es;
	int n,count;

     cout<<"\nEnter the degree of the polynomial";
	 cin>>n;
	 init(n);

	 cout<<"\nXo:";
	 cin>>x;
	 cout<<"\nEs:";
	 cin>>Es;

	 x_prev=x;
	 count=1;
     fx=0;

	 while(1)
	 {

		 f1x=deff1(n,x);
		 f2x=deff2(n,x);

		 x=x-(f1x/f2x);

		 for(int j=n;j>=0;j--)
		 {
			 fx+=a[j]*pow(x,j);
		 }

		 Ea=((x-x_prev)/x)*100;

		 cout<<"\nIteration no."<<count<<"\tX:"<<x<<"\tFx:"<<fx<<"\tF'x:"<<f1x<<"\tF''x:"<<f2x<<"\tEa:"<<fabs(Ea);

		 if(fabs(Ea)<=Es)
            break;

		 x_prev=x;

		 fx=0;

		 count++;
	 }
}



int main()
{
	newton();
	return;
}
