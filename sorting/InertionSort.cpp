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
    for(i=1;i<n;i++){
        for(j=i;j>=0;j--){
            if(A[j]<A[j-1]){
                int x=A[j];
                A[j]=A[j-1];
                A[j-1]=x;
            }
        }
    }

    cout<<"Sorted Array is"<<endl;
    for(i=0;i<n;i++)
        cout<<A[i]<<" ";

}