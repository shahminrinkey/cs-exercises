#include<iostream.h>
#include<math.h>

 

void gold_srch()
{
   float xl,xu,x1,x2,x_opt,x1_prev,x2_prev,d,fx1,fx2,fxl,fxu,fx_opt,Ea,Es;
   int n,count;
   float r=0.618034;
    
   float *a=new float[];
   cout<<"\nEnter degree of the polynomial:";
   cin>>n;
   for(int i=n;i>=0;i--)
   {
	   cout<<"a"<<i<<":";
	   cin>>a[i];
   }
   cout<<"\nEnter value:\n";
   cout<<"Xl:";
   cin>>xl;
   cout<<"Xu:";
   cin>>xu;
   cout<<"Es:";
   cin>>Es;

   fx1=0;
   fx2=0;
   fxu=0;
   fxl=0;
    count=1;
   while(1){

   d=r*(xu-xl);
   if(count==1){
   x1=xl+d;
   x1_prev=x1;
   x2=xu-d;
   x2_prev=x2;
   }
   else
   {
	   if(x_opt==x1_prev)
	   {
		   x1=xl+d;
		   x1_prev=x1;
	   }
	   else
	   {
		   x2=xu-d;
		   x2_prev=x2;
	   }
   }


   for(int k=n;k>=0;k--)
   {
	   fxl+=a[k]*pow(xl,k);
	   fxu+=a[k]*pow(xu,k);
	   fx1+=a[k]*pow(x1,k);
	   fx2+=a[k]*pow(x2,k);
   }

   if(fx1>fx2){
	   x_opt=x1;
       fx_opt=fx1;
   }
	   else if(fx2>fx1){
	   x_opt=x2;
	   fx_opt=fx2;
	   }


   Ea=((1-r)*((xu-xl)/x_opt))*100;

   cout<<"\nIteration No."<<count<<"\tXl:"<<xl<<"\tf(xl):"<<fxl<<"\tXu:"<<xu<<"\tf(xu):"<<fxu<<"\tXopt:"<<x_opt<<"\tf(Xopt):"<<fx_opt<<"\tEa:"<<fabs(Ea);
   
   

   if(fx1>fx2){
	   xl=x2;
	   x2=x1;
   }
   else
   {
	   xu=x1;
	   x1=x2;
   }


	 

fx1=0;
fx2=0;
fxl=0;
fxu=0;

   if(fabs(Ea)<=Es)
      break;


count++; 

}
}

int main()
{
	gold_srch();
	return 0;
}


          
   







    




