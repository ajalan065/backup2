#include<iostream>
using namespace std;

struct node
{
       int n;
       struct node *llink, *rlink;
}*t;

class binst
{
      public:
             node *root;
             void display(node *t);
             void del(int a);
             void add(int a);
             void search(int a);
};

void binst::search(int a)
{
                 struct node *trav=root;
                 int f=0,lev=0;
                 while(trav!=NULL && !f)
                 {
                                  if(trav->n==a)                 
                                  {
                                       f=1;
                                       break;
                                  }
                                  else if(a>trav->n)
                                       trav=trav->rlink;
                                  else
                                      trav=trav->llink;
                                  lev++;
                 }
                 if(f==1)
                         cout<<"element exists in the bst at level"<<lev<<endl;
                 else
                          cout<<"element does not exists in the bst\n";

                                          
}                 
                 
void binst::del(int a)
{
	struct node *t1=NULL;
	if(t->n==a)
	{
		if(t->llink==NULL && t->rlink==NULL)
			cout<<     "\nTree is empty";
		else if(t->llink!=NULL && t->rlink==NULL)
		{
			t->n=t->llink->n;
			t->llink=NULL;
		}
		else if(t->llink==NULL && t->rlink!=NULL)
		{
			t->n=t->rlink->n;
			t->rlink=NULL;
		}
		else
		{
			if(a<t->n)
			{
				t1=t->llink;
				while(t1->rlink!=NULL)t1=t1->rlink;
				t->n=t1->n;
			}
			else 
			{
				t1=t->rlink;
				while(t1->llink!=NULL)t1=t1->llink;
				t->n=t1->n;
			}
		}
	}
	else if(a<t->n)t=t->llink;
	else t=t->rlink;
}                     
                 
void binst::display(node *t)
{
              if(t!=NULL)
              {
                         display(t->llink);
                         cout<<"  "<<t->n;
                         display(t->rlink);
              }
}
 
void binst::add(int a)
{
     struct node *temp=new node;
     temp->n=a;
     temp->llink=temp->rlink=NULL;
     if(root==NULL)
     {
                root=temp;
     }
     else
     {
         int greater=0,f=1;
         struct node *trav=root,*parent=NULL;
        while(trav!=NULL)
         {
             if(a==trav->n)
             {
                           cout<<"element already exists"<<endl;
                           f=0;
                           break;
             }
             else if(a<trav->n)
             {
                  parent=trav;
                  trav=trav->llink;
                  greater=0;
             }
             else if(a>trav->n)
             {
                  parent=trav;
                  trav=trav->rlink;
                  greater=1;
             }
         }
         if(!greater && f)
                   parent->llink=temp;
         else if(greater && f)
                   parent->rlink=temp;
     }
} 


int main()
{
    binst *ob=new binst;
    ob->root=NULL;
    int ch;
    do
    {
        cout<<"1. to enter data, 2. to display 3.to search\n";
        cin>>ch;
        switch(ch)
        {
                  case 1:
                       int a;
                       cin>>a;
                       ob->add(a);
                  break;
                  
                  case 2:
                       ob->display(ob->root);        
                  break;
                  
                  case 3:
                       int d;
                       cin>>d;
                       ob->search(d);
                  break;
		case 4:
			int c;
			cin>>c;
			ob->del(c);
		break;
        }
        cout<<"press 1 to continue adns 0 to exit\n";
        cin>>ch;
    }while(ch!=0);
    
    return 0;
}   
         
         
         
         
         
         
         
         
         
         
         
         
         
                
