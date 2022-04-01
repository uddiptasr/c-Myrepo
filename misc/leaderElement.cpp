#include<bits/stdc++.h>
using namespace std;

vector<int> findL(vector<int> &arr){
	int n=arr.size();
	int lastL=arr[n-1];
	vector<int> res;
	res.push_back(arr[n-1]);
	for(int i=n-2;i>=0;i--){
		if(arr[i]>lastL){
			res.push_back(arr[i]);
			lastL=arr[i];
		}	
	}
	return res;
}
int main(){
	vector<int> arr;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		arr.push_back(a);
	}

	vector<int> ans;
	ans=findL(arr);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
}
//{16, 17, 4, 3, 5, 2};