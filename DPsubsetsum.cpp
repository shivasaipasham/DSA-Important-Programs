#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define en "\n"

void printarray(vector<int> &v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<en;
}


void printmatrix(vector<vector<int>> v){
   for(int i=0;i<v.size();i++){
      for(int j=0;j<v[0].size();j++){
         cout<<v[i][j]<<" ";
      }
      cout<<en;
   }
}


bool subsetsum_tabulation(vector<int> &v,int target){
   int r=v.size()+1,c=target+1;
   vector<vector<bool>> dp(r,vector<bool>(c,false));
   for(int i=0;i<r;i++){
      dp[i][0]=true;
   }
   for(int i=1;i<c;i++){
      dp[0][i] = false;
   }
   for(int i=1;i<r;i++){
      for(int j=1;j<c;j++){
         if(dp[i-1][j]==true){
            dp[i][j]=true;
         }
         else if(j-v[i-1]>=0 && dp[i-1][j-v[i-1]]==true){
            dp[i][j] = true;
         }
      }
   }
   return dp[r-1][c-1];
}

int subsetsum_memoization(vector<int> &v,vector<vector<int>> &dp,int n,int target){
   if(n==-1 || target==0){
      if(target==0) return 1;
      return 0;
   }
   if(dp[n][target]!=-1) return dp[n][target];
   int f;
   if(target>=v[n]){
      f = subsetsum_memoization(v,dp,n-1,target-v[n])||subsetsum_memoization(v,dp,n-1,target);
   }
   else if(target<v[n]){
      f = subsetsum_memoization(v,dp,n-1,target);
   }
   dp[n][target] = f;
   return f;
}






int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   vector<int> v{10,4,5,9,1};
   int target=15;
   int n=v.size();
   vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
   if(subsetsum_memoization(v,dp,n-1,target))
   cout<<"True"<<en;
   else 
   cout<<"False"<<en;
   printmatrix(dp);
   return 0;
}