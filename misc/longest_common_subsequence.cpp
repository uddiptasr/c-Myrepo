#include<bits/stdc++.h>
using namespace std;
int iterativeDp(string t1,string t2,int n,int m){
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 if(t1[i]==t2[j]){
                    cout<<i<<j<<endl;
                    cout<<t1[i]<<t2[j];
                    dp[i+1][j+1]=1+dp[i][j];

                }
                else{
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               cout<<dp[i][j]<< " ";
            }
            cout<<endl;
        }
       return dp[n][m];
}
int lcs( string X, string Y, int m, int n )
{
    int L[m+1][n+1];
    int i, j;
     for (i=0; i<=m; i++)
    {
        for (j=0; j<=n; j++)
        {
        if (i == 0 || j == 0)
            L[i][j] = 0;
     
        else if (X[i-1] == Y[j-1])
            L[i][j] = L[i-1][j-1] + 1;
     
        else
            L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    return L[m][n];

}
int main() {
    string text1,text2;
    text1="AGGTAB";
    text2="GXTXAYB";
        int n=text1.length();
        int m=text2.length();
        cout<<iterativeDp(text1,text2,n,m)<<endl;
        cout<<lcs(text1,text2,n,m);
        return 0;
    
 }