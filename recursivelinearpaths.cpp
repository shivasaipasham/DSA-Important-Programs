#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define en "\n"

int totalways=0;

void print(int n,int k,string path){
    if(k==n){
        cout<<path<<en;
        totalways++;
        return;
    }
    if(k+1<=n)
    print(n,k+1,path+"1 ");
    if(k+2<=n)
    print(n,k+2,path+"2 ");
    if(k+3<=n)
    print(n,k+3,path+"3 ");
    if(k+4<=n)
    print(n,k+4,path+"4 ");
    if(k+5<=n)
    print(n,k+5,path+"5 ");
    if(k+6<=n)
    print(n,k+6,path+"6 ");

    //instead of line 14 to 26 we can use a for loop from line 28 to 31 
   // if(k>n)
    //return;
    //for(int i=1;i<=n;i++)
    // print(n,k+i,path+to_string(i)+"->");

}





int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int n;
   cin>>n;
   print(n,0,"");
   cout<<"Total ways are "<<totalways;
   return 0;
}