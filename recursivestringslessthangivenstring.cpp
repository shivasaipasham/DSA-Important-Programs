#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define en "\n"

void generatestrings(vector<string> &ans,string s,string osf){
   if(osf.size()==s.size() && osf<s){
      ans.push_back(osf);
      return;
   }
   if(osf>s || osf.size()>s.size())
   return;
   for(int i=97;i<=122;i++){
      generatestrings(ans,s,osf+char(i));
   }
}


int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   string s;
   cin>>s;
   vector<string> ans;
   generatestrings(ans,s,"");
   for(string str:ans)
   cout<<str<<"\n";
   return 0;
}