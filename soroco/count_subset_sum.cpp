// subset sum {2,4,6,10}
#include<bits/stdc++.h>
using namespace std;
int dp[2000][2000];
int subset(int set[],int n,int sum){
    if(sum==0)
        return 1;
    if(n==0)
        return 0;
    if(dp[n-1][sum]!=-1){
        return dp[n-1][sum];
    }
    if(set[n-1]>sum){
        return dp[n-1][sum]=subset(set,n-1,sum);
    }
    return dp[n-1][sum]=subset(set,n-1,sum)+subset(set,n-1,sum-set[n-1]);
}
int main(){
    memset(dp,-1,sizeof(dp));
    int set[]={1, 1, 1, 1 };
    int sum=1;
    int n=sizeof(set)/sizeof(set[0]);
    cout<<subset(set,n,sum);
}