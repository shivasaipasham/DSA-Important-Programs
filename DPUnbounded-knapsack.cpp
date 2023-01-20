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

int knapsack_memoization(vector<int> &weights,vector<int> &values,vector<vector<int>> &dp,int n,int capacity){
   if(n==-1 || capacity==0) return 0;
   if(dp[n][capacity]!=-1) return dp[n][capacity];
   if(capacity>=weights[n])
   dp[n][capacity] = max(values[n]+knapsack_memoization(weights,values,dp,n,capacity-weights[n]),
                                                                              knapsack_memoization(weights,values,dp,n-1,capacity));
   else if(capacity<weights[n])
   dp[n][capacity] = knapsack_memoization(weights,values,dp,n-1,capacity);
   return dp[n][capacity];
}

int knapsack_tabulation(vector<int> &weights,vector<int> &values,int n,int capacity){
   vector<vector<int>> dp(n+1,vector<int>(capacity+1,0));
   for(int i=1;i<=n;i++){
      for(int j=1;j<=capacity;j++){
         if(j<weights[i-1]){
            dp[i][j] = dp[i-1][j];
         }
         else{
            dp[i][j] = max(dp[i-1][j], values[i-1] + dp[i][j-weights[i-1]]); 
            //cout<<i<<" "<<j<<en;
         }
      }
   }
   //printmatrix(dp);
   return dp[n][capacity];
}


int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   vector<int> weights{52,89,6,53,17};
   vector<int> values{298,123,882,566,337};
   int capacity=106;
   vector<vector<int>> dp(values.size()+1,vector<int>(capacity+1,-1));
   cout<<knapsack_memoization(weights,values,dp,weights.size()-1,capacity)<<en;
   cout<<knapsack_tabulation(weights,values,weights.size(),capacity)<<en;
   //printmatrix(dp);
   return 0;
}