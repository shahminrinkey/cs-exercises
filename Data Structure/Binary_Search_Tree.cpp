#include<iostream.h>


class tree{
public:
 int x[20],pos,size;
 
 tree()
 {
	 
     size=20;
	 for(int i=0;i<size;i++)
	 {
		 x[i]=-1;

	 }

 }


 void insert(int pos,int item)
 {
	 if(x[pos]==-1)
	 {
		 x[pos]=item;
	 }

	 else if(x[pos]>item)
		 insert(2*pos,item);
	 else if(x[pos]<item)
		  insert(2*pos+1,item);
	
 }



 int Find(int pos,int item)
 {
	 if(x[pos]==-1)
		 return 0;
	 else if(x[pos]>item)
		 return Find(2*pos,item);
	 else if(x[pos]<item)
		 return Find(2*pos+1,item);
	 else
		 return pos;
 }

 
 int Findmax(int pos)
 {
	 int p;
	 do{
         p=pos; 
		 pos=2*pos+1;
		 if(x[pos]==-1)
			 break;
		
	 }while(1);
        return x[p];

	
 }

int Findmin(int pos)
 {
	 int p;
	 do{
         p=pos; 
		 pos=2*pos;
		 if(x[pos]==-1)
			 break;
		
	 }while(1);
        return x[p];

	
 }

void show(int pos)
{
	if(x[pos]!=-1){
cout<<x[pos]<<"\t";
show(2*pos);
show(2*pos+1);
	}
}



};


int main()

{
	tree ob;

	int p;

	ob.insert(1,5);
	ob.insert(1,2);
	ob.insert(1,7);
	ob.insert(1,3);

	p=ob.Find(1,3);
     
	//if(p!=0)
		cout<<p;
		
		p=ob.Findmax(1);
		cout<<p;

p=ob.Findmin(1);
		cout<<p;


		ob.show(1);
	return 0;
}