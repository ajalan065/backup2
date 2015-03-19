/*infix to postfix conversion*/

#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

class Inpost
{
    char str[30];
	public:
	char st[30], post[30];
	int top=0, topp=0, l;
	Inpost()
    {
    cout<<"\nEnter the expression:\n";      //takes input
    gets(str);
    }
	void intopost();
	void display();
	~Inpost()
	{
	cout<<"\nPress any key to exit....";
	exit(0);
	}
};

void Inpost::intopost()
{
    l=strlen(str);
    int i;
    for(i=0;i<l;i++)
    {
        if(!(str[i]=='(' || str[i]==')' ||str[i]=='+' ||str[i]=='-' || str[i]=='*' || str[i]=='/'))
        {
            topp++;
            post[topp]=str[i];
        }
        else
        {
            if(str[i]=='(')
            {
                top++;
                st[top]=str[i];
            }

            if(str[i]==')')
            {
                while(st[top]!='(')
                {
                    topp++;
                    post[topp]=st[top];
                    top--;
                }
                top--;
            }
            if(str[i]=='*' || str[i]=='/')
            {
                if(top==0)st[top++]=str[i];
                else if(st[--top]=='+' || st[--top]=='-')st[++top]=str[i];
                else{

                while(st[--top]=='*' || st[--top]=='/')
                {
                    post[++topp]=st[top];
                }
                st[top++]=str[i];
            }
            }
            if(str[i]=='+' || str[i]=='-')
            {
                if(top==0)st[top++]=str[i];
                else
                {
                while(top>0)
                post[++topp]=st[top--];
                st[++top]=str[i];
                }
            }
            if(i==(l-1))post[++top]=st[top--];
        }
    }

    display();
}

void Inpost::display()
{
int i;
    cout<<endl;
    for(i=0;i<l;i++)
    {
        cout<<post[i];
    }
}
int main(void)
{
	Inpost *ob=new Inpost();
	ob->intopost();
	return 0;
}
