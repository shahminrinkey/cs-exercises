
#include<iostream.h>


int main()
{
    int n,p;
	cin>>n;
	p=n;
	float *a=new float[n+1];
	for(int i=0;i<n+1;i++)
	{
		cin>>a[i];
	}
	for(int j=0;j<n+1;j++)
	{
		if(p==n||a[j]<0)
			cout<<a[j]<<"x^"<<p;
		else
		{
			cout<<"+"<<a[j]<<"x^"<<p;
		}
		p--;
	}
    return 0;
}
















