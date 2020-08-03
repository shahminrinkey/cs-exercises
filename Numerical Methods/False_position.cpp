#include<iostream.h>
#include<math.h>

void false_pos()
{
	float *a=new float[];

	double xl,xu,Es,xr,Fxl,Fxr,Fxu,Ea,xr_prev;
    int count=0;
	int degree;
	int i=1;

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
        
	    
for(int j=degree;j>=0;j--)
		{
			
            Fxl+=a[j]*pow(xl,j);
			Fxu+=a[j]*pow(xu,j);
		}
        
xr=xu-((Fxu*(xl-xu))/(Fxl-Fxu));        

        Ea=((xr-xr_prev)/xr)*100;
		for(int k=degree;k>=0;k--){
        Fxr+=a[k]*pow(xr,k);
		}

		cout<<"\nIteration No"<<i<<"\tXl:"<<xl<<"\tf(xl):"<<Fxl<<"\tXu:"<<xu<<"\tXr:"<<xr<<"\tf(xr):"<<Fxr<<"\tEa:"<<Ea;
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
         i++;
		
	}


}

int main()
{
	false_pos();
	return 0;
}