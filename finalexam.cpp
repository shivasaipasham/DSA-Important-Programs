#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define en "\n"

void printarray(vector<int> &v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}

class parent{
    public:
    void add(int a,int b){
        cout<<a+b<<en;
    }
    void add(int a,int b,int c){
        cout<<a+b+c<<en;
    }
};

class child: public parent{
    public:
    void subtract(int a,int b){
        cout<<a-b<<"\n";
    }
    void add(int a,int b){
        cout<<2*a+2*b<<en;
    }
};

int main() {
    ios_base::sync_with_stdio(0);   
    cin.tie(0);
    cout.tie(0);
    child obj;
    obj.add(1,2);
    //obj.add(1,2,3);
    return 0;
}
