#include<iostream>
#include<stdio.h>
using namespace std;

struct tree
{
    
	struct tree *left,*right;
	int data;
	int height=1;

};

int hght(tree **root)
{
	if((*root)==NULL)
		return NULL;
	else
		return (*root)->height;
}

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int get_balance(tree **root)
{
	if((*root)==NULL)
		return NULL;
	else
		return (hght(&(*root)->left)-hght(&(*root)->right));
}

int compare(int data1,int data2)
{
	if(data1>data2)
		return 1;
	else if(data1==data2)
		return 0;
	else
		return -1;
}



tree* left_rotate(tree **root)
{

	tree **P;
	(*P)=new tree;

	*P=(*root)->right;

	(*root)->right=(*P)->left;
	(*P)->left=(*root);
	(*P)=(*root);

	(*root)->height=max(hght(&(*root)->left)-hght(&(*root)->right))+1;
     (*P)->height=max(hght(&(*P)->left)-hght(&(*P)->right))+1;

	 return *P
}


tree* right_rotate(tree **root)
{

	tree **P;
	(*P)=new tree;

	*P=(*root)->left;

	(*root)->left=(*P)->right;
	(*P)->right=(*root);
	(*P)=(*root);

	(*root)->height=max(hght(&(*root)->left)-hght(&(*root)->right))+1;
     (*P)->height=max(hght(&(*P)->left)-hght(&(*P)->right))+1;

	 return *P;
}




























tree* insert(tree **root,int item)
{
    int balance;
	if((*root)==NULL){
        (*root) = new tree;
        (*root)->left = (*root)->right = NULL;
        (*root)->data = item;
		(*root)->height=1;
		
        	}
    
    else{
        if(item < (*root)->data)
        {
            (*root)->left=insert(&(*root)->left,item);
        }
        
        else if(item > (*root)->data)
        {
            (*root)->right=insert(&(*root)->right,item);
        }


        }

	(*root)->height=max(hght(&(*root)->left),hght(&(*root)->right))+1;

      balance=get_balance(&(*root));

	  if(balance>1&&compare(item,&(*root)->left->key)<0)
		  return right_rotate(&(*root));

        if(balance<-1&&compare(item,&(*root)->right->key)>0)
		  return left_rotate(&(*root));

        if(balance>1&&compare(item,&(*root)->left->key)>0)
		{
		  (*root)->left=left_rotate(&(*root)->left);
		  return right_rotate(&(*root));
		}

      if(balance<-1&&compare(item,&(*root)->right->key)<0)
		{
		  (*root)->right=right_rotate(&(*root)->left);
		  return left_rotate(&(*root));
		}




  return *root;
		


}


  tree* find(tree **root,int item)
 {
    if((*root)==NULL){
       
        return NULL;
        	}
    
    
        else if(item < (*root)->data)
        {
            return find(&(*root)->left,item);
        }
        
        else if(item > (*root)->data)
        {
            return find(&(*root)->right,item);
        }

		else

			return *root;
        
    }



  tree* findmax(tree **root)
 {
    if((*root)==NULL)
		return NULL;
	if((*root)->right==NULL)
		return *root;
	return findmax(&(*root)->right);
       
 }

 tree* findmin(tree **root)
 {
    if((*root)==NULL)
		return NULL;
	if((*root)->left==NULL)
		return *root;
	return findmin(&(*root)->left);
       
 }

void preorder(tree **root)
{
    if((*root)!=NULL){
        cout<<(*root)->data<<endl;
        preorder(&(*root)->left);
        preorder(&(*root)->right);
    }
}
void postorder(tree **root)
{
    if((*root)!=NULL){
        
        postorder(&(*root)->left);
        postorder(&(*root)->right);
        cout<<(*root)->data<<endl;
    }
}

void inorder(tree **root)
{
    if((*root)!=NULL){
          inorder(&(*root)->left);
        cout<<(*root)->data<<endl;
        
        inorder(&(*root)->right);
    }
}


void del(tree **root,int item)
{
    tree *f,*fmin;
	int temp;
	f=find(&(*root),item);
	if(f==NULL)
		cout<<"\nValue not found";
	else
	{
		if(f->left==NULL&&f->right==NULL)
			delete f;
		
		
else if(f->left!=NULL&&f->right==NULL){
	    
	f->data=f->left->data;     

         f->left=NULL;
		delete f->left;
		
	}
			
	else if(f->left==NULL&&f->right!=NULL)
		{
		f->data=f->right->data;
	
		f->right=NULL;
		delete f->right;
			
	}


	else if(f->left!=NULL&&f->right!=NULL)
		{
			
			fmin=findmin(&f->right);
			temp=f->data;
			f->data=fmin->data;
			fmin->data=temp;
             if(fmin->right!=NULL)
			{
                temp=fmin->data;
			fmin->data=fmin->right->data;
			fmin->data=temp;

			delete fmin->right;
			}

            else 
			
			delete fmin;
	}
	}


}




	




int main()
{
     tree *f,*fmax;
	tree *node=NULL;
    insert(&node,5);
	insert(&node,7);
	insert(&node,1);
	insert(&node,2);
	insert(&node,4);
    
	preorder(&node);
	postorder(&node);
	inorder(&node);

	f=find(&node,1);
     fmax=findmax(&node);
	cout<<f->data;
	cout<<fmax->data;

	cout<<"\ndelete function";

	del(&node,2);

    preorder(&node);


    
	return 0;
    
}