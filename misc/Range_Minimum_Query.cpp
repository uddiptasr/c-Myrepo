#include<bits/stdc++.h>
using namespace std;

const int MAX_N=100005;
const int LOG=17;
int a[MAX_N];
int m[MAX_N][LOG];
int ben_log[MAX_N];

int query(int L,int R)
{
    int len=R-L+1;
    int K=ben_log[len];
    return min(m[L][K],m[R-(1<<K)+1][K]);

    /* l  -16  
         16  +   R
         R-k+1  
    */
}

int main(){
    int n;
    cin>>n;
    ben_log[1]=0;
    for(int i=2;i<=n;i++){
        ben_log[i]=ben_log[i/2]+1;
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
        m[i][0]=a[i];
    }
    for(int k=1;k<LOG;k++){
        for(int i=0;i + (1<<k) - 1<n;i++){ ///cheking if the range gets out of bound
            m[i][k]=min(m[i][k-1],m[i+(1<<(k-1))][k-1]);
        }
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        cout<<query(l,r)<<"\n";
    }
    return 0;

}
