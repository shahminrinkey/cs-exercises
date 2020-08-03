#include<iostream>

using namespace std;

int MAX_SIZE=10;
int queue[10];
int front=-1;
int rear=-1;

void Enqueue(int item)
{

  queue[++rear]=item;
  if(rear==MAX_SIZE)
  {
      rear=0;
  }

}

int Dqueue()
{
   if(front=MAX_SIZE)
   {
       front=0;
   }
    return queue[++front];
}

int isfull()
{
    if(rear==MAX_SIZE)
    return 1;
    else
    return 0;
}

int isempty()
{
    if(front==rear)
    return 1;
    else
    return 0;

}

int main()
{
    int f,e,d;
     e=isempty();
    if(e==1)
    cout<<"\nQueue is empty";
    else
    cout<<"\nNot empty";


    Enqueue(5);
    Enqueue(8);
    Enqueue(4);
    Enqueue(6);
    Enqueue(9);
    Enqueue(2);
    Enqueue(60);
    Enqueue(70);
    Enqueue(40);
    Enqueue(74);

    f=isfull();

    if(f==1)
    cout<<"\nQueue is full";
    else
    cout<<"\nNot full";

    cout<<"\nShow Queue:\n";

    for(int i=0;i<rear;i++)
    {
        cout<<queue[i]<<"\t";
    }



     d=Dqueue();
     cout<<"\n"<<d<<" has been deleted from queue";


      cout<<"\nShow Queue:\n";
     for(int j=0;queue[j]!=NULL;j++)
    {
        cout<<queue[j]<<"\t";
    }

    return 0;
}






















