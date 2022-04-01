#include<bits/stdc++.h>
using namespace std;
std::vector<int> adj[100005];

bool dfs(int start){
	bool visited[100005]={0};
	vector<int>res;
	int count=0;
	queue<int>q;
	q.push(start);
	visited[start]=true;
	while(!q.empty()){
		int a=q.front();
		q.pop();
		for(int  i:adj[a]){
			if(!visited[i]){
				visited[i]=true;
				count++;
				res.push_back(i);
				q.push(i);
			}
			else if(visited[i] && start==i){
				cout<<count<<endl;
				for(auto i:res){
					cout<<i<<" ";
				}
				return true;
			}
		}
	}
	
	return false;
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[u].push_back(v);
	}
	for(int i=1;i<n+1;i++){
		if(dfs(i))
			break;
		else if(i==n){
			cout<<"IMPOSSIBLE";
		}
	}
	return 0;

}