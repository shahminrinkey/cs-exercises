#include<iostream>
#include<algorithm>


using namespace std;



float w[10];
float price[10];
float price2[10];


void quicksort(float a[],int left,int right)
{
    float temp;
    int i=left;
    int j=right;
    int pivot=right;
    if(left<right){
    while(i<j){
    while(a[i]>a[pivot])
    {
        i++;
    }

    while(a[j]<a[pivot])
    {
        j--;
    }
    if(i<j)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    }

    temp=a[pivot];
    a[pivot]=a[j];
    a[j]=temp;

    quicksort(a,left,j-1);
    quicksort(a,j,right);
    }

}


float find_wght(float p,int n)
{
    int i,wght;
    for(i=0;i<n;i++)
    {
        if(price[i]==p)
        {
            wght=w[i];
            break;
        }
    }

    return wght;

}

float knapsack(int W,int n)
{
  float wght;
    int i=0;
    float value;

    quicksort(price2,0,n-1);

   for(int j=0;j<n;j++)
   cout<<"\n"<<price2[j];

	while(W!=0)
	{
	    wght=find_wght(price2[i],n);
	    cout<<"\n"<<wght;
   if(wght<=W)
   {


	   value=value+(wght*price2[i]);

	   W=W-wght;
   }

   else{
	   value=value+(W*price2[i]);
	   W=0;
   }


   i++;
	}

	return value;

}


int main()
{
   int n,W;
   float maxValue;

	cout<<"\nEnter number of items:";
		cin>>n;



	for(int i=0;i<n;i++)
	{
		    cout<<"\nWeight:";
			cin>>w[i];
			cout<<"\nPrice:";
			cin>>price[i];
			price2[i]=price[i];
	}

	cout<<"\nKnapsack capacity:";
	cin>>W;

	maxValue=knapsack(W,n);

	cout<<"\nMaximumValue:"<<maxValue;

	return 0;
}

