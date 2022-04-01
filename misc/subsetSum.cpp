#include<bits/stdc++.h>
using namespace std;
int tab[200][200];
int result=0;
int subsetSum(int arr[],int n,int sum){
	if(sum==0)
		return 1;
	if(n<0 || sum<0)
		return 0;
	if(tab[n-1][sum]!=-1)
		return tab[n-1][sum];
	if(arr[n-1]>sum){
		result=subsetSum(arr,n-1,sum);
	}
	else
		{
			result=subsetSum(arr,n-1,sum-arr[n-1]) + subsetSum(arr,n-1,sum);
		}
	tab[n-1][sum]=result;	
	return result;

}

int main(){	
	memset(tab,-1,sizeof(tab));
	int n=5;
	int a[]={2,4,6,10};
	int sum=16;
	cout<<subsetSum(a,n,sum);
	return 0;
}