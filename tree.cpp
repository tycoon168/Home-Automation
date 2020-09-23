#include<iostream>
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
			struct node s1,*ptr;
            ptr=&s1;
            cout<<endl<<endl<<"ptr value  :  "<<ptr<<endl<<endl;
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
