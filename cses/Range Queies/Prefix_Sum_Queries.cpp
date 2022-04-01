#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
struct Node{
	long long sum;
	long long prefix;
};
Node tree[4*MAXN];
const int N=2e5;
int a[N];

void build(int v,int l,int r)
{
	if(l==r){
		tree[v].prefix=tree[v].sum=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(2*v,l,mid);
	build(2*v+1,mid+1,r);
	tree[v].sum=tree[2*v].sum+tree[2*v+1].sum;
	tree[v].prefix=max(tree[2*v].prefix  ,  tree[2*v].sum + tree[2*v +1].prefix);
}
void update(int n,int pos,int u){
		tree[n+pos].sum=tree[n+pos].prefix =a[n+pos] =u;
		for(int i=(n+pos)/2;i>=1;i/=2){
			tree[i].sum=tree[2*i].sum+tree[2*i+1].sum;
			tree[i].prefix=max(tree[2*i].prefix  ,  tree[2*i].sum + tree[2*i+1].prefix);
		}
}
void update1(int v,int s,int e,int qi,int val){
	if(qi<s || qi>e) return;
	if(s==e &&  s==qi){
		tree[v].sum=tree[v].prefix=a[s]=val;
		return;
	}
	int mid=(s+e)/2;
	
	update1(2*v,s,mid,qi,val);
	update1(2*v+1,mid+1,e,qi,val);

	tree[v].sum=tree[2*v].sum+tree[2*v+1].sum;
	tree[v].prefix=max(tree[2*v].prefix  ,  tree[2*v].sum + tree[2*v+1].prefix);
}
Node query(int v,int l,int r,int qleft,int qright){
	if(l>=qleft && r<=qright)
		return tree[v];
	if(r<qleft || l>qright)
		{
			Node temp;
			temp.prefix=temp.sum=0;
			return temp;
		}
	int mid=(l+r)/2;
	Node left=query(2*v,l,mid,qleft,qright);
	Node right=query(2*v+1,mid+1,r,qleft,qright);
	Node res;
	res.sum=left.sum+right.sum;
	res.prefix=max(left.prefix,left.sum+right.prefix);
	return res;
}

int main(){
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	build(1,0,n-1);
	while(q--){
		int type,a,b;
		cin>>type>>a>>b;
		if(type==1){
			//update(n,a,b);
			a--;
			update1(1,0,n-1,a,b);
		}
		else{
			a--;
			b--;
			cout<<max(0LL,query(1,0,n-1,a,b).prefix)<<endl;
		}
	}
}
/*
8 4
1 2 -1 3 1 -5 1 4
2 2 6
1 4 -2
2 2 6
2 3 4
*/