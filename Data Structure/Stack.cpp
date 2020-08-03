#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;


char data[10];
int top=-1;


void push(char item)
{
  data[++top]=item;

}

char pop()
{
    return data[top--];
}


int isfull()
{
    if(top==9)
    return 1;
    else
    return 0;
}

int isempty()
{
    if(top==-1)
    return 1;
    else
    return 0;
}



void showstck(int size)
{
    char x;
   for(int i=size-1;i>=0;i--){
   x=pop();
   cout<<"\n"<<x;
   }

}

void rev(char a[])
{

char x;
int l;
l=strlen(a);
cout<<"\nLength:"<<l;

for(int i=0;i<l;i++)
{
    push(a[i]);
}
cout<<"\nReverse:";

for(int j=l;j>=0;j--)
{
    x=pop();
    cout<<x;
}
}





int main()
{

    int e,f;
    char r[20];
    char y;
    char x[20];
    char post;

     cin>>r;
     rev(r);

     e=isempty();
     if(e==1)
     cout<<"\nempty stack";
     else
     cout<<"\nNot empty";

     f=isfull();
          if(f==1)
     cout<<"\nFull stack";
     else
     cout<<"\nNot full";




      return 0;
}























