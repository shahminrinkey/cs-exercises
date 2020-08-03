#include<stdio.h>
#include<math.h>
#define N 51
#define K 2
#define D 30
#define MAX 100000

float tx[N]={65,37,75.05,62.65,60.95,50.7,52.35,56.75,55.7,67.6,62.55,77.6,52.5,51.3,51.7,50.85,55.05,53.65,69.55,45.65,58.45,51.4,48.2,47.05,64.55,55.25,45.5,50.65,50.9,46.3,54.9,49.9,55.15,59.8,42.8,52.9,61.5,53,55.85,51.5,63.8,42.8,63,69.4,54.8,55.7,58.75,52.65,55.7,47.75,46.4};
float ty[N]={53.05,16.57,8.04,49.57,18.51,14.16,42.8,46.1,40.78,59.21,49.74,17.13,11.58,39.04,40.62,35.67,36.49,43.59,62.45,41.9,40.72,43.56,31.73,32.04,54.16,43.11,11.12,30.25,9.63,40.69,46.01,14.21,46.23,41.63,17.82,56.11,36.46,39.61,41.45,102.52,44.29,22.2,53.67,34.25,18.58,40.78,43.32,37.13,44.02,34.49,15.66};
int c[N];
float Cx[K],Cy[K];
float w1,w2,b,y;

void normalization(float a[])
{
    int i;
    float min,max;
    min=a[0];
    max=a[0];
    for(i=1;i<N;i++)
    {
        if(a[i]<min)
        {
            min=a[i];
        }
        if(a[i]>max)
        {
            max=a[i];
        }
    }
//printf("\min=%f max=%f",min,max);
    for(i=0;i<N;i++)
    {
        a[i]=(a[i]-min)/(max-min);
        printf("a[%d]=%f  ",i,a[i]);
    }

}

float normalization_2(float a[],float d)
{
    int i;
    float temp,min,max;
    min=a[0];
    max=a[0];
    for(i=1;i<N;i++)
    {
        if(a[i]<min)
        {
            min=a[i];
        }
        if(a[i]>max)
        {
            max=a[i];
        }
    }
//printf("\min=%f max=%f",min,max);

        temp=(d-min)/(max-min);
        return temp;

}


float distance(float x1,float x2,float y1,float y2)
{
    float temp,dist;
    temp=pow((x2-x1),2)+pow((y2-y1),2);
    dist=sqrt(temp);
    return dist;
}
void heuristic()
{
    float max,d;
    int i,j,k;

    Cx[0]=tx[0];
    Cy[0]=ty[0];

    for(k=1;k<K;k++)
    {
        max=0;
        for(i=0;i<N;i++)
        {
            d=0;
            for(j=0;j<k;j++)
            {
                d+=distance(tx[i],Cx[j],ty[i],Cy[j]);
            }
            if(d>max){
            max=d;
            Cx[k]=tx[i];
            Cy[k]=ty[i];
            }
        }
    }
}



void kmean()
{
    float d,cost=MAX,tempX,tempY,old_cost,min_dist,j;
    int i,count,k,iter=1;
  while(1)
  {
      printf("\nIter %d:",iter);
      j=0;
      old_cost=cost;
      for(i=0;i<N;i++)
      {
          min_dist=MAX;
          for(k=0;k<K;k++){
          d=distance(tx[i],Cx[k],ty[i],Cy[k]);
          if(d<min_dist){
            c[i]=k;
            min_dist=d;
          }
          }
          printf("\nmindist:%f",min_dist);
          printf("\nC[%d]=%d",i+1,c[i]+1);
          j+=pow(min_dist,2);
      }
//printf("\nj=%f",j);
      cost=j/N;


 printf("\ncost=%f",cost);

    if(fabs(cost-old_cost)<=0)
      break;
      for(k=0;k<K;k++)
      {
          count=0;
          tempX=0;
          tempY=0;

          for(i=0;i<N;i++)
          {
              if(c[i]==k){
              tempX+=tx[i];
              tempY+=ty[i];
              count++;
              }
          }
          Cx[k]=tempX/count;
          Cy[k]=tempY/count;
 //printf("\nCentroids:cluster%d(%f,%f)",k,Cx[k],Cy[k]);
      }
iter++;


      }


printf("\nIteration:%d",iter);
  printf("\nConverged!");
}

void perceptron()
{

int i,d;
    float a,sum;
    w1=0,w2=0;
    b=0;
    for(i=0;i<D;i++){
        if(c[i]==0)
        y=1;
        else
        y=-1;
        sum=(tx[i]*w1)+(ty[i]*w2);

    a=sum+b;
    if(a*y<=0)
    {
        w1=w1+y*tx[i];
        w2=w2+y*ty[i];
         b=b+y;
    }


}

}

void test()
{
    float a,sum;
    int i,d;
    printf("\nTest:\n");
    for(i=31;i<N;i++)
    {
         sum=(tx[i]*w1)+(ty[i]*w2);
         a=sum+b;
         printf("\nvalue:%f",a);
         if(a>0)
          printf("\nRegion:1");
        else
        printf("\nRegion:2");
    }
}
void classify()
{
    float a,sum,tem,rain;
    int i,d;
    printf("\nEnter Temperature and Rainfall:\n");
    scanf("%f%f",&tem,&rain);
    tem=normalization_2(tx,tem);
    rain=normalization_2(ty,rain);
         sum=(tem*w1)+(rain*w2);
         a=sum+b;
        if(a>0)
        printf("\nRegion:1");
        else
        printf("\nRegion:2");

}
int main()
{
    int i,k;
    printf("Train data X:\n");
    normalization(tx);
    printf("\nTrain data Y:\n");
    normalization(ty);
    heuristic();
   /* for(k=0;k<K;k++)
    {
     printf("\nCentroids:cluster%d(%f,%f)\n",k,Cx[k],Cy[k]);
    }*/
    kmean();

    for(i=0;i<N;i++)
    {
        printf("\ndata %d in group %d",i+1,c[i]+1);
    }
    for(k=0;k<K;k++)
    {
     printf("\nCentroids:cluster%d(%f,%f)\n",k+1,Cx[k],Cy[k]);
    }
    perceptron();
     printf("\nw1=%f w2=%f b=%f",w1,w2,b);
    test();
    classify();
    return 0;
}
