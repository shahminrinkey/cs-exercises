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
        int currindex=1;
        if(head==NULL||index==1)
        {
            newnode->data=value;
            newnode->next=head;
            head=newnode;

        }


        else
        {
            current=head;

            while(current->next!=NULL&&currindex<index)
            {

                current=current->next;
                 currindex++;

            }

            newnode->data=value;
            newnode->next=current->next;
            current->next=newnode;

        }
    }

    int find(int value)
    {
        node *current=new node;
        int found=0;
        int count=1;
        current=head;
        while(current->next!=NULL)
        {
            if(current->data==value)
            {
                found=1;
                break;
            }
            current=current->next;
            count++;
        }

        if(found==0)
        return -1;

        else
        return count;
    }

    void del(int value)
    {
        node *current=new node;
        node *prev=new node;
        prev=NULL;
        current=head;

        while(current->data!=value&&current!=NULL)
        {
           prev=current;
         current=current->next;

        }
        if(current!=NULL){
            if(prev!=NULL){
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

    int sawp(int value)
    {
        node *current=new node;
        node *prev=new node;
        node *nextnode=new node;
        prev=NULL;
       current=head;
       nextnode=current->next;

       while(current->next!=NULL)
       {
           if(current->data==value)
           {
               prev->next=current->next;
               nextnode=current;
               current=current->next;
               break;
           }
           prev=current;
        current=current->next;
           nextnode=current->next;

       }

       return current->data;



    }
void sort()
    {
        node *current=new node;
        node *prev=new node;
        node *nextnode=new node;
        prev=NULL;
        current=head;
        nextnode=current->next;
        while(current->next!=NULL)
        {
            if(current->data>current->next->data)
            {
                prev->next=current->next;
                nextnode=current;
                current=current->next;
            }
            prev=current;
            current=current->next;
            nextnode=current->next;


        }
    }



    void destroy()
    {
        node *current=new node;
        node *nextNode=new node;

        current=head;

        while(current->next!=NULL)
        {
            nextNode=current->next;
            delete current;
            current=nextNode;


        }
    }
};


    int main()
    {
        node ob;
        int f,r;
        ob.insert(18,1);
        ob.insert(65,2);
        ob.insert(15,3);
        ob.insert(20,4);
        ob.insert(30,5);
        ob.display();
        f=ob.find(15);
        if(f==-1)
        cout<<"\nValue not in the list";
        else
        cout<<"\n"<<10<<"found in the location "<<f;
        ob.insert(60,3);
        cout<<"\n";
        ob.display();
        ob.del(30);
        cout<<"\n";
        ob.display();
        ob.insert(40,3);

        cout<<"\n";
        ob.display();
r=ob.sawp(65);
        cout<<"\nAfter sawpping:"<<r;

        cout<<"\n";


    //ob.sort();
    ob.display();


        ob.destroy();




        return 0;



    }














