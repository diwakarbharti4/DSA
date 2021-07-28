#include<bits/stdc++.h>
using namespace std;

void merging(int A[],int mid,int low,int high){
    int B[high+1];
    int i=low,j=mid+1,k=low;
    while(i<=mid && j<=high){
        if(A[i]<A[j]){
            B[k]=A[i];
            i++,k++;
        }
        if(A[i]>=A[j]){
            B[k]=A[j];
            j++,k++;
        }
           
    }
    while(i<=mid){
        B[k]=A[i];
            i++,k++;
    }
    while(j<=high){
        B[k]=A[j];
        k++,j++;
    }    
    for(i=low;i<=high;i++)
        A[i]=B[i];
};

void MergeSort(int A[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,high);
        merging(A,mid,low,high);

    }
};
int main(){
    int A[]={4,1,2,5,3,6};
    MergeSort(A,0,5);  
    cout<<"Sorted Array is"<<endl;
    for(int i=0;i<6;i++)
        cout<<A[i]<<" ";
}