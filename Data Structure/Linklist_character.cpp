#include<iostream>
#include<string.h>

using namespace std;

class node
{
    node *head,*next;

    char name[20];float cgpa;int id;

    public:

    node()
    {
        head=NULL;
        next=NULL;
        strcpy(name,"Adam");
        cgpa=0.0;
        id=0;

    }

    void insert(char n[20],float c,int i,int index)
    {
        node *current=new node;
        node *newnode=new node;
        int currindex=1;
        current=head;
        newnode->cgpa=c;
        newnode->id=i;
        strcpy(newnode->name,n);
    while(current->next!=NULL&&currindex<index)
    {
        current=current->next;
        currindex++;
    }


        if(index>1&&current==NULL)
        cout<<"\nInvalid index";
        else{
        if(head==NULL||index==1)
        {
            newnode->next=head;
            head=newnode;
        }

        else{

               newnode->next=current->next;
               current->next=newnode;

        }
        }
    }

    int find(char stdn[20])
    {
        node *current=new node;
        int count=0;
        int found=0;

        current=head;

        while(current->next!=NULL)
        {
              count++;
            if(strcmp(current->name,stdn)==0)
            {
                found=1;
                break;
            }
            current=current->next;

        }

        if(found==0)
            return -1;
            else{
                cout<<"\nName:"<<current->name<<"\tCGPA:"<<current->cgpa<<"\tID:"<<current->id;
            return count;
            }
    }

    void del(char n[20])
    {
        node *current=new node;
        node *prev=new node;
        current=head;
        prev=NULL;
        while(current!=NULL)
        {

            if(strcmp(current->name,n)==0)
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
            head=current->next;
            delete current;
        }
        else
        cout<<"\nNot found";


    }

    void display()
    {
        node *current=new node;

        current=head;

        while(current!=NULL)
        {
            cout<<"\nName:"<<current->name<<"\tCGPA:"<<current->cgpa<<"\tID:"<<current->id;
            current=current->next;
        }
    }

    void destroy()
    {
        node *current=new node;

        node *nextnode=new node;
        current=head;

        while(current!=NULL)
        {
            nextnode=current->next;
            delete current;
            current=nextnode;

        }

    }

};


int main()
{
    node ob;
    int f;

    ob.insert("Sabrina",3.53,031,1);
    ob.insert("Rinkey",3.59,023,2);
    ob.insert("Mahinur",3.03,025,3);
    ob.insert("Jack",3.50,030,4);
    ob.display();

    f=ob.find("Rinkey");
    if(f==-1)
    cout<<"\nNot found";
    else
    cout<<"\nLocation:"<<f;
    ob.del("Mahinur");
    ob.display();
    ob.destroy();

    return 0;
}


















