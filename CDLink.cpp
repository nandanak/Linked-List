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
  Node* temp=head;
  Node* newnode = new Node();
  newnode->sdata(data);
  if(temp==NULL)
  {
    head=newnode;
    newnode->snext(head);
    newnode->sprev(head);
  }
  else
  {
    while(temp->Next()!=head){
      temp=temp->Next();
   }
   newnode->snext(head);
   newnode->sprev(temp);
   head->sprev(newnode);
   temp->snext(newnode);
   head=newnode;
  }
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
    newnode->sprev(head);
  }
  else
  {
    while(temp->Next()!=head){
      temp=temp->Next();
    }
    newnode->snext(head);
    newnode->sprev(temp);
    head->sprev(newnode);
    temp->snext(newnode);
  }
}

void Linkedlist::insertpos(int data,int p)
{
  Node* temp=head;
  Node* newnode = new Node();
  newnode->sdata(data);
  if(p==1)
  {
   insertbeg(data);
   return;
  }
  else
  {
    if(temp==NULL)
    {
      cout<<"Invalid position";
      return;
    }
    else
    {
      int i=1;
      while(i<p-1&&temp->Next()!=head){
       temp=temp->Next();
       i++;
      }
      if(temp->Next()==head&&i==(p-1))
      {
        insertend(data);
        return;
      }
      else if(temp->Next()==head&&i!=(p-1))
      {
        cout<<"Invalid position";
        return;
      }
      temp->Next()->sprev(newnode);
      newnode->snext(temp->Next());
      newnode->sprev(temp);
      temp->snext(newnode);
    }
  }
}

void Linkedlist::deletebeg();
{
  Node temp=head;
  if(temp==NULL)
  {
    cout<<"List is empty";
    return;
  }
  else
  {
    while(temp->Next()!=head){
      temp.next=head.next;
      head=head.next;

    }
  }
}
