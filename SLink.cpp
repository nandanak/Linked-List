#include <iostream>
using namespace std;
class Node
{
  int data;
  Node* next;
public:
  Node() {
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

class Linkedlist
{
  Node* head;
public:
  Linkedlist() {
    head=NULL;
  };
  void insertbeg(int data);
  void insertpos(int p,int data);
  void insertend(int data);
  void deletebeg();
  void deletepos(int p);
  void deleteend();
  void display();
};

void Linkedlist::display()
{
  Node* temp=head;
  cout<<"List of elements\n";
  while(temp!=NULL){
       cout<<temp->Data()<<"->";
       temp=temp->Next();
  }
  cout<<"NULL\n";
}
void Linkedlist::insertbeg(int data)
{
    Node* temp;
    Node* newnode = new Node();
    newnode->sdata(data);
    if(head==NULL)
    {
      head = newnode;
      newnode->snext(NULL);
    }
    else
    {
      temp = head;
      head = newnode;
      newnode->snext(temp);
    }
}
void Linkedlist::insertpos(int p,int data)
{
  Node* newnode = new Node();
  newnode->sdata(data);
  Node* temp = head;
  if(head==NULL)
  {
    head = newnode;
    newnode->snext(NULL);
  }
  else
  {
    int i=1;
    while(i<p-1){
      if(temp->Next()!=NULL)
      temp=temp->Next();
      i++;
    }
    newnode->snext(temp->Next());
    temp->snext(newnode);
  }
}
void Linkedlist::insertend(int data)
{
  Node* newnode= new Node();
  newnode->sdata(data);
  newnode->snext(NULL);
  Node* temp = head;
  if(temp!=NULL){
   while(temp->Next() != NULL){
       temp = temp->Next();
   }
   temp->snext(newnode);
  }
  else
  head = newnode;
}

void Linkedlist::deletebeg()
{
  Node* temp = head;
  if(temp==NULL)
  {
    cout<<"List is empty";
    return;
  }
  temp=temp->Next();
  head=temp;
}
void Linkedlist::deletepos(int p)
{
  Node* temp=head;
  if(temp==NULL)
  {
    cout<<"List is empty";
    return;
  }
  else
  {
  int i=1;
  while(i<p-1){
    temp=temp->Next();
    i++;
  }
  temp->snext(temp->Next()->Next());
  }
}
void Linkedlist::deleteend()
{
  Node* temp=head;
  if(temp==NULL)
  {
    cout<<"List is empty";
    return;
  }
  while(temp->Next()->Next()!=NULL)
  {
    temp=temp->Next();
  }
  temp->snext(NULL);
}

int main()
{
  Linkedlist list;
  int n=0,data,p;
  while(n!=8){
  cout<<"Options:\n[1] Insert node at beginning\n[2] Insert node at end\n[3] Insert node at a position\n";
  cout<<"[4] Delete node from beginning\n[5] Delete node from end\n[6] Delete node from a position\n";
  cout<<"[7] Print the linked list\n[8] Exit\nEnter your choice\n";
  cin>>n;
  switch(n)
  {
    case 1:cout<<"Enter element to be inserted\n";
           cin>>data;
           list.insertbeg(data);
           break;
    case 2:cout<<"Enter element to be inserted\n";
           cin>>data;
           list.insertend(data);
           break;
    case 3:cout<<"Enter the position to insert node\n";
           cin>>p;
           cout<<"Enter element to be inserted\n";
           cin>>data;
           list.insertpos(p,data);
           break;
    case 4:cout<<"Deleting from beginning....\n";
           list.deletebeg();
           break;
    case 5:cout<<"Deleting from end....\n";
           list.deleteend();
           break;
    case 6:cout<<"Enter the position of element\n";
           cin>>p;
           cout<<"Deleting from position "<<p<<"....\n";
           list.deletepos(p);
           break;
    case 7:list.display();
           break;
    case 8:cout<<"Exiting...\n";
           break;
    default:cout<<"Invalid Option\n";
            break;
  }
}
return 0;
}
