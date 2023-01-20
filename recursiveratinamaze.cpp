#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define en "\n"


string ratinamaze(vector<vector<bool>> v,int x ,int y,string osf){
   if(x==v.size()-1 && y==v.size()-1){
      return osf;
   }
   if(x<0 || x>=v.size() || y<0 || y>=v.size())
      return "";
   if(v[x][y]==0)
      return "";
   string str = ratinamaze(v,x,y+1,osf+'R');
   if(str!="")
      return str;
   return ratinamaze(v,x+1,y,osf+'D');
}

void norratinamaze(vector<vector<bool>> v,int x ,int y,string osf){
   if(x==v.size()-1 && y==v.size()-1){
      cout<<osf;
      return;
   }
   if(x<0 || x>=v.size() || y<0 || y>=v.size())
      return;
   if(v[x][y]==0)
      return;
   norratinamaze(v,x,y+1,osf+'R');
   norratinamaze(v,x+1,y,osf+'D');
}

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   vector<vector<bool>> v{{1,0,0,0},
                          {1,1,0,1},
                          {0,1,0,0},
                          {1,1,1,1}};   
   string op=ratinamaze(v,0,0,"");
   cout<<op<<en;
   norratinamaze(v,0,0,"");
   return 0;
}