#include<iostream.h>
#include<math.h>

void least_sqr()
{
	float *x=new float[];
	float *y=new float[];

	float sum_x,sum_y,sum_xy,sum_x2,xm,ym,ao,a1,st,sr,Syx,Sy,r2,r,x_main,y_main,temp1,temp2,temp3,temp4;
	int n,count;

	sum_x=0;
	sum_y=0;
	sum_xy=0;
	sum_x2=0;
	st=0;
	sr=0;

	cout<<"\nEnter number of data points:";
	cin>>n;

	for(int i=0;i<n;i++)
	{
		cout<<"X"<<i+1<<":";
		cin>>x[i];
		cout<<"Y"<<i+1<<":";
		cin>>y[i];
	}


	for(int j=0;j<n;j++)
	{
		sum_x=sum_x+x[j];
		sum_y=sum_y+y[j];
        sum_xy=sum_xy+(x[j]*y[j]);
		sum_x2=sum_x2+(x[j]*x[j]);

	}

	xm=sum_x/n;
	ym=sum_y/n;

	a1=(n*sum_xy-sum_x*sum_y)/(n*sum_x2-sum_x*sum_x);

	ao=ym-a1*xm;
    
	cout<<"\nao:"<<ao<<"\ta1:"<<a1;

	cout<<"\nEnter value of x to know the corresponding value of y:";
	cout<<"\nX:";
	cin>>x_main;

	y_main=ao+a1*x_main;

	cout<<"\nY:"<<y_main;

    for(int k=0;k<n;k++)
	{
	temp1=(ym-y[k]);
	st=st+pow(temp1,2);
     temp2=(y[k]-ao-a1*x[k]);
	 sr=sr+pow(temp2,2);

	}

	temp3=st/(n-1);
	Sy=sqrt(temp3);
    temp4=sr/(n-2);
	Syx=sqrt(temp4);

	cout<<"\nStandard error of estimate:"<<Syx;
	

	if(Syx<Sy)
		cout<<"\nImprovement.";
			else
			cout<<"\nNo improvement.";

	r2=(st-sr)/st;

	r=sqrt(r2);

	cout<<"\nCorrelation coeffecient:"<<r;

}


int main()
{
	least_sqr();
	return 0;
}


	













