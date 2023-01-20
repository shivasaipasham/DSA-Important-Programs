#include<bits/stdc++.h>
using namespace std;
#define en "\n"

int partition(vector<int> &v,int l,int r){
    int i=l-1,pivot=v[r];
    for(int j=l;j<r;j++){
        if(v[j]<pivot){
            i++;
            swap(v[i],v[j]);
        }
    }
    swap(v[i+1],v[r]);
    return i+1;
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
    cout<<"Before sorting :"<<en;
    for(int x:v)
      cout<<x<<" ";
    cout<<en;
    quicksort(v,0,n-1);
    cout<<"After sorting :"<<en;
    for(int x:v)
      cout<<x<<" ";
}