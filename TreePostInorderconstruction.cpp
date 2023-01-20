#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define en "\n"

class node{
   public:
   int data;
   node* left;
   node* right;
   node(int val){
      data=val;
      left=NULL;
      right=NULL;
   }
};

int search(vector<int> &v,int k){
   for(int i=0;i<v.size();i++){
      if(v[i]==k)
      return i;
   }
   return -1;
}

node* buildTree(vector<int> &inorder,vector<int> &postorder,int start,int end){
   static int idx=4;
   if(start>end){
      return NULL;
   }
   int k=postorder[idx--];
   node* n=new node(k);
   if(start==end) return n;
   int pos=search(inorder,k);
   n->right=buildTree(inorder,postorder,pos+1,end);
   n->left=buildTree(inorder,postorder,start,pos-1);
   return n;
}

void printinorder(node* root){
   if(root==NULL) return;
   printinorder(root->left);
   cout<<root->data<<" ";
   printinorder(root->right);
}


int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   vector<int> inorder{1,2,3,4,5};
   vector<int> postorder{2,1,5,4,3};
   node* root = buildTree(inorder,postorder,0,4);
   printinorder(root);
   return 0;
}