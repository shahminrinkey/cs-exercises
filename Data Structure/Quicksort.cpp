#include<iostream>

using namespace std;


int data[10]={4,5,7,3,8,1,9,10,18,2};
int n=10;


void quicksort(int a[],int left,int right)
{
    int temp;
    int i=left;
    int j=right;
    int pivot=right;
    if(left<right){
    while(i<j){
    while(a[i]<a[pivot])
    {
        i++;
    }

    while(a[j]>a[pivot])
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
    quicksort(a,j+1,right);
    }

}

int main()
{
  quicksort(data,0,n-1);

  for(int k=0;k<n;k++)
  {
      cout<<data[k]<<"\t";
  }
  return 0;

}
