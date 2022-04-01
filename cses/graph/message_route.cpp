#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>adj(n+1);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	vector<int>dist(n+1,0),parent(n+1);
	vector<bool>visited(n+1);
	queue<int>q;
	q.push(1);
	dist[1]=0;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(auto a: adj[x]){
			if(!visited[a]){
				visited[a]=true;
				dist[a]=dist[x]+1;
				parent[a]=x;
				q.push(a);	
			}
		}
	}
	if(!visited[n])
	{
		cout<<"IMPOSSIBLE";
	}
	else
	{	cout<<dist[n]+1<<' '<<endl;
		vector<int>res;
		res.pb(n);
		while(res.back()!=1){
				res.pb(parent[res.back()]);
			}

			reverse(begin(res),end(res));
			for(int t:res)
			cout<<t<<" ";
					
	}

}