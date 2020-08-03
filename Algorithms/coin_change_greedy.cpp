#include<iostream>
#include<queue>
#include<math.h>

using namespace std;


int coin[10];

priority_queue<int>maxHeap;


void init(int n)
{
	cout<<"\nEnter coins:\n";
	for(int i=0;i<n;i++)
	{
		cin>>coin[i];
		maxHeap.push(coin[i]);
	}
}
  


int coin_change(int n,int money)
{

   int c;
   float coin_num;
   int num_of_coin=0;
    while(money!=0)
	{
       

     c=maxHeap.top();
	 maxHeap.pop();
	 cout<<"\n"<<c;

	 if(c<=money)
	 {

	coin_num=floor(money/c);

	num_of_coin+=coin_num;
    cout<<"\nNumber of coins:"<<num_of_coin;
	money=money-(c*coin_num);
	 }

	}

   return num_of_coin;

}


int main()
{

	int n;
	int number,money;
	cout<<"\nEnter number of coins:";

	cin>>n;

	init(n);

	cout<<"\namount of money:";
	cin>>money;

	number=coin_change(n,money);

	cout<<"\nMinimum coin change:"<<number;

	return 0;
}

