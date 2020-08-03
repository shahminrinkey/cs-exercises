#include<iostream>

using namespace std;

class list
{
    public:

    int data;
    list *next;
    list()
    {
        data=0;
        next=NULL;
    }

    void insert(list *node,int val)
    {
        list *p;
        p=new list;

        p->data=val;
        p->next=node;
        node=p;
        node->next=NULL;

    }

void print(list *node)
{
    while(node!=NULL)
{
    cout<<node->data;
    node=node->next;
}
}

};


int main()
{
    list *link,ob;

    ob.insert(link,5);
        ob.insert(link,6);
            ob.insert(link,8);


    ob.print(link);

    return 0;


}
