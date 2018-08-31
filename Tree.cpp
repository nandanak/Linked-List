#include <iostream>
using namespace std;
class Node
{
  int data;
  Node* left=NULL;
  Node* right=NULL;
public:
  Node() {
  };
  void sdata(int adata){
    data=adata;
  };
  void sleft(Node* aleft){
    left=aleft;
  };
  void sright(Node* aright){
    right=aright;
  }
  int Data(){
    return data;
  };
  Node* Left(){
    return left;
  };
  Node* Right(){
    return right;
  };
};
class Tree
{
  Node* root=NULL;
public:
  Tree(){
  };
  void insertnode(Node* node, int data);
  void printtree(Node* root);
};
void Tree::insertnode(Node* node, int data)
{
  if(node->Data()<data)
  {
    if(node->Left()!=NULL)
    insertnode(node->Left(),data);
    else
    {
      Node* newnode = new Node();
      newnode->sdata(data);
      node->sleft(newnode);
    }
  }
  else
  {
    if(node->Right()!=NULL)
    insertnode(node->Right(),data);
    else
    {
      Node* newnode = new Node();
      newnode->sdata(data);
      node->sright(newnode);
    }
  }
}
void printtree(Node* root)
{
  if(root==NULL)
  return;
  printtree(root->Right());
  cout<<root->Data();
  printtree(root->Left());
}
int main()
{
  Tree tree;
  int data,n;
  Node* root=NULL;
  while(n!=3){
    cout<<"(1) Insert into tree\n(2) Print the tree\n";
    cout<<"(3) Exit\n";
    cin>>n;
    switch(n)
    {
      case 1:cout<<"Enter element to be inserted\n";
             cin>>data;
             tree.insertnode(root,data);
             break;
      case 2:tree.printtree(root);
             break;
      case 3:cout<<"Exiting...\n";
             break;
      default:cout<<"Invalid option\n";
              break;
    }
  }
  return 0;
}
