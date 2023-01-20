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

void insert(node* &root,int value){
   node* n=new node(value);
   if(root==NULL){
      root=n;
      return;
   }
   node* temp=root;
   while(1){
      if(value<temp->data && temp->left==NULL){
         temp->left=n;
         return;
      }
      if(value>temp->data && temp->right==NULL){
         temp->right=n;
         return;
      }
      if(value<temp->data){
         temp=temp->left;
      }
      else{
         temp=temp->right;
      }
   }
}

void printpostorder(node* root){
   if(root==NULL) return;
   printpostorder(root->left);
   printpostorder(root->right);
   cout<<root->data<<" ";
}

void printarray(vector<int> &v){
   for(int i=0;i<v.size();i++)
      cout<<v[i]<<" ";
   cout<<"\n";
}

int height(node* root){
   if(root==NULL) return 0;
   return max(height(root->left),height(root->right))+1;
}

int diameter(node* root){
   if(root==NULL) return 0;
   int lheight=height(root->left);
   int rheight=height(root->right);
   int currdiameter=lheight+rheight+1;
   int ldiameter=diameter(root->left);
   int rdiameter=diameter(root->right);
   return max({currdiameter,ldiameter,rdiameter});
}

int countNodes(node* root){
   if(root==NULL) return 0;
   return 1+countNodes(root->left)+countNodes(root->right);

}

int sumNodes(node *root){
   if(root==NULL) return 0;
   return root->data+sumNodes(root->left)+sumNodes(root->right);
}

void sumReplacement(node* root){
   if(root==NULL) return;
   //cout<<"came\n";
   sumReplacement(root->left);
   sumReplacement(root->right);
   if(root->left!=NULL)
   root->data+=root->left->data;
   if(root->right!=NULL)
   root->data+=root->right->data;
}

void leftview(node* root){
   queue<node*> q;
   q.push(root);
   node* temp=root;
   while(!q.empty()){
      int n=q.size();
      for(int i=0;i<n;i++){
         if(i==0){
            cout<<q.front()->data<<" ";
         }
         if(q.front()->left!=NULL){
            q.push(q.front()->left);
         }
         if(q.front()->right!=NULL){
            q.push(q.front()->right);
         }
         q.pop();
      }
   }

}

void rightview(node* root){
   queue<node*> q;
   q.push(root);
   node* temp=root;
   while(!q.empty()){
      int n=q.size();
      for(int i=0;i<n;i++){
         if(i==n-1){
            cout<<q.front()->data<<" ";
         }
         if(q.front()->left!=NULL){
            q.push(q.front()->left);
         }
         if(q.front()->right!=NULL){
            q.push(q.front()->right);
         }
         q.pop();
      }
   }

}


int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int t;
   cin>>t;
   while(t--){
      int n;
      cin>>n;
      node* root=NULL;
      for(int i=0;i<n;i++){
         int x; cin>>x;
         insert(root,x);
      }
      int ans=0;
      
   

}
