#include <bits/stdc++.h>
using namespace std;
int n,m;
bool vis[1000][1000];
char a[1000][1000];

int parent[1000][1000];
//0 =up 1=right 2 down 3 left
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
string stepdir="URDL";


int main(){
	cin>>n>>m;
	pair<int,int>begin,end;
	queue<pair<int,int >>q;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
			if(a[i][j]=='A')
				begin=make_pair(i,j);
			if(a[i][j]=='B')
				end=make_pair(i,j);
		}
	}
	q.push(begin);
	vis[begin.first][begin.second]=true;
	while(!q.empty())
	{
		pair<int,int> u=q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			pair<int,int>v=make_pair(u.first +dx[i],u.second +dy[i]);
			if(v.first<0 || v.first>=n || v.second<0 || v.second>=m )continue;
			if(a[v.first][v.second]=='#')continue;
			if(vis[v.first][v.second])continue;
				parent[v.first][v.second]=i;
				vis[v.first][v.second]=true;
				q.push(v);	
			}
		}
	
	if(vis[end.first][end.second]){
		cout<<"YES"<<endl;
		vector<int>res;
		while(end!=begin){
			int  a=parent[end.first][end.second];	
			res.push_back(a);
			end=make_pair(end.first-dx[a],end.second-dy[a]);
		}
		reverse(res.begin(),res.end());
		cout<<res.size()<<endl;
		for(auto c:res){
			cout<<stepdir[c];
		}	
		cout<<endl;
	}
	else
		cout<<"NO"<<endl;

return 0;
}