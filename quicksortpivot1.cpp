#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define en "\n"

int partition(vector<int> &v,int l,int r){
    int i=l,j=r,pivot=v[l];
    while(i<j){
        while(v[i]<=pivot){
            i++;
        }
        while(v[j]>pivot){
            j--;
        }
        if(i<j){
            swap(v[i],v[j]);
        }
    }
    swap(v[l],v[j]);
    return j;
}


void quicksort(vector<int> &v,int l,int r){
    if(l<r){
        int pi=partition(v,l,r);
        quicksort(v,l,pi-1);
        quicksort(v,pi+1,r);
    }
}


int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int n;
   cin>>n;
   vector<int> v(n);
   for(int &x:v)
   cin>>x;
   quicksort(v,0,n-1);
   for(int x:v)
   cout<<x<<" ";
}