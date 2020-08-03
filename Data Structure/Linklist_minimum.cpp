#include<iostream>

using namespace std;

class node
{


public:
node *head,*next;
int data;

node()
{
    head=NULL;
    next=NULL;
    data=0;
}

void insert(int value,int index)
{
    node *current=new node;
    node *newnode=new node;
    int currindex=0;

    if(head==NULL||index==0)
    {
        newnode->data=value;
        newnode->next=head;
        head=newnode;
    }

    else{

    current=head;

    while(current->next!=NULL&&currindex<index)
    {
        current=current->next;
        currindex++;
    }

    if(current==NULL&&index>0)
    {
        cout<<"\ninvalid index";
    }
    else
    {
        newnode->data=value;
        newnode->next=current->next;
        current->next=newnode;
    }



    }


}

void del(int value)
{

    node *current=new node;

    node *prev=new node;
    prev=NULL;
    current=head;


    while(current!=NULL&&current->data!=value)
    {
        if(current->data==value)
        {
            break;

        }
        prev=current;
        current=current->next;
    }

    if(current!=NULL)
    {
        if(prev!=NULL)
        {
            prev->next=current->next;

            delete current;
        }

        else
        {
            head=current->next;

            delete current;

        }
    }

    else
    cout<<"\nValue not found";
}


int search(int value)
{
    node *current=new node;
    int found=0;
    int count=0;

    current=head;

    while(current->next!=NULL)
    {
        count++;

        if(current->data==value)
        {
            found=1;
            break;
        }
        current=current->next;
    }

    if(found==0)
    return -1;

    else
    return count;
}


int swap(int value)
{
    node *current=new node;

    node *prev=new node;

    node *nextnode=new node;

    prev=NULL;
    current=head;
    nextnode=current->next;

    while(nextnode!=NULL&&current->data!=value)
    {
        if(current->data==value)
        {
            break;
        }
        prev=current;
        current=current->next;
        nextnode=current->next;
    }

    if(nextnode!=NULL&&current->data==value)
    {
        if(prev!=NULL)
        {
            prev->next=nextnode;
            nextnode=current;
            current=current->next;
        }

        else
        {
            head=nextnode;
            nextnode=current;
            current=current->next;

        }

        return current->data;
    }

    else

   return -1;

}

node* min()
{
    node *current=new node;

    node *prev=new node;

    node *nextnode=new node;

    node *min=new node;

    prev=NULL;
    current=head;
    nextnode=current->next;

    while(nextnode->next!=NULL)
    {
        if(current->data>nextnode->data)
        {
            if(prev!=NULL)
            {
                prev->next=nextnode;
                nextnode=current;
                current=current->next;
                min=current;
            }

            else
            {
                nextnode=current;
                head=nextnode;
                current=current->next;
                min=current;

            }
        }

        prev=current;
        current=current->next;
        nextnode=current->next;
    }
    return min;
}

void display()
{
    node *current=new node;

    current=head;

    while(current!=NULL)
    {
        cout<<"\n"<<current->data;
        current=current->next;
    }
}

  void destroy()
  {
      node *current=new node;
      node *nextnode=new node;

      current=head;
      nextnode=current->next;

      while(current!=NULL)
      {
          delete current;
          current=nextnode;
          nextnode=current->next;
      }


  }
};


int main()
{
    node ob,*p;
    int v,i,f,s;
    char ch;
    cout<<"\nWant to enter value?y/n";
    cin>>ch;
    while(ch!='n')
    {
        if(ch=='n')
        break;

        cin>>v>>i;
        ob.insert(v,i);
        cout<<"\nWant to enter value?y\n";
    cin>>ch;

    }
    ob.display();
    f=ob.search(5);
    if(f==-1)
    cout<<"\nNot found";
    else
    cout<<"\nLocation:"<<f;
    ob.del(6);
    s=ob.swap(7);
    cout<<s;

    p=ob.min();
    cout<<"\n"<<p->data;

    ob.destroy();

    return 0;


}

















































