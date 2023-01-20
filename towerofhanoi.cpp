#include<bits/stdc++.h>
using namespace std;

void toh(int n,char s,char d,char h){
    int cnt=0,a=n;
    if(n==0){
        return;
    }
    toh(n-1,s,h,d);
    cout<<"Move "<<to_string(n)<<" from "<<s<<" to "<<d<<"\n";
    toh(n-1,h,d,s);
}
 


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<pow(2,n)-1<<"\n";
        toh(n,'A','C','B');
    }
    return 0;
}
