#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define en "\n"

void braces(int n,int open,int close,int i,string temp){
    if(i==n){
        cout<<temp<<en;
        return;
    }
    if(open<n/2){
        cout<<"entered open "<<open<<" "<<close<<" "<<temp<<en;
        braces(n,open+1,close,i+1,temp+'(');
        cout<<"return after open "<<open<<" "<<close<<" "<<temp<<en;
    }
    cout<<"came here "<<open<<" "<<close<<" "<<en;
    if(close<open){
        cout<<"entered close "<<open<<" "<<close<<" "<<temp<<en;
        braces(n,open,close+1,i+1,temp+')');
        cout<<"return after close "<<open<<" "<<close<<" "<<temp<<en;
    }

}

void allbraces(int n,int i,string temp){
    if(i==n){
        cout<<temp<<en;
        return;
    }
    allbraces(n,i+1,temp+'(');
    allbraces(n,i+1,temp+')');
}

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   braces(4,0,0,0,"");
   return 0;
}