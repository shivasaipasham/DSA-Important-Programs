#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define en "\n"

class ListNode{
    public:
    int val;
    ListNode* next;

    ListNode(int data){
        val=data;
        next=NULL;
    }
};

void insertAtTail(ListNode* &head,int val){

    ListNode* n=new ListNode(val);
    if(head==NULL){
        head=n;
        return;
    }
    
    ListNode* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;

}

void insertAtHead(ListNode* &head,int val){
    ListNode* n=new ListNode(val);
    n->next=head;
    head=n;
}

void print(ListNode* head){
    while(head!=NULL){
        if(head->next!=NULL)
            cout<<head->val<<"->";
        else
            cout<<head->val;
        head=head->next;
    }
}
    
ListNode* findmid(ListNode* head){
    ListNode* slow=head,*fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    //cout<<slow->val<<" ";
    return slow;
} 
    
ListNode* merge(ListNode* &head1,ListNode* &head2){
    ListNode* dummynode=new ListNode(-1);
    ListNode* temp=dummynode;
    ListNode *ptr1=head1,*ptr2=head2;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->val<ptr2->val){
            temp->next=ptr1;
            ptr1=ptr1->next;
            temp=temp->next;
        }
        else{
            temp->next=ptr2;
            ptr2=ptr2->next;
            temp=temp->next;
        }
    }
    while(ptr1!=NULL){
        temp->next=ptr1;
        ptr1=ptr1->next;
        temp=temp->next;
    }
    while(ptr2!=NULL){
        temp->next=ptr2;
        ptr2=ptr2->next;
        temp=temp->next;
    }
    print(dummynode);cout<<"\n";
    return dummynode->next;
}

ListNode* mergesort(ListNode* &head){
    if(head==NULL || head->next==NULL){
        //cout<<head->val<<" ";
        return head;
    } 
    ListNode* temp=findmid(head); 
    ListNode* head2=temp->next;
    temp->next=NULL;
    ListNode* nh1 = mergesort(head);
    ListNode* nh2 = mergesort(head2);
    print(head); cout<<" merge "; print(head2); cout<<"\n";
    return (merge(nh1,nh2));
}




int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   ListNode* head=NULL;
   int n;
   cin>>n;
   for(int i=0;i<n;i++){
       int x; cin>>x;
       insertAtTail(head,x);
   }
   ListNode* nh = mergesort(head);
   print(nh);



}