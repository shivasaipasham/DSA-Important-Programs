#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define en "\n"
// ⁰¹²³⁴⁵⁶⁷⁸⁹ ⁿ ⁿ*ᵐ
// ₀₁₂₃₄₅₆₇₈₉ 

void printmatrix(vector<vector<int>> &v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<en;
    }
}

void printarray(vector<int> &v){
   for(int i=0;i<v.size();i++){
      cout<<v[i]<<" ";
   }
   cout<<en;
}


int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   return 0;
}