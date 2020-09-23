#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	 int info;
	 struct node *next;
	 struct node *right;
};
struct node *tree=NULL;
void create(int value )
{
	 if(tree==NULL)
	{
			struct node *ptr=(struct node *)(malloc(sizeof(struct node)));
			cout<<endl<<endl<<"ptr value :  "<<ptr<<endl<<end;
            ptr->info=value;
            ptr->next=NULL;
            ptr->right=NULL;
            tree=ptr;
	}
	else if(tree!=NULL)
	cout<<endl<<endl<<"tree is already created";
}
int main()
{
	
	cout<<tree;
	create(6);
	cout<<endl<<tree<<endl;
	cout<<tree->info;
	create(7);
}
