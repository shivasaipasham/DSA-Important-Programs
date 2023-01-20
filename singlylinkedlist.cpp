#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define en "\n"


class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};


void insertAtTail(node* &head,int val){

    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;

}

void insertAtHead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}

node* reverseRecursive(node* &head){
    if(head==NULL || head->next==NULL){
        //cout<<head->data<<en;
        return head;
    }
    node* newhead=reverseRecursive(head->next);
    //cout<<head->data<<en;
    head->next->next=head;
    head->next=NULL;
    return newhead;

}

node* reverseKNodes(node* head,int k){
    node* preptr=NULL;
    node* curptr=head;
    node* nexptr;
    int i=0;
    while(curptr!=NULL && i<k){
        nexptr=curptr->next;
        curptr->next=preptr;
        preptr=curptr;
        curptr=nexptr;
        i++;
    }
    if(nexptr!=NULL){
        head->next=reverseKNodes(nexptr,k);
    }
    return preptr;
}

node* reverseIterative(node* &head){
    node* preptr=NULL;
    node* curptr=head;
    node* nexptr=head->next;
    while(curptr!=NULL){
        nexptr=curptr->next;
        curptr->next=preptr;
        preptr=curptr;
        curptr=nexptr;
    }
    return preptr;
}

void display(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<en;;
}

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   node* head=NULL;
   insertAtTail(head,1);
   insertAtTail(head,2);
   insertAtTail(head,3);
   insertAtTail(head,4);
   insertAtTail(head,5);
   insertAtTail(head,6);
   display(head);
   //node* revIteHead=reverseIterative(head);
   //node* revRecHead=reverseRecursive(head);
   //display(revIteHead);
   //display(revRecHead);
   node* revKNodes=reverseKNodes(head,3);
   display(revKNodes);


}