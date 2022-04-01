// sumEqual check wheather i is equal to the total(sum)-i
#include<bits/stdc++.h>
using namespace std;
int n,m;
void solve(vector<vector<char>> &board,int i,int j){
    if(i>=n || j>=m ||i<0 || j<0)
        return;
    if(board[i][j]=='X'){
        board[i][j]='0';
        solve(board,i,j-1);
        solve(board,i-1,j);
        solve(board,i,j+1);
        solve(board,i+1,j);
    }
    return;
}
int main(){
    vector<vector<char>>board= 
       { {'X','O','O','X','O','O','O'},
        {'X','X','O','O','O','X','O'},
        {'O','X','O','O','O','X','O'}};
         n=board.size();
         m=board[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X'){
                    count+=1;
                    solve(board,i,j);
                }
            }
        }
        cout<<count<<endl;
}