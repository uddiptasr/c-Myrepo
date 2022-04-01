#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" "<< x<<endl;
struct Node{
	int data;
	struct Node* left;
	struct Node* right;
	Node(int val){
		data=val;
		left=NULL;
		right=NULL;
	}
};
/*
void levelordertransversal(Node* root){
	if(root==NULL){
		return;
	}
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		Node* node=q.front();
		q.pop();
		if(node!=NULL){
			cout<<node->data<<" ";
			if(node->left){
				q.push(node->left);

			}
			if(node->right){
				q.push(node->right);

			}

		}
		else if(!q.empty()){
			q.push(NULL);
		}
	}
}
int  sum_of_kth_level(Node* root,int val){
	if(root==NULL){
		return -1;
	}
	queue<Node*> q;
	int level=1;
	int cnt=0;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		Node* node=q.front();
		q.pop();
		if(node!=NULL){
			//cout<<node->data<<" ";
			if(node->left){
				q.push(node->left);

			}
			if(node->right){
				q.push(node->right);

			}
			if(level==3){
				cnt=cnt+node->data;
			}


		}
		else if(!q.empty()){
			q.push(NULL);
			level++;
		}
	}

	return cnt;

}

int node_sum(Node* root){
	if(root==NULL)
		return 0;
	return node_sum(root->left)+node_sum(root->right)+root->data;
}

void non_recursive_node_sum(Node* root)
{
	if(root==NULL){
		return;
	}
	queue<Node*> q;
	q.push(root);
	int cnt=0;
	while(!q.empty())
	{
		Node* node=q.front();
		q.pop();
			
			cnt+=node->data;
			if(node->left){
				q.push(node->left);

			}
			if(node->right){
				q.push(node->right);

			}
	}
	cout<<cnt;

}
int calcheight(Node* root){
	if(root==NULL)
		return 0;
	int lheight=calcheight(root->left);
	int rheight=calcheight(root->right);
	return max(lheight,rheight) +1;
}

int calcDiameter(Node* root){
		cout<<"\n";

	if(root==NULL)
	{
		return 0;
	}
	int lheight=calcheight(root->left);
	int rheight=calcheight(root->right);
	int currDiameter =lheight+rheight +1;
	
	int ldiameter=calcDiameter(root->left);
	int rdiameter=calcDiameter(root->right);
	
	return max(currDiameter,max(ldiameter,rdiameter));

}
int sumplacement(Node* root){
	if(root==NULL)
		return 0;
	int lsum=sumplacement(root->left);
	int rsum=sumplacement(root->right);

	root->data+=lsum+rsum;
	return root->data;
}
void preorder(Node* root){
		if(root==NULL){
			return;
		}
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
}

bool balancedtree(Node* root,int* height){
	if(root==NULL)
	{  		
		return true;
	}
	int lh=0,rh=0;
	if(balancedtree(root->left,&lh)==false){
		return false;
	}
	if(balancedtree(root->right,&rh)==false){
		return false;
	}
	*height=max(lh,rh)+1;

	if(abs(lh-rh)<=1)
		return true;
	else
		return false;
}

void left_view_tree(Node* node){
	if(node==NULL){
		return;
	}
	queue<Node*> q;
	q.push(node);
	while(!q.empty())
	{
		int n=q.size();
		for(int i=0;i<n;i++){
			Node* temp=q.front();
			q.pop();
			if(i==0){
				cout<<temp->data<<' ';

			}
			if(temp->left!=NULL)
				q.push(temp->left);
			if(temp->right!=NULL)
				q.push(temp->right);
		}

	}
}
*/
/// 
	//////////distance from n1 to n2
////

///

////
Node* LCA(Node *root, int n1 ,int n2)
{
    // Your code here
    if (root == NULL)
       return NULL;
    if (root->data == n1 || root->data == n2)
       return root;
 
    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);
 
    if (left != NULL && right != NULL)
         return root;
    if (left == NULL && right == NULL)
        return NULL;
    if (left != NULL)
        return LCA(root->left, n1, n2);
 
    return LCA(root->right, n1, n2);
}

int findDist(Node  *root,int k,int dist){
	if(root==NULL)
		return -1;
	if(root->data ==k )
	{
		return dist;
	}
	int left=findDist(root->left,k, dist+1);
	if(left==-1)
	{
		return findDist(root->right,k,dist+1) ;
	}

	return left;
}

 

int distanceNodes(Node *root,int n1,int n2){
	Node* lca=LCA(root,n1,n2);

	int d1=findDist(lca,n1,0);
	int d2=findDist(lca,n2,0);
	return d1+d2;
}

////

////
////
///  flattten   a binary b  tree
//
//////

///

void flatten( Node* root ) {
	if(root==NULL || root->left==NULL && root->right==NULL)
			return;
		
		if(root->left!=NULL	){
			flatten(root->left);

			Node* temp=root->right;
			root->right=root->left;
			root->left=NULL;
			Node* t=root->right;
			while(t->right!=NULL){
				t=t->right;
	 		}
	 		t->right=temp;

  		}
  		flatten(root->right);

	
}

void inorderPrint(Node* root){
	if(root==NULL)
		return;
	inorderPrint(root->left);
	cout<<root->data<<" ";
	inorderPrint(root->right);
}
///
//
///
///
//
//

////print nodes to a distance from a given node
///


//
////
void printsubtree_distance(Node* root,int k){
	if(root==NULL || k<0 )
		return;
	if(k==0)
		{
			cout<<root->data<<" ";
			return;
		}
	printsubtree_distance(root->left,k-1);
	printsubtree_distance(root->right,k-1);
}
int  printNodesatk(Node* root,Node* target,int k)
{
	if(root==NULL)
		return -1;
	if(root==target)
	{
		printsubtree_distance(root,k);
		return 0;
	}
	int dt=printNodesatk(root->left, target, k);
	if(dt!=-1){
		if(dt+1==k)
			cout<<root->data<<" ";
		else
			printsubtree_distance(root->right,k-dt-2);
	return 1+dt;
	}
	int dr=printNodesatk(root->right, target,k);
	if(dr!=-1){
		if(dr+1==k)
			cout<<root->data<<" ";
		else
			printsubtree_distance(root->left,k-dr-2);
	return 1+dr;
	}
	return -1;


}
///
////

///
/// lowest  common ancestor 
//
//
Node* lowest_common_Ancestor(Node* root,int n1,int n2){
	if(root==NULL)
		return NULL;
	if(root->data==n1 || root->data==n2)
		return root;
	Node* left=lowest_common_Ancestor(root->left,n1,n2);
	Node* right=lowest_common_Ancestor(root->right,n1,n2);
	if(left!=NULL && right!=NULL)
		return root;
	if(left==NULL && right==NULL)
		return NULL;
	if(left!=NULL)
		return left;
	return right;
}

///// 2nd method for lowest common ancestor
////
//
///
//
////
/*

bool getpath(Node* root, int n, vector<int> &path){
	if(root==NULL)
		return false;
	path.push_back(root->data);
	if(root->data==n)
		return true;
	if(getpath(root->left,n,path) || getpath(root->right,n,path)){
		return true;
	}
	path.pop_back();
	return false;
}

int lowestca(Node* root,int n1,int n2){
	vector<int> path1,path2;
	if(!getpath(root,n1,path1) || !getpath(root,n2,path2)){
		return -1;
	}
	int pc;
	for( pc = 0; pc<path1.size() && path2.size(); pc++)
	{	
		if(path1[pc]!=path2[pc])
		{	
				break;
		}
	}


	return path1[pc-1];
}
	*/
bool getpath(Node* root,int key,vector<int>&path){
	if(root==NULL)
		return false;
	path.push_back(root->data);
	if(root->data==key)
		return true;
	if(getpath(root->left,key,path)|| getpath(root->right,key ,path))
		return true;
	path.pop_back();
	return false;
}
int lowestca(Node* root,int n1,int n2){
	std::vector<int> path1,path2;
	if(!getpath(root,n1,path1)||!getpath(root,n2,path2))
		return -1;
	int i;
	for ( i = 0; i <path1.size()&& path2.size(); i++)
	{
		if(path1[i]!=path2[i])
			break;
	}
	return path1[i-1];

}

/////
////max sum path from one node to another in binary tree
///
////

////
	int maxPathsumutil(Node* root,int &ans){
		if(root==NULL)
			return 0;
		int left=maxPathsumutil(root->left,ans);
		int right=maxPathsumutil(root->right,ans);

		int nodeMax=max(max(root->data, root->data +left+right),
						max(root->data +left, root->data + right));
		ans=max(ans,nodeMax);

		int singlePathSum=max(root->data,max(root->data +left,root->data + right));
		return singlePathSum;  
	}
	int maxPathsum(Node* root){

		int ans=INT_MIN;
		maxPathsumutil(root,ans);
		return ans;
	}

///////
/// binary search tree

	Node* bst(Node* root,int val){
		if(root==NULL)
			return new Node(val);
		if(val<root->data)
			root->left=bst(root->left,val);
		else
			root->right=bst(root->right,val);

		return root;
	}
/////
\
int main(){
	/*Node* root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->right->right=new Node(5);*/

	//bst
	Node* root=NULL;
	root=bst(root,1);
	bst(root,5);
	bst(root,2);
	bst(root,3);
	inorderPrint(root);

	//      levelordertransversal(root);
	//cout<<sum_of_kth_level(root,3);
	//cout<<node_sum(root);
	//      non_recursive_node_sum(root);
	//cout<<calcDiameter(root);
	
	/*preorder(root);
	cout<<endl;
	cout<<sumplacement(root)<<endl;
	preorder(root);
 	*/
	/*
	int height=0;
 	
 	if(balancedtree(root,&height))
 		cout<<"balancedtree";
 	else 
 		cout<<"not balancedtree";
	*/
	
	//  left_view_tree(root);


	//cout<<distanceNodes(root,4,6);
	// cout << "Dist(4, 5) = " << findDistance(root, 6, 7);
	/*
	inorderPrint(root);
	cout<<endl;
	flatten(root);
	inorderPrint(root);
	cout<<endl;*/

	//printNodesatk(root,root->left,2);  //printnodes at  a distance k from a node
	/*Node* temp=lowest_common_Ancestor(root,4,6);
	cout<<temp->data;
	*/
	//cout<<lowestca(root,4,5);
	//cout<<maxPathsum(root);
	return 0;

}
	/*    1
	    /  \
	   2    3
	  / \   /
	 4   5 6
  	  \
  	   7
  	   */