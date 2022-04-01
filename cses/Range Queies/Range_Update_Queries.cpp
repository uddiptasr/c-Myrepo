#include<bits/stdc++.h>
using namespace std;
vector<long long>tree;

long long f(int node,int low,int high,int q_low,int q_high,int v){
	if(low>=q_low && high<=q_high)
	{  
		if(v!=-1){

			tree[node]+=v;
		}
		return tree[node];
	}
	if(low>q_high || high<q_low)
		return 0;
	int mid=(low+high)/2;
	
	long long sum=f(2*node,low,mid,q_low,q_high,v)+f(2*node+1,mid+1,high,q_low,q_high,v);
	return sum+tree[node];
}

int main(){
	int n,q;
	cin>>n>>q;
	vector<int>a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	while(__builtin_popcount(n)!=1){
		//a.push_back(0);
		n++;
	}
	tree.resize(2*n);
	for(int i=0;i<(int)a.size();i++){
		tree[n+i]=a[i];
	}
	// for(int i=n-1;i>=1;i--){
	// 	tree[i]=tree[2*i]+tree[2*i+1];
	// }
	while(q--){
		int type;
		cin>>type;
		if(type==1){
			int low,high,u;
			cin>>low>>high>>u;
			low--;
			high--;
			cout<<f(1,0,n-1,low,high,u);
			
		}
		else{ //value at pos k
			int k;
			cin>>k;
			k--;
			cout<<f(1,0,n-1,k,k,-1)<<"\n";
		}	
	}

}
/*

8 3
3 2 4 5 1 1 5 3
2 4
1 2 5 1
2 4

*/