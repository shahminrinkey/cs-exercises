#include<iostream.h>
#include<math.h>

void secant()
{    
     
	float *a=new float[];
	double Fxo,Fx,Fx1,xo,x,x1,x_prev,Ea,Es;

	int degree,count;

cout<<"\nEnter the degree of the polynomial:";
cin>>degree;

for(int i=degree;i>=0;i--)
{
	cout<<"\nCoeffecient"<<i<<":";
	cin>>a[i];
}

cout<<"\nX-1:";
cin>>xo;
cout<<"\nX:";
cin>>x;
cout<<"\nEs:";
cin>>Es;

x_prev=0;

Fxo=0;
Fx=0;
Fx1=0;
count=1;
while(1){

	for(int j=degree;j>=0;j--)
	{
		Fxo+=a[j]*pow(xo,j);
		Fx+=a[j]*pow(x,j);
	}

	x1=x-(Fx*(xo-x)/(Fxo-Fx));

     for(int h=degree;h>=0;h--)
	 {
		 Fx1+=a[j]*pow(x1,h);

	 }

	 Ea=((x1-x_prev)/x1)*100;

	 cout<<"\nIteration No."<<count<<"\tX-1:"<<xo<<"\tX:"<<x<<"\tX+1:"<<x1<<"\tF(x+1):"<<Fx1<<"\tEa:"<<Ea;

	 if(fabs(Ea)<Es)
		 break;
      
	 xo=x;
     x=x1;
     x_prev=x1;

	 Fxo=0;
	 Fx=0;
	 Fx1=0;

	 count++;

}

}

int main()
{
	secant();
	return 0;
}





