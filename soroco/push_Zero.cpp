/*# # 2) Given an array with positive
 and negative elements, 
push all the zero elements 
to back of array

*/
#include<bits/stdc++.h>
using namespace std;
vector<int>arr;
void pushZerosToEnd(vector<int>&arr,int n){
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            arr[count++]=arr[i];        
        }
    }
    while(count<n){
        arr[count++]=0;
    }
}
int main(){
    arr={1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
    int n=arr.size();
    pushZerosToEnd(arr,n);
    for(int a: arr)
        cout<<a<<" ";
}
