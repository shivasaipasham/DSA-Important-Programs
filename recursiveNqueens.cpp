#include<bits/stdc++.h>
using namespace std;
//using namespace std::chrono;
typedef long long ll;
#define en "\n"

bool isValid(vector<vector<bool>> &v,int i,int j){
   int row=i,col=j;
   while(row>=0 && col>=0){
      if(v[row][col]!=0){
         return false;
      }
      row--;
      col--;
   }
   row=i,col=j;
   while(row>=0){
      if(v[row][col]!=0){
         return false;
      }
      row--;
   }
   row=i,col=j;
   while(col>=0){
      if(v[row][col]!=0){
         return false;
      }
      col--;
   }
   row=i,col=j;
   while(row>=0 && col<v[0].size()){
      if(v[row][col]!=0){
         return false;
      }
      row--;
      col++;
   }
   return true;
}

void nqueens(vector<vector<bool>> &v,int i,int j,int n,int q,string s){
   if(q==n){
      cout<<s<<en;
      return;
   }
   if(j==n){
      i++;
      j=0;
   }
   if(i==n){
      return;
   }
   if(isValid(v,i,j)){
      v[i][j]=1;
      nqueens(v,i,j+1,n,q+1,s+'['+to_string(i)+","+to_string(j)+']');
      v[i][j]=0;
   }
   nqueens(v,i,j+1,n,q,s);
}
  

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   //auto start = high_resolution_clock::now();
   int n;
   cin>>n;
   vector<vector<bool>> v(n,vector<bool>(n,0));
   nqueens(v,0,0,n,0,"");
   //auto stop = high_resolution_clock::now();
   //auto duration = duration_cast<microseconds>(stop - start);
   //cout << "executed in "<< duration.count() << " ms" << endl;
   return 0;
}