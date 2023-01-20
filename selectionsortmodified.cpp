#include<bits/stdc++.h>
using namespace std;

void sort(int a[], int n){
    int min;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]<a[i]){
            swap(a[i],a[j]);
            }
        }
    }
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,key;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    sort(a,n);
    return 0;
}
