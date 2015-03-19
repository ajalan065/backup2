#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

class intopostfix
{
    char str[30];
    int top=-1, topp=-1, i, l;
    public:
    char post[30], st[20];
    void inpost(void);
    void display(void);
    intopostfix()
    {
        cout<<"\nEnter the expression:\nEnter # at the end of execution: \n";
        gets(str);
    }
};

void intopostfix:: inpost(void)
{
    l=strlen(str);
    for(i=0;i<l;i++)
    {
        if(!(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='#'))
        {
            topp++;
            post[topp]=str[i];

        }
        else
        {
            if(str[i]=='*' || str[i]=='/')
            {
              if((st[top]=='+' || st[top]=='-' || top==-1))
              {
                ++top;
                st[top]=str[i];
              }
              {
                if(st[--top]=='*' || st[--top]=='/')
                {
                    topp++;
                    post[topp]=st[top++];
                }
                ++top;
                st[top]=str[i];
              }
            }

            if(str[i]=='+' || str[i]=='-')
            {
                while(top!=-1)
                {
                  // ++topp;
                   //  top--;
                    post[++topp]=st[top--];
                }
                ++top;
                st[top]=str[i];
            }
            if(str[i]=='#')
            {
                while(top!=-1)
                {
                    topp++;
                    post[topp]=st[top];
                    top--;
                }
            }
        }
    }
    display();
}

void intopostfix:: display(void)
{
    for(i=0;i<l;i++)
    {
        cout<<post[i];
    }
    cout<<"\n";
    for(i=0;i<l;i++)cout<<st[i];
}


int main(void)
{
    intopostfix *ob=new intopostfix();
    ob->inpost();
    return 0;
}
