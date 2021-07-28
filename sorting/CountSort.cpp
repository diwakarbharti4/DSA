#include<bits/stdc++.h>
using namespace std;

int main(){
    int A[5]={1,4,3,1,4};
    int i,max=A[0]; 

    for(i=1;i<5;i++){
        if(A[i]>max)
            max=A[i];
    }
    int B[max+1];
    memset(B,0,sizeof(B));

    for(i=0;i<5;i++){
        int x= A[i];
        B[x]++;
    }
    int j=0;
    for(i=0;i<max+1;i++){
        if(B[i]>0){
            A[j]=i;
            B[i]--;
            i--;
            j++;
        }
    }
    for(i=0;i<5;i++)
    cout<<A[i]<<" ";
}