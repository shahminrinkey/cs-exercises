#include<iostream>

#include<string.h>

using namespace std;

char data[20];
int top=-1;

int data2[20];
int top2=-1;
char p[20];

void push(char item)
{
	data[++top]=item;
}

char pop()
{
	return data[top--];

}




void push2(int item)
{
  data2[++top]=item;

}

int pop2()
{
    return data2[top--];
}

char chktop()
{
	return data[top];
}

int prec(char b)

{
	if(b=='-')
		return 1;
	if(b=='+')
		return 2;
	if(b=='*')
		return 3;
	if(b=='/')
		return 4;
}

void postfix(char a[])
{
   char x,y;
   int prc,p1,p2,l;
   l=0;


	for(int i=0;a[i]!=NULL;i++)
	{
		if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')

		{
             while(1)

			 {

				 x=chktop();
                  prc=prec(x);
				  p1=prc;


				 prc=prec(a[i]);
				 p2=prc;



				 if(p1>=p2)
				 {
					 y=pop();
                     cout<<y;
                     p[l++]=y;

				 }

			 else
				 break;
		}
			 push(a[i]);


		}

		else if(a[i]>='0'&&a[i]<='9')
		{

			cout<<a[i];
			p[l++]=a[i];
		}

		else if(a[i]=='(')
		{
			push(a[i]);
		}

		else if(a[i]==')')
		{
			while(1)
			{
				x=pop();

			if(x=='(')
				break;
			}



		}
	}

	for(int k=top;data[k]!=NULL;k--)
	{
		x=pop();
		cout<<x;
		p[l++]=x;
	}
for(int r=0;p[r]!=NULL;r++)
	{

		cout<<p[r]<<"\t";
	}

}

void postfix_res(char b[])
{
    int n,m;
    int res,l,x,digit,k;
    char op;

    l=strlen(b);

    for(int i=0;i<l;i++)
    {
        if(b[i]>='0'&&b[i]<='9')
        {
            digit=b[i]-'0';
            push(digit);


        }

          if(b[i]=='*'||b[i]=='/'||b[i]=='+'||b[i]=='-')
        {

            op=b[i];

            n=pop();
            m=pop();

          if(op=='*'){
            res=m*n;
            }
            else if(op=='/'){
            res=m/n;
            }
            else if(op=='+'){
            res=m+n;

            }
            else if(op=='-'){
            res=m-n;


           }


               push(res);

          }

    }

                    x=pop();
       cout<<"\n"<<x<<endl;
}



	int main()
	{
       char ch[20];

	   cout<<"\nEnter xpression:";
	   cin>>ch;
		postfix(ch);

		postfix_res(p);
return 0;
	}








































