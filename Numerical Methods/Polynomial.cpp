#include<iostream.h>
#include<math.h>

void polynomial()
{
	int n;

cout<<"\nThe degree of the polynomial is:";
cin>>n;
float x;
float *a=new float[n];
float fx=0;
float temp;

cout<<"x:";
cin>>x;
for(int i=n;i>=0;i--)
{
   cout<<"a"<<i<<":";
   cin>>a[i];

   temp=pow(x,i);

   fx+=(a[i]*temp);
}

cout<<"\nf(x)="<<fx;

}

int main()
{
	polynomial();

	return 0;
}






