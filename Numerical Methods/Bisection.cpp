#include<iostream.h>
#include<math.h>

void bisec()
{
	float *a=new float[];

	float xl,xu,Es,xr,Fxl,Fxr,Fxu,Ea,xr_prev;
    int count=0;
	int degree;

	cout<<"\nEnter the degree of the polynomial:";
	cin>>degree;

	while(count<=degree)
	{
		cout<<"Coeffecient"<<count<<":";
		cin>>a[count];
       count++;
	}

	cout<<"Enter value for xl,xu and Es";
	cin>>xl>>xu>>Es;
     Fxr=0;
	 Fxl=0;
	 Fxu=0;
    xr_prev=0;
	int iter=degree;
	while(1)
	{
        xr=(xl+xu)/2;
	    
for(int j=degree;j>=0;j--)
		{
			Fxr+=a[j]*pow(xr,j);
            Fxl+=a[j]*pow(xl,j);
			Fxu+=a[j]*pow(xu,j);
		}
         
        Ea=((xr-xr_prev)/xr)*100;
        
		cout<<"\nXl:"<<xl<<"\tf(xl):"<<Fxl<<"\tXu:"<<xu<<"\tXr:"<<xr<<"\tf(xr):"<<Fxr<<"\tEa:"<<Ea;
		if(fabs(Ea)<Es)
			break;
		if((Fxr*Fxl)<0)
			xu=xr;
		else
			xl=xr;

		xr_prev=xr;
		Fxl=0;
		Fxr=0;
		Fxu=0;
      iter--;
		
	}


}

int main()
{
	bisec();
	return 0;
}


