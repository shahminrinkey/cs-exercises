#include<iostream>

using namespace std;

void insort(int a[],int size)
{
    int j,i,value;

    for(i=1;i<size;i++)
    {
       value=a[i];
       j=i-1;

       while(j>=0&&a[j]>value)
       {
           a[j+1]=a[j];
           j--;
       }

       a[j+1]=value;
    }
}


int main()
{
    int x[10]={4,5,1,3,10,7,14,2,8,9};

    insort(x,10);

    cout<<"Sorted list:\n";
    for(int k=0;k<10;k++)
    {
        cout<<x[k]<<"\t";
    }

    return 0;
}
