#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod =1000000007;
const ll n=1000005;
ll sep[n],join[n];

int main(){
   sep[0]=1;
   join[0]=1;
   for(int i=1;i<n;i++){
      sep[i]=4*sep[i-1]+join[i-1];
      sep[i]%=mod;
      join[i]=2*join[i-1]+sep[i-1];
      join[i]%=mod;
   }
   int t;
   cin>>t;
   while(t--){
      int a;
      cin>>a;
      ll ans=(sep[a-1]+join[a-1])%mod;
      cout<<ans<<'\n';
   }
   return 0;
}  