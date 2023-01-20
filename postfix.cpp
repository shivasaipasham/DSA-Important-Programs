#include<bits/stdc++.h>
using namespace std;

int postfix(string s){
    stack<int> st;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }
        else{
            int op2=st.top();
            st.pop();
            int op1=st.top();
            st.pop();
            switch(s[i]){
                case '+': st.push(op1+op2);
                          break;
                case '-': st.push(op1-op2);
                          break;
                case '*': st.push(op1*op2);
                          break;
                case '/': st.push(op1/op2);
                          break;
                case '^': st.push(pow(op1,op2));
                          break;
                
            }
            //cout<<st.top()<<" ";
        }
    }
    return st.top();
}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cout<<postfix("46+2/5*7+");
    return 0;
}
