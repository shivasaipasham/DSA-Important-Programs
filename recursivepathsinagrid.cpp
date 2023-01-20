#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define en "\n"
int c=0;
void print(int n,int m,int x,int y,string path){
    if(x==n-1 && y==m-1){
        cout<<path<<en;
        c++;
        return;
    }
    if(x<n-1)
    print(n,m,x+1,y,path+'R');//Right step
    if(y<m-1)
    print(n,m,x,y+1,path+'D');//Down step
    if(x<n-1 && y<m-1)
    print(n,m,x+1,y+1,path+"Di");//If you want to travel diagonally 
}


int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int n,m;
   cin>>n>>m;
   print(n,m,0,0,"");
   cout<<"number of ways are "<<c;
   return 0;
}