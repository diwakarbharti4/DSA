#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int A[n],i,j;
    cout<<"Enter Data for array  "<< endl;
    for(i=0;i<n;i++)
        cin>>A[i];
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(A[i]>A[j]){
                int a=A[i];
                A[i]=A[j];
                A[j]=a;
            }
        }
    }
    cout<<"Sorted Array is"<<endl;
    for(i=0;i<n;i++)
        cout<<A[i]<<" ";

}