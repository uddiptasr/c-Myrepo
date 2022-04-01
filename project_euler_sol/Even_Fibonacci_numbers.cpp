#include<bits/stdc++.h>
using namespace std;

int main(){
	int sum=2;

	int t1=1;
	int t2=2;
	while(t2<4000000){
		int newsum=t1+t2;
		if(newsum%2==0)
			sum+=newsum;
		t1=t2;
		t2=newsum;

	}
	cout<<sum;
return 0;
}