#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define en "\n"
// ¹²³⁴⁵⁶⁷⁸⁹⁰ ⁿ
// ₀₁₂₃₄₅₆₇₈₉ 



int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   vector<bool> primes(1e6+1,true);
   for(int i=2;i*i<1e6+1;i++){
       if(primes[i]){
           for(int j=i*i;j*j<1e6+1;j+=i){
               primes[j] = false;
           }
       }
   } 

   int t;
   cin>>t;
   ll ans=0;
   while(t--){
       ll n;
       cin>>n;
       
   }
   return 0;
}