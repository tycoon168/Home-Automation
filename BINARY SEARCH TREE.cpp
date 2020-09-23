#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
  int data;
  node * left;
  node * right;
};
node * casea(node * ,node * ,node *);
node * caseb(node * ,node *,node *);

node * insert(node * tree,int value)
{
  node * ptr=(node *)(malloc(sizeof(node)));
  ptr->data=value;
  ptr->left=NULL;
  ptr->right=NULL;
  if(tree==NULL)
  tree=ptr;
  else
  {
     node * var=tree;
     node * par=NULL;
     while(var!=NULL)
    {
       par=var;
       if(value<var->data)
       var=var->left;
       else
       var=var->right;
    }
    if(value<par->data)
    par->left=ptr;
    else 
    par->right=ptr;
  }
 return tree;
}
void inorder(node * tree)
{
  if(tree!=NULL)
  {
     inorder(tree->left);
     cout<<tree->data<<"  ";
     inorder(tree->right);
  }
}
node * deletion(node * tree,int value)
{
   node * var=tree;
   node * par=NULL;
   while(var!=NULL)
   {
   	if(value==var->data)
   	    break;
   	   par=var;
     if(value<var->data)
       var=var->left;
     else
      var=var->right;
   }
  if(var==NULL)
  cout<<endl<<"ELEMENT NOT FOUND"<<endl<<endl;
  else
  {
    if(var->left!=NULL&&var->right!=NULL)
    tree=casea(tree,var,par);
    else
    tree=caseb(tree,var,par);
    cout<<"ELEMENT DELETED IS  :  "<<var->data<<endl<<endl;
  }
return tree;
}
node * caseb(node * root,node * var,node * par)
{
   node * child;
   if(var->left==NULL&&var->right==NULL)
   child=NULL;
   else
   {
     if(var->left!=NULL)
     child=var->left;
     else
     child=var->right;
   }
   if(par!=NULL)
   {
       if(var==par->left)
       par->left=child;
       else
       par->right=child;
   }
   else
   root=child;
 return root;
}
node * casea(node * root,node * var,node * par)
{
   node * next=var->right;
   node * save=var;
   while(next->left!=NULL)
   {
     save=next;
     next=next->left;
   }
   root=caseb(root,next,save);
   var->data=next->data;
  return root;
}
int main()
{
  int n,a,d,k;
  node * tree=NULL;
  cout<<endl<<endl<<"ENTER THE NO OF ELEMENTS YOU WANT TO INSERT  :  ";
  cin>>n;
  cout<<endl<<endl<<"ENTER THE ELEMENTS  :  ";
  for(int i=0;i<n;i++)
  {
    cin>>a;
    tree=insert(tree,a);
  }
  cout<<endl<<endl<<"INORDER TRAVERSAL IS  :  ";
  inorder(tree);
  cout<<endl<<endl<<"ENTER THE NO OF ELEMENTS YOU WANT TO DELETE  :  ";
  cin>>d;
  for(int j=0;j<d;j++)
  {
    cout<<endl<<"Enter the element to delete  :  ";
    cin>>k;
    tree=deletion(tree,k);
    cout<<endl<<"RESULTING INORDER  :  ";
    inorder(tree);
  }
}
