//# {16, 17, 4, 3, 5, 2}, leaders are 17, 5 and 2.
#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={16, 17, 4, 3, 5, 2};
    int l=6;
    int leader=arr[5];
    vector<int>res;
    res.push_back(leader);
    for(int i=4;i>=0;i--){
        if(arr[i]>leader)
        {
            leader=arr[i];
            res.push_back(leader);

        }
    }
    reverse(res.begin(),res.end());
    for(int a:res){
        cout<<a<<" ";
    }
}