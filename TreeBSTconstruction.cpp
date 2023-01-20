#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define en "\n"

                              25
                             /   \
                            15   50 
                          /   \    \
                         10    22  70
                        /  \   / \
                       4   12 18 24




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

void printarray(vector<int> &v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<en;
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

bool search(node* root, int val) {
   if(root==NULL) return false;
   if(root->data==val) return true;
   if(root->data>val) return search(root->left,val);
   return search(root->right,val);
}

node* inordersuccessor(node* root){
   node* temp=root;
   while(temp!=NULL && temp->left!=NULL) temp=temp->left;
   return temp;
}

node* erase(node* root,int key){
   if(root->data>key){
      root->left=erase(root->left,key);
   }
   else if(root->data<key){
      root->right=erase(root->right,key);
   }
   else{
      if(root->left==NULL && root->right==NULL){
         return NULL;
      }
      else if(root->left==NULL){
         node* temp=root->right;
         free(root);
         return temp;
      }
      else if(root->right==NULL){
         node* temp=root->left;
         free(root);
         return temp;
      }
      else{
         node* temp=inordersuccessor(root->right);
         root->data=temp->data;
         root->right=erase(root->right,temp->data);
      }
   }
   return root;
}

void verticalorder(node* root,int lev,map<int,vector<int>> &mp){
   if(root==NULL) return;
   mp[lev].push_back(root->data);
   verticalorder(root->left,lev-1,mp);
   verticalorder(root->right,lev+1,mp);
}

void inorder(node* root){
   if(root==NULL) return;
   inorder(root->left);
   cout<<root->data<<" ";
   inorder(root->right);
}

void postorder(node* root){
   if(root==NULL) return;
   postorder(root->left);
   postorder(root->right);
   cout<<root->data<<" ";
}

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int t;
   cin>>t;
   while(t--){
      node* root=NULL;
      int n;
      cin>>n;
      while(n--){
         int x; cin>>x;
         insert(root,x);
      }
      map<int,vector<int>> mp;
      verticalorder(root,0,mp);
      for(auto it:mp){
         printarray(it.second);
      }
      cout<<en;
   }
   return 0;
}