#include<iostream.h>
#include<math.h>

int fact(int a)
{
	if(a<=1)
		return 1;
	return a*fact(a-1);
}

  void error()
{
	int n,maxit,factor;

	float x,e,Ea,Et,Es,true_error,true_value,temp1,e_prev;

	cout<<"\nX:";
	cin>>x;
	cout<<"\nNumber of significant figures:";
	cin>>n;
	cout<<"\nMaximum iteration:";
	cin>>maxit;

	true_value=pow(2.7183,(-x));
	Es=true_value*pow(10,(2-n));
   cout<<"\nEs:"<<Es;
    int count=0;
     
	e=1;
	true_error=true_value-e;
    
	Et=(true_error/true_value);
	

	cout<<"\nIteration:"<<count<<"\tTrue relative error:"<<Et;
    
	e_prev=1;

	while(count<=maxit)
	{  
		count++;
       if(count%2!=0)
	   {
		   x=(-1)*x;
	   }
		temp1=pow(x,count);

		factor=fact(count);
        
		

		e=e_prev+(temp1/factor);

	    true_error=true_value-e;
		Et=(true_error/true_value);

		Ea=((e-e_prev)/e)*100;

		cout<<"\nIteration:"<<count<<"\tTrue relative error:"<<Et<<"\tApproximate relative error:"<<Ea;

		e_prev=e;

		if(fabs(Ea)<Es||fabs(Et)<Es)
			break;


	}
}


int main()
{
	error();

	return 0;
}


