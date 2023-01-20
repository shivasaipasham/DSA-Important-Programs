#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define en "\n"

int totalperm=0;

void print(string s,string osf){
    if(s.size()==0){
        totalperm++;
        cout<<osf<<en;
        return;
    }
    for(int i=0;i<s.size();i++){
        string ros=s.substr(0,i)+s.substr(i+1);
        print(ros,osf+s[i]);
    }
}

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   string n;
   cin>>n;
   print(n,"");
   cout<<"Total permutations are "<<totalperm;
   return 0;
}