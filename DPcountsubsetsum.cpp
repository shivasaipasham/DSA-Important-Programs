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




int countsubsetsum_memoization(vector<int> &v,vector<vector<int>> &dp,int n,int target){
   if(n==-1 || target==0){
      if(target==0) return 1;
      return 0;
   }
   if(dp[n][target]!=-1) return dp[n][target];
   int f;
   if(target>=v[n]){
      f = countsubsetsum_memoization(v,dp,n-1,target-v[n])+countsubsetsum_memoization(v,dp,n-1,target);
   }
   else if(target<v[n]){
      f = countsubsetsum_memoization(v,dp,n-1,target);
   }
   dp[n][target] = f;
   return f;
}


int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   vector<int> v{1,1,2,3};
   int target=4;
   int n=v.size();
   vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
   cout<<countsubsetsum_memoization(v,dp,n-1,target)<<en;
   //printmatrix(dp);
   return 0;
}