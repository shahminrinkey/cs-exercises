#include<stdio.h>
#include<iostream>

using namespace std;

int size=20;
int a[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
class array
{

    public:

    void insert(int pos,int val)
    {
        for(int i=size-1;i>=pos;i--)
        {
            a[i+1]=a[i];
        }
        a[pos]=val;
        cout<<"\n"<<val<<" inserted in position "<<pos;
        size++;
    }

    void find(int val)
    {
       int found=0;
       int pos;
        for(int j=0;j<size;j++)
        {
            if(a[j]==val)
            pos=j;
            found=1;
        }

        if(found==1)
        cout<<"\n"<<val<<" found in location "<<pos;
        else
        cout<<"\nNot found";
    }

    void del(int pos)
    {
        size--;
        for(int k=pos;k<size;k++)
        {
            a[k]=a[k+1];
        }
        cout<<"\nValue deleted from position "<<pos;
    }

    void display()
    {
        cout<<"\n";
        for(int n=0;n<size;n++)
        {
            cout<<a[n]<<"\t";
        }
    }
};

    int main()
    {
        array ob,x;
        ob.insert(2,5);
        ob.insert(4,10);
        ob.find(3);
        ob.del(7);
        ob.display();

        return 0;
    }























