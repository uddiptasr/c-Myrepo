// sumEqual check wheather i is equal to the total(sum)-i
#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={16, 23, 4, 3, 5, 2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int total=0;
    for(int i=0;i<n;i++){
        total+=arr[i];
    }
    
    vector<int>res;
    cout<<total-23;
    for(int i=0;i<n;i++){
        if(arr[i]==total-arr[i])
        {
            res.push_back(arr[i]);
        }
    }
    if(res.size()>0){
    for(int a:res){
        cout<<a<<" ";
    }
}
else 
    cout<<-1;
}