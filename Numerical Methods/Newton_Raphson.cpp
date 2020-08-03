#include<iostream.h>
#include<math.h>

float *a=new float[];

double deff(int d,double y){

    double f,temp;
     int power;
	 f=0;
	for(int t=d;t>=0;t--){
		power=t;
     temp=a[t]*power;
      power=power-1;

	  f+=temp*pow(y,power);

	}
	return f;

}
void new_raph()
{
	
	double Fx,Fx1,x,x_prev,Ea,Es;
	int count=1;
    int degree;
     

	cout<<"\nEnter the degree of the plynomial";
	cin>>degree;
     
	for(int i=degree;i>=0;i--){
	cout<<"Coeffecient"<<i<<":";
	cin>>a[i];
	}
    
	cout<<"\nInitial guess of root:";
	cin>>x;
    cout<<"\nEs:";
	cin>>Es;
     
	x_prev=x;
	Fx=0;

	while(1){

	for(int j=degree;j>=0;j--)
	{
		Fx+=a[j]*pow(x,j);
	}

	Fx1=deff(degree,x);
    
	x=x-(Fx/Fx1);

	Ea=((x-x_prev)/x)*100;

	cout<<"\nIteration No."<<count<<"\tXi:"<<x<<"\tF(xi):"<<Fx<<"\tEa:"<<Ea;

	if(fabs(Ea)<Es)
		break;

	x_prev=x;
	Fx=0;
   
	count++;
	}


}

int main()
{
	new_raph();
	return 0;
}










    