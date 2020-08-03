#include<stdio.h>
#include<math.h>
#define N 7
#define K 2
#define MAX 100000

float tx[7]={1.0,1.5,3.0,5.0,3.5,4.5,3.5};
float ty[7]={1.0,2.0,4.0,7.0,5.0,5.0,4.5};
int c[N];
float Cx[K],Cy[K];

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
    float d,cost=MAX,tempX,tempY,old_cost,min_dist;
    int i,j=0,count,k,iter=1;
  while(1)
  {
      printf("\nIter %d:",iter);
      old_cost=cost;
      for(i=0;i<N;i++)
      {
          min_dist=MAX;
          for(k=0;k<K;k++){
          d=distance(tx[i],Cx[k],ty[i],Cy[k]);
          if(d<min_dist){
            c[i]=k;
            d=min_dist;
          }
          }
          printf("\nC[%d]=%d",i,c[i]);
          j+=min_dist;
      }

      cost=j/N;
 printf("\ncost=%f",cost);
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
 printf("\nCentroids:cluster%d(%f,%f)\n",k,Cx[k],Cy[k]);
      }

       if(cost==old_cost)
      break;



iter++;


      }



  printf("\nConverged!");
}

int main()
{
    int i,k;
    heuristic();

    kmean();
     for(i=0;i<N;i++)
    {
     printf("\ntx[%d]=%f and ty[%d]=%f",i,tx[i],i,ty[i]);
    }

    for(i=0;i<N;i++)
    {
        printf("\ndata %d in group %d",i,c[i]);
    }
    for(k=0;k<K;k++)
    {
     printf("\nCentroids:cluster%d(%f,%f)\n",k,Cx[k],Cy[k]);
    }
    return 0;
}
