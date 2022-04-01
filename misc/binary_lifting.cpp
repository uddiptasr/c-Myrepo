#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>up;
int LOG=0;
int getKthAncestor(int node, int k) {
        for(int i=0;i<LOG && node>-1;i++){
            if(k & 1<<i){
            	cout<<node<<" "<<i<<endl;
                node=up[node][i];
            }
        }
        return node;
    }
int main(){
	int n=11;
	vector<int>parent={-1,0,0,1 ,1,2,2,3,7,8,9};
     	while((1<<LOG)<=n)
            LOG++;
        cout<<LOG<<endl;
        up=vector<vector<int>>(n,vector<int>(LOG));
        for(int i=0;i<n;i++){
            up[i][0]=parent[i];
        }
        for(int i=0;i<n;i++){  //i=10 
            for(int j=1;j<LOG;j++){ //j=2
                int &par=up[i][j-1];//i=
                up[i][j]=par>-1?up[up[i][j-1]][j-1]:-1;
            }
        }
         for(int i=0;i<n;i++){   
         	cout<<i<<" ";
            for(int j=0;j<LOG;j++){
                cout<<up[i][j]<<" ";
        	}
        	cout<<endl;
    	}
        cout<<getKthAncestor(10,5);
 }
    
/**   10- 1010  2^3 2^1  
 * 	  0101	 2^2 2^0
 *          0
 * 		  1  2 	 
 *       3 4  5 6
 *      7
 *     8
 *     9
 *     10
 * 
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 
["TreeAncestor","getKthAncestor","getKthAncestor","getKthAncestor"]
[[4,[-1,2,3,0]],[2,3],[2,2],[2,1]]
[null,-1,0,3]
 */