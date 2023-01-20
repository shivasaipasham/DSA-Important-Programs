#include<bits/stdc++.h>
using namespace std;
#define en "\n"


void merge(vector<int> &v,int low,int mid,int high){
    vector<int> temp;
    int i=low,j=mid+1;
    while(i<=mid && j<=high){
        if(v[i]<=v[j]){
            temp.push_back(v[i++]);
        }
        else{
            temp.push_back(v[j++]);
        }
    }
    while(i<=mid){
        temp.push_back(v[i++]);
    }
    while(j<=high){
        temp.push_back(v[j++]);
    }
    for(int k=low;k<=high;k++){
        v[k]=temp[k-low];
    }
    temp.clear();
}

void mergesort(vector<int> &v,int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergesort(v,low,mid);
        mergesort(v,mid+1,high);
        merge(v,low,mid,high);
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
    mergesort(v,0,n-1);
    cout<<"After sorting :"<<en;
    for(int x:v)
      cout<<x<<" ";
    
}