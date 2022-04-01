#include<bits/stdc++.h>
using namespace std;
vector<long long>tree;

long long f(int node,int low,int high,int q_low,int q_high){
	if(low>=q_low && high<=q_high)
		return tree[node];
	if(low>q_high || high<q_low)
		return 0;
	int mid=(low+high)/2;
	return f(2*node,low,mid,q_low,q_high)+f(2*node+1,mid+1,high,q_low,q_high);
}
void update(int n,int pos,int u){
	tree[n+pos]=u;
	for(int i=(n+pos)/2;i>=1;i/=2){
		tree[i]=tree[2*i]+tree[2*i+1];
	}
}

int main(){
	int n,q;
	cin>>n>>q;
	vector<int>a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	while(__builtin_popcount(n)!=1){
		a.push_back(0);
		n++;
	}
	tree.resize(2*n);
	for(int i=0;i<n;i++){
		tree[n+i]=a[i];
	}
	for(int i=n-1;i>=1;i--){
		tree[i]=tree[2*i]+tree[2*i+1];
	}
	for(int i=0;i<q;i++){
		int type;
		cin>>type;
		if(type==1){
			int pos,u;
			cin>>pos>>u;
			pos--;
			update(n,pos,u);
		}
		else{
			int low,high;
			cin>>low>>high;
			low--;
			high--;
			cout<<f(1,0,n-1,low,high)<<"\n";
		}	
	}
	return 0;


}
/*
8 4
3 2 4 5 1 1 5 3
2 1 4
2 5 6
1 3 1
2 1 4



*/