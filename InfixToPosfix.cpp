#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<char> opearator;
    string s;
    stack<char> stack;
    cout<<"Enter the infix"<<endl;
    cin>>s;
    int n=s.length();
    for(int i=0;i<n;i++){
        if(s[i]=='a'||s[i]=='b'||s[i]=='c'||s[i]=='d'||s[i]=='e')
            opearator.push_back(s[i]);
        else{
            if(s[i]=='+'||s[i]=='-'){
                if(stack.empty())
                    stack.push(s[i]);
                else{
                    opearator.push_back(stack.top());
                    stack.pop();
                    if(stack.empty())
                        stack.push(s[i]);
                    else{
                        opearator.push_back(stack.top());
                        stack.pop();
                        stack.push(s[i]);
                    }
                }
            }
            if(s[i]=='*'||s[i]=='/'){
                if(stack.empty()||stack.top()=='+'||stack.top()=='-')
                    stack.push(s[i]);
                else{
                    opearator.push_back(stack.top());
                    stack.pop();
                    stack.push(s[i]);
                }
            }
        }
    }
    int x=stack.size();
    for(int i=0;i<x;i++){
        opearator.push_back(stack.top());
        stack.pop();
    }
    for(int i=0;i<n;i++)
        cout<<opearator[i]<<" ";
}