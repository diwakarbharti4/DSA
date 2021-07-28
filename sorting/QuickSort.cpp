#include<bits/stdc++.h>
using namespace std;
void swap(int &a,int &b){
    int x=a;
    a=b;
    b=x;
}
void print(int A[],int n){
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<"\n";
}
int QS(int A[],int str,int end){
    int piv=end;
    print(A,6);
    if(piv==0|| str==end||end<str) 
        return 1;
    for(int i=str;i<end;i++){
        if(A[i]>A[piv]){
            swap(A[i],A[piv-1]);
            swap(A[piv],A[piv-1]);
            piv--;
            i--;
        }
        if(i==piv) break;
    }

return QS(A,str,piv-1) +QS(A,piv+1,end);
};

int main(){
    int A[]={4,1,2,5,3,6};
    QS(A,0,5);  
    cout<<"Sorted Array is"<<endl;
    for(int i=0;i<6;i++)
        cout<<A[i]<<" ";
     
}