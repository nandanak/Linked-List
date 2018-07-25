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
class Linkedlist{
  Node* head;
public:
  Linkedlist(){
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

void Linkedlist::insertbeg(int data)
{
  Node* temp=head;
  Node* newnode = new Node();
  newnode->sdata(data);
  if(temp==NULL)
  {
    head=newnode;
    newnode->snext(head);
    return;
  }
  else
  {
    newnode->snext(head);
    while(temp->Next()!=head)
    {
      temp=temp->Next();
    }
    temp->snext(newnode);
    head=newnode;
  }
}
void Linkedlist::insertpos(int p,int data)
{
  Node* temp=head;
  Node* newnode = new Node();
  newnode->sdata(data);
  if(p==1)
  insertbeg(data);
  else if(temp!=NULL&&p>1)
  {
    int i=1;
    while(i<p-1){
      temp=temp->Next();
      i++;
    }
    if(temp==head)
    {
     cout<<"Invalid position";
     return;
    }
    else if(temp->Next()==head)
    {
     insertend(data);
     return;
    }
    newnode->snext(temp->Next());
    temp->snext(newnode);
  }
  else
  cout<<"Invalid position";
}
void Linkedlist::insertend(int data)
{
 Node* temp=head;
 Node* newnode = new Node();
 newnode->sdata(data);
 if(temp==NULL)
 {
   head=newnode;
   newnode->snext(head);
   return;
 }
 else
 {
   while(temp->Next()!=head){
     temp=temp->Next();
   }
   temp->snext(newnode);
   newnode->snext(head);
 }
}
void Linkedlist::deletebeg()
{
  Node* temp=head;
  if(temp==NULL)
  {
    cout<<"The list is empty";
    return;
  }
  else
  {
    while(temp->Next()!=head){
      temp=temp->Next();
    }
    temp->snext(head->Next());
    head=head->Next();
  }
}
void Linkedlist::deletepos(int p)
{
  Node* temp=head;
  if(temp==NULL)
  {
    cout<<"The list is empty";
    return;
  }
  else if(p==1)
  {
    deletebeg();
    return;
  }
  else
  {
    int i=1;
    while(i<p-1&&temp->Next()->Next()!=head){
      temp=temp->Next();
      i++;
    }
    if(temp->Next()->Next()!=head)
    {
      temp->snext(temp->Next()->Next());
    }
    else if(temp->Next()->Next()==head&&i==(p-1))
    {
      deleteend();
      return;
    }
    else
    {
     cout<<"Invalid position";
     return;
    }
  }
}
void Linkedlist::deleteend()
{
  Node* temp=head;
  if(temp==NULL)
  {
    cout<<"The list is empty";
    return;
  }
  else
  {
    while(temp->Next()->Next()!=head){
      temp=temp->Next();
    }
    delete(temp->Next());
    temp->snext(head);
  }
}
void Linkedlist::display()
{
  Node* temp=head;
  cout<<"List of elements\n";
  if(temp==NULL)
  {
    cout<<"NULL";
    return;
  }
  else
  {
  while(temp->Next()!=head){
    cout<<temp->Data()<<"->";
    temp=temp->Next();
  }
  cout<<temp->Data()<<"->";
  temp=temp->Next();
  cout<<temp->Data()<<"->....";
 }
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
