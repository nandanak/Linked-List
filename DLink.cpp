#include <iostream>
using namespace std;
class Node
{
  int data;
  Node* next;
  Node* prev;
public:
  Node() {
  };
  void sdata(int adata){
    data=adata;
  };
  void snext(Node* anext){
    next=anext;
  };
  void sprev(Node* aprev){
    prev=aprev;
  };
  int Data(){
    return data;
  };
  Node* Next(){
    return next;
  };
  Node* Prev(){
    return prev;
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

void Linkedlist::insertbeg(int data)
{
  Node* newnode = new Node();
  newnode->sdata(data);
  if(head==NULL)
  {
    newnode->snext(NULL);
    newnode->sprev(NULL);
    head=newnode;
  }
  else
  {
    newnode->sprev(NULL);
    newnode->snext(head);
    head=newnode;
  }
}
void Linkedlist::insertpos(int p,int data)
{
  Node* newnode = new Node();
  Node* temp=head;
  newnode->sdata(data);
  if(head==NULL)
  {
    newnode->snext(NULL);
    newnode->sprev(NULL);
    head=newnode;
  }
  else if(p==1)
  {
    insertbeg(data);
    return;
  }
  else
  {
  int i=1;
  while(i<p-1)
  {
    temp=temp->Next();
    i++;
  }
  newnode->snext(temp->Next());
  temp->Next()->sprev(newnode);
  newnode->sprev(temp);
  temp->snext(newnode);
 }
}
void Linkedlist::insertend(int data)
{
  Node* newnode = new Node();
  Node* temp=head;
  newnode->sdata(data);
  if(head==NULL)
  {
    newnode->snext(NULL);
    newnode->sprev(NULL);
    head=newnode;
  }
  else
  {
    while(temp->Next()!=NULL)
    {
      temp=temp->Next();
    }
    temp->snext(newnode);
    newnode->sprev(temp);
    newnode->snext(NULL);
  }
}
void Linkedlist::deletebeg()
{
  Node* temp=head;
  if(temp==NULL)
  {
    cout<<"List is empty";
    return;
  }
  else
  {
    temp=temp->Next();
    head=temp;
    temp->sprev(NULL);
  }
}
void Linkedlist::deletepos(int p)
{
  Node *temp=head;
  if(temp==NULL)
  {
    cout<<"List is empty";
    return;
  }
  else
  {
    int i=1;
    while(i<p-1)
    {
      temp=temp->Next();
      i++;
    }
    Node* end=temp->Next()->Next();
    temp->snext(end);
    end->sprev(temp);
  }
}
void Linkedlist::deleteend()
{
  Node *temp=head;
  if(temp==NULL)
  {
    cout<<"List is empty";
    return;
  }
  else
  {
    while(temp->Next()->Next()!=NULL)
    {
      temp=temp->Next();
    }
    temp->snext(NULL);
  }
}
void Linkedlist::display()
{
  Node *temp=head;
  cout<<"List of elements\n";
  while(temp!=NULL)
  {
    cout<<temp->Data()<<"->";
    temp=temp->Next();
  }
  cout<<"NULL\n";
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
