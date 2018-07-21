#include <iostream>
using namespace std;
class Node{
  int data;
  Node* next;
public:
  Node(){
  };
  void sdata(int adata){
    data=adata;
  };
  void snext(Node* anext){
    next=anext;
  };
  int Data(){
    return data;
  };
  Node* Next(){
    return next;
  };
};
class Stacklist{
  Node* top;
public:
  Stacklist(){
  };
  Node* push(Node* top,int data);
  Node* pop(Node* top);
  void traverse(Node* top);
};

Node* Stacklist::push(Node* top,int data)
{
  Node* temp = new Node();
  temp->sdata(data);
  temp->snext(top);
  top = temp;
  return top;
}

Node* Stacklist::pop(Node* top)
{
  Node* temp;
  if(top==NULL)
  cout<<"Stack is empty\n";
  else
  {
    temp=top;
    cout<<"Element popped: "<<temp->Data()<<"\n";
    top=top->Next();
    delete(temp);
  }
  return top;
}

void Stacklist::traverse(Node* top)
{
  Node* temp;
  temp=top;
  if(top==NULL)
  cout<<"NULL\n";
  else
  {
    cout<<"Stack elements are \n";
    while(temp!=NULL)
    {
      cout<<temp->Data()<<"\n";
      temp=temp->Next();
    }
  }
}

  int main()
  {
    Stacklist stack;
    int n=0,data;
    Node* top=NULL;
    while(n!=4){
    cout<<"Options:\n[1] Push element into stack\n[2] Pop element from stack\n[3] Traverse the stack\n";
    cout<<"[4] Exit\nEnter your choice\n";
    cin>>n;
    switch(n)
    {
      case 1:cout<<"Enter element to be pushed\n";
             cin>>data;
             top=stack.push(top,data);
             break;
      case 2:cout<<"Popping element....\n";
             top=stack.pop(top);
             break;
      case 3:stack.traverse(top);
             break;
      case 4:cout<<"Exiting...\n";
             break;
      default:cout<<"Invalid Option\n";
              break;
    }
  }
  return 0;
  }
