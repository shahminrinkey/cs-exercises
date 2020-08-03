#include<iostream.h>


void mergesort(int a[],int f,int m,int l);

void part(int a[],int m,int n)
{
	int p;
     if(m<n)
	 {
	p=(m+n)/2;
     part(a,m,p);
	part(a,p+1,n);

     mergesort(a,m,p,n);
	 }

}


void mergesort(int a[],int f,int m,int l)
{

	int merge[100],i,q;
    i=f;
    q=m+1;
	int count=f;
	int c,d;
	
	

	while(i<=m&&q<=l)
	{
		if(a[i]<=a[q]){

		   merge[count]=a[i];
	   i++;
		}

		else
		{
			merge[count]=a[q];
			q++;
		}

		count++;


	}


	if(i>m)
	{
        c=q;
		while(c<=l)
		{
			merge[count++]=a[c++];
		}

	}

	else if(q>l)
	{
		d=i;
		while(d<=m)
		{
			merge[count++]=a[d++];
		}
	}

		for(int k=f;k<=l;k++)
		{
			a[k]=merge[k];
		}
	

}



  int main()
  {
	  int a[100],n;
       
	  cout<<"How many numbers?\n";
	  cin>>n;
	  cout<<"Enter numbers for sort:\n";

	  for(int i=0;i<n;i++)
	     cin>>a[i];

	  part(a,0,n-1);

	  cout<<"\nMerge sort list:\n";

	  for(int j=0;j<n;j++)
		  cout<<a[j]<<"\t";

	  return 0;
  }




	