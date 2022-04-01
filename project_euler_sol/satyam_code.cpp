#include<bits/stdc++.h>
#define pii pair<int,int>
#define mn 1005
#define debug(x) cout<<#x<<" "<< x<<endl;

using namespace std;

int n,m;
pii A;
queue<pii> q;
int path[mn][mn];
int sol[mn][mn];
bool starting=true;
pii from[mn][mn];
int testing[mn][mn];


void retraced(pii initial){
   pii backtrack=from[initial.first][initial.second];
   if(backtrack==pii(0,0)) 
      return;
   if(backtrack.first==initial.first-1) 
      testing[backtrack.first][backtrack.second]=1;
   if(backtrack.second==initial.second-1)
      testing[backtrack.first][backtrack.second]=1;
   retraced(backtrack);
}

bool isSafe(pii check){
   int x=check.first;
   int y=check.second;
   if(  x >= 0 && x < n && y >= 0
        && y < m && path[x][y] >= 0){
      return true;
   }
   return false;
}

void check(pii start,pii end){
   int a=sol[start.first][start.second];
   int b=path[end.first][end.second];

   if( sol[end.first][end.second]<a+b && testing[end.first][end.second]!=1){
      from[end.first][end.second]=start;
      sol[end.first][end.second]=a+b;
   }
   else if(sol[end.first][end.second]<a+b){
      from[end.first][end.second]=start;
      sol[end.first][end.second]=a;
   }
   q.push(end);
         
}


void bfs(){
   while(!q.empty()){
      pii test=q.front();
      pii next;
      q.pop();
      if(starting){
         next=test; next.first++; 
         if(isSafe(next)) check(test,next);
         next=test;  next.second++;
         if(isSafe(next)) check(test,next);
      }
      else{
          next=test; next.first--;
          if(isSafe(next)) check(test,next);
          
          next=test; next.second--; 
          if(isSafe(next)) check(test,next);
      }
   }
}


int main(){
   cin>>n>>m;
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         cin>>path[i][j];
         sol[i][j]=0;
         testing[i][j]=0;
      }
   }
   q.push(make_pair(0,0));
   sol[0][0]=path[0][0];
   bfs();

   retraced({n-1,m-1});
   
   starting=false;
   q.push(make_pair(n-1,m-1));
   bfs();
   // for(int i=0;i<n;i++){
   //    for(int j=0;j<m;j++){
   //       cout<<sol[i][j]<<" ";
   //    }
   //    cout<<endl;
   // }
   // cout<<endl;
   // for(int i=0;i<n;i++){
   //    for(int j=0;j<m;j++){
   //       cout<<testing[i][j]<<" ";
   //    }
   //    cout<<endl;
   // }

   cout<<endl;
   cout<<sol[0][0];

}


/*

4 4
0 0 1 0
-1 0 1 0
0 0 0 1
0 1 0 0

4 4
0 0 0 1
1 0 0 0 
0 0 0 0 
0 0 0 0




/*