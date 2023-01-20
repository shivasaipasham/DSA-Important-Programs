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

int rodcutting_memoization(vector<int> &lengths,vector<int> &prices,vector<vector<int>> &dp,int n,int capacity){
   if(n==-1 || capacity==0) return 0;
   if(dp[n][capacity]!=-1) return dp[n][capacity];
   if(capacity>=lengths[n])
   dp[n][capacity] = max(prices[n]+rodcutting_memoization(lengths,prices,dp,n,capacity-lengths[n]),
                                                                              rodcutting_memoization(lengths,prices,dp,n-1,capacity));
   else if(capacity<lengths[n])
   dp[n][capacity] = rodcutting_memoization(lengths,prices,dp,n-1,capacity);
   return dp[n][capacity];
}

int rodcutting_tabulation(vector<int> &lengths,vector<int> &prices,int n,int capacity){
   vector<vector<int>> dp(n+1,vector<int>(capacity+1,0));
   for(int i=1;i<=n;i++){
      for(int j=1;j<=capacity;j++){
         if(j<lengths[i-1]){
            dp[i][j] = dp[i-1][j];
         }
         else{
            dp[i][j] = max(dp[i-1][j], prices[i-1] + dp[i][j-lengths[i-1]]); 
            //cout<<i<<" "<<j<<en;
         }
      }
   }
   printmatrix(dp);
   return dp[n][capacity];
}


int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   vector<int> lengths{1,2,3,4};
   vector<int> prices{2,365,882,1000};
   int capacity=4;
   vector<vector<int>> dp(prices.size()+1,vector<int>(capacity+1,-1));
   //cout<<rodcutting_memoization(lengths,prices,dp,lengths.size()-1,capacity)<<en;
   cout<<rodcutting_tabulation(lengths,prices,lengths.size(),capacity)<<en;
   //printmatrix(dp);
   return 0;
}