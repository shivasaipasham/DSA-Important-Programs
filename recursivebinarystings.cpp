#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define en "\n"

//print all binary strings of size n with no consecutive 1's

int binarystrings(int n,int i,string temp,vector<int> dp){
    if(i==n){
        return 1;
    }
    if(dp[n]!=-1) return dp[n];
    int a = 0;
    a = binarystrings(n,i+1,temp+'0',dp);
    if(temp=="" || temp[i-1]!='1'){
        a+= binarystrings(n,i+1,temp+'1',dp);
    }
    dp[n] = a;
    return dp[n];
}



int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   vector<int> dp(4,-1);
   cout<<binarystrings(4,0,"",dp);
   return 0;
}