#include<bits/stdc++.h>
using namespace std;

void sort(int a[], int n){
     for(int i=1;i<n;i++){
        int j=i-1;
        int current=a[i];
        while(a[j]>current && j>=0){
            a[j+1]=a[j];
            j--;
        } 
        a[j+1]=current;
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

