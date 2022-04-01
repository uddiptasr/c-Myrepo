#include<bits/stdc++.h>
using namespace std;
struct vertex{
    int value;
    int index;
};
const int MAXN=200005;
vertex tree[4*MAXN];
#define inf -1e9+7;

void buildSegmentTree(int a[],int v,int l,int r){
    if(l==r){
        tree[v].value=a[l];
        tree[v].index=l+1;
        return;
    }
    int mid=(l+r)/2;
    buildSegmentTree(a,2*v,l,mid);
    buildSegmentTree(a,2*v+1,mid+1,r);
    if(tree[2*v].value>tree[2*v+1].value){
        tree[v]=tree[2*v];
    }
    else{
        tree[v]=tree[2*v+1];
    }
}
int query(int v,int l,int r,int num){
    if(tree[v].value<num)
        return 0;
    if(l==r){
        tree[v].value=tree[v].value-num;
        return tree[v].index;
    }
    int mid=(l+r)/2;
    if(tree[2*v].value>=num){
        int idx=query(2*v,l,mid,num);
        if(tree[2*v].value>=tree[2*v+1].value){
            tree[v]=tree[2*v];
        }
        else
                    tree[v]=tree[2*v+1];
        }
        return idx;
    }
    else{
      int idx=query(2*v+1,mid+1,r,num);
        if(tree[2*v].value>=tree[2*v+1].value){
            tree[v]=tree[2*v];
        }
        else{
            tree[v]=tree[2*v+1];
        }
         return idx;

    }
}

int main(){
    int n,m;
    cin>>n>>m;
    int h[n],r[m];
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    for(int i=0;i<m;i++){
        cin>>r[i];
    }
    buildSegmentTree(h,1,0,n-1);
    for(int i=0;i<m;i++){
        cout<<query(1,0,n-1,r[i])<<" ";
    }

}