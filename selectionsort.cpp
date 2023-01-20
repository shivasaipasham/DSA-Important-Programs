#include<bits/stdc++.h>
using namespace std;

void sort(int a[], int n){
    int min;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(j==i)
            min=j;
            else if(a[min]<a[j])
            min=j;
        }
        swap(a[i],a[min]);
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

