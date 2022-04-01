#include <bits/stdc++.h>
#define pii pair<int,int>
#define mn 1005

using namespace std;
//#define debug(x) cout<<#x<<" "<< x<<endl;
//#define int  long long 

int n,m;
pii A;
queue<pii> q;
pii from[mn][mn];
int path[mn][mn];
int infinte=INT_MAX;
bool possible=false;
string result;

void retraced(pii initial){
	pii backtrack=from[initial.first][initial.second];
	if(backtrack==pii(0,0)) return;
	if(backtrack.first==initial.first+1) result.push_back('U');
	if(backtrack.first == initial.first-1) result.push_back('D');
	if(backtrack.second == initial.second+1) result.push_back('L');
	if(backtrack.second==initial.second-1) result.push_back('R');
	retraced(backtrack);

}
void check(pii start,pii end){
	int p=path[start.first][start.second];

	if(p+1 < (path[end.first][end.second])){

		path[end.first][end.second]=p+1;
		q.push(end);
		from[end.first][end.second]=start;
	}

}
bool  NOTmonster=false;
void bfs(){
	while(!q.empty()){
	pii test =q.front(),next;
	q.pop();
	next=test ; next.first++; check(test,next);	
	next=test ; next.first--; check(test,next);
	next=test ; next.second++; check(test,next);
	next=test ; next.second--; check(test,next);
	if(NOTmonster && (test.first==1 || test.second==1 || test.first==n || test.second==m))
	{
		cout<<"YES"<<endl;
		cout<<path[test.first][test.second]<<endl;
		retraced(test);
		possible=true;
		return;
	}
}

}


int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string s;
		cin>> s;
		for(int j=1; j<=m; j++){
			path[i][j]= infinte;
			if(s[j-1]=='#') path[i][j]=0;
			if(s[j-1]=='M') {
				q.push(make_pair(i,j));
				path[i][j] = 0;
			 }
			if(s[j-1]=='A'){A.first = i; A.second = j;}	 ///a.first=i,a.second=j
			
		}
	}
	bfs();
	NOTmonster=true;
	from[A.first][A.second]=make_pair(0,0);
	path[A.first][A.second]=0;
	q.push(A);
	bfs();
	if(possible){
		reverse(result.begin(), result.end());
		cout<<result<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}

}


