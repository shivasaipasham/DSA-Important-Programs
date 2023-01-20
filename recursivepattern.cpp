#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define en "\n"

void pattern1(int n,int i,int k){
    if(n==k) return;
    if(i<=k){
        cout<<"* ";
        pattern1(n,i+1,k);
    }
    else{
        cout<<en;
        pattern1(n,0,k+1);
    }
}

void pattern2(int n,int i){
    if(n==0) return;
    if(i<n){
        cout<<"* ";
        pattern2(n,i+1);
    }
    else{
        cout<<en;
        pattern2(n-1,0);
    }
}


int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   pattern1(5,0,0);
   cout<<en;
   pattern2(5,0);
   return 0;
}