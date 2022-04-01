#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100005];
bool vis[100005];

void dfs(int i){
	if(vis[i])
		return;
	vis[i]=1;
	for(int a:adj[i]){
		dfs(a);
	}
}



int main(){
	int n ,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int>res;
	for(int i=1;i<n+1;i++){
		if(!vis[i]){
			res.push_back(i);
			dfs(i);
		}
	}

	cout<<res.size()-1<<endl;
	for(int i=1;i<res.size();i++){
		cout<<res[i]<<" "<<res[i-1]<<endl;
	}

}