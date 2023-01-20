#include<iostream>
using namespace std;

class demo{
    public:
    demo(){
        cout<<"Constructor"<<en;
    }
    void method1(){
        cout<<"Method1"<<en;
    }
    void method2(){
        cout<<"Method2"<<en;
    }
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    demo obj;
    obj.method1();
    obj.method2();
    return 0;
}

