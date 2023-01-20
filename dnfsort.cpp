#include<bits/stdc++.h>
using namespace std;




int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int n;
   cin>>n;
   vector<int> v(n);
   for(int &x:v){
       cin>>x;
   }
   int low=0,mid=0,high=n-1;
   while(mid<=high){
       if(v[mid]==0){
           swap(v[low++],v[mid++]);
       }
       else if(v[mid]==1){
           mid++;
       }
       else{
           swap(v[mid],v[high--]);
       }
   }
   for(int x:v)
   cout<<x<<" ";
}