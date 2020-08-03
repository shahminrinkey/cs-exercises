#include <stdio.h>
#include <stdlib.h>
#include<math.h>

float w[3][5][20],delta[3][5],e,a[3][5],z[3][5];
float x[4]={5.1,3.5,1.4,0.2};
float y[3]={1,0,0};
int l,n;
float learn=0.01;


void init()
{

    int i,j,k;
    for(i=0;i<4;i++)
    {
        a[0][i]=x[i];
    }
    for(i=1;i<3;i++)
    {
        if(i==1){n=5;l=4;}
        else if(i==2){n=3;l=5;}
        for(j=0;j<n;j++)
        {
            for(k=0;k<l;k++)
            {
                w[i][j][k]=0.01;
            }

        }
    }
}

void forward_feed()
{
 int i,j,k;
      for(i=1;i<3;i++)
    {
         if(i==1){n=5;l=4;}
        else if(i==2){n=3;l=5;}
        for(j=0;j<n;j++)
        {
            z[i][j]=0;
            for(k=0;k<l;k++)
            {
                z[i][j]+=w[i][j][k]*a[i-1][k];
            }
            a[i][j]=1/(1+exp(-z[i][j]));
            printf("\nforward a[%d][%d]=%f/t z[%d][%d]=%f",i,j,a[i][j],i,j,z[i][j]);
        }
    }
}

void backprop()
{
    int i,j,k;
    float temp;
   //output layer
   for(i=0;i<3;i++)
   {
       delta[2][i]=(a[2][i]-y[i])*a[2][i]*(1-a[2][i]);
   }
   //hidden layer

       for(j=0;j<5;j++)
       {   temp=0;
           for(k=0;k<3;k++)
           {
               temp+=w[2][j][k]*delta[2][k];
           }
        delta[1][j]=temp*a[1][j]*(1-a[1][j]);
       }


}

void update_weight()
{
    int j,k;

//hidden layer
        for(j=0;j<4;j++)
        {
            for(k=0;k<5;k++)
            {
                w[1][j][k]=w[1][j][k]-(learn*delta[1][k]*a[0][j]);
            }
        }
//output layer
        for(j=0;j<5;j++)
        {
            for(k=0;k<3;k++)
            {
                w[2][j][k]=w[2][j][k]-(learn*delta[2][k]*a[1][j]);
            }
        }

}

float error()
{
    int i;
    float sum,e;
    for(i=0;i<3;i++)
   {
       sum+=pow((a[2][i]-y[i]),2);
   }
   e=sum/2;
   return e;

}
int main()
{
    int complete=0;
    float e;
   //training
  init();
  while(1)

  {

forward_feed();
backprop();
e=error();
if(e<0.2){
break;
}
printf("\nError:%f",e);

update_weight();

}
}
