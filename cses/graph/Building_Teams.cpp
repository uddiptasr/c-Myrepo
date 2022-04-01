#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100005];
bool vis[100005];
int col[100005];
queue<int>q;

bool bfs(int s){	
	vis[s]=1;
	q.push(s);
	col[s]=1;
	while(!q.empty()){
		int a=q.front();
		q.pop();
		for(auto i:adj[a]){
			if(col[i]==col[a])
				return 0;
			if(vis[i]) continue;
			vis[i]=true;
			col[i]=(col[a]==1?2:1);
			q.push(i);
		}
	}
	return 1;
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1;i<n+1;i++){
		if(!vis[i]){
			if(!bfs(i)){
				cout<<"IMPOSSIBLE";
				return 0;;
			}
		}
	}
	for(int i=1;i<n+1;i++){
		cout<<col[i]<<" ";
	}

}