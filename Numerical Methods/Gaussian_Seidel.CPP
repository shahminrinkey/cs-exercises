#include<iostream.h>

float a[10][10];
float b[10];

void init(int n)
{
	cout<<"\nEnter the coeffecients:\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<"a"<<i+1<<j+1<<":";
			cin>>a[i][j];
		}
        
		cout<<"b"<<i+1<<":";
		cin>>b[i];

		cout<<"\n";
	}

}

void Seidel()
{
    int n;
	int count;
	float temp;
   float x[10],x_prev[10],Ex[10];

    cout<<"\nEnter number of unknowns:";
    cin>>n;
   init(n);
    
   
   cout<<"\nEnter initial guesses:";
   for(int i=0;i<n;i++){
   cin>>x[i];
   }


   for(int j=0;j<n;j++)
   {
	   x_prev[j]=x[j];
   }
   
   count=1;
   while(count<=3){
   for(int k=0;k<n;k++){

	   temp=b[k];
	   for(int l=0;l<n;l++){
	    
		   if(l==k)
			   l=l+1;
	   temp-=(a[k][l]*x[l]);
	   }

	   x[k]=temp/(a[k][k]);
		   

          
	   Ex[k]=((x[k]-x_prev[k])/x[k])*100;

	 cout<<"\nX"<<k+1<<":"<<x[k];
		 cout<<"\nEx"<<k+1<<Ex[k];
		 

		 for(int h=0;h<n;h++){
	   x_prev[h]=x[h];
		 }

	 }

       count++;

  

}

}




int main()
{
	Seidel();

	return 0;
}




	
