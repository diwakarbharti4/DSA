#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int A[n],i;
    cout<<"Enter Data for array  "<< endl;
    for(i=0;i<n;i++)
        cin>>A[i];
    for(int j=0;j<n-1;j++){
        for(i=0;i<n-1;i++){
            if(A[i]>A[i+1]){
                int a=A[i];
                A[i]=A[i+1];
                A[i+1]=a;
            }
        }
    }
    cout<<"Sorted Array is"<<endl;
    for(i=0;i<n;i++)
        cout<<A[i]<<" ";

}