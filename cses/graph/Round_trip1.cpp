#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector<int>adj[100005];
bool visited[100005];
vector<int>res;

bool dfs(int s,int p){ //s =start ,p=parent
	visited[s]=1;
	for(auto i:adj[s]){
		res.push_back(i);
		if(!visited[i])
		{
			if(dfs(i,s))
				return 1;
		}
		else if(i!=p)
			return 1;
		res.pop_back();
	}
	return 0;
}
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=1;i<n+1;i++){
		res.push_back(i);
		if(!visited[i] && dfs(i,0)){
			vector<int>ans={*res.rbegin()};
			for(auto j=res.rbegin()+1;j!=res.rend();j++){
				ans.push_back(*j);
				 if(*j==*res.rbegin()) break;
			}
			cout<<ans.size()<<endl;
			for(auto i:ans){
				cout<<i<<" ";
			}
			return;		}
		res.pop_back();
	}
	cout<<"IMPOSSIBLE";
}

int main(){
	IOS;
	solve();
	return 0;
}