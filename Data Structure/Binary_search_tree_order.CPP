# include <stdio.h>
#include<conio.h>
# include <stdlib.h>

typedef struct BST
{
    int data;
    struct BST *lchild,*rchild;
}node;

void insert(node *,int);
node *get();
void inorder(node *);
void preorder(node *);
void postorder(node *);

int main()
{
 int choice,item;
 char ans='N';
 int key;
 node *root;
 root=NULL;

 printf("nProgram For Binary Search Tree ");
 do
 {
   printf("n1.Create");
   printf("n2.Search");
   printf("n3.Recursive Traversals");
   printf("n4.Exit");
   printf("nEnter your choice :");
   scanf("%d",&choice);

   switch(choice)
   {
    case 1:
           do
             {

             printf("nEnter The Element ");
             scanf("%d",&item);
               if(root==NULL)
				   root=get();
			   else
                 insert(root,item);

             printf("nWant To enter More Elements?(y/n)");
             ans=getch();

             }while(ans=='y');

             break;


    case 2:

            if(root==NULL)
                printf("Tree Is Not Created");
            else
               {
               printf("nThe Inorder display : ");
               inorder(root);
               printf("nThe Preorder display : ");
               preorder(root);
               printf("nThe Postorder display : ");
               postorder(root);
               }

            break;
    }
 }while(choice!=2);

 return 0;
}
/*
  Get new Node
*/

/*
  This function is for creating a binary search tree
*/

node *get()
{
  node *temp;
 temp=(node *)malloc(sizeof(node));
 temp->lchild=NULL;
 temp->rchild=NULL;
  return temp;
}
void insert(node *root,int item)
{

 if(item< root->data)
     {
     if(root->lchild==NULL)
         root->lchild->data = item;
     else
         insert(root->lchild,item);
     }

  if(item> root->data)
     {
     if(root->rchild==NULL)
         root->rchild->data=item;
     else
         insert(root->rchild,item);
     }
}
/*
This function is for searching the node from
      binary Search Tree
*/

/*
This function displays the tree in inorder fashion
*/
void inorder(node *temp)
{
   if(temp!=NULL)
    {
    inorder(temp->lchild);
    printf("%d",temp->data);
    inorder(temp->rchild);
    }
}
/*
This function displays the tree in preorder fashion
*/
void preorder(node *temp)
{
 if(temp!=NULL)
    {
    printf("%d",temp->data);
    preorder(temp->lchild);
    preorder(temp->rchild);
    }
}

/*
This function displays the tree in postorder fashion
*/
void postorder(node *temp)
{
 if(temp!=NULL)
    {
    postorder(temp->lchild);
    postorder(temp->rchild);
    printf("%d",temp->data);
    }
}
