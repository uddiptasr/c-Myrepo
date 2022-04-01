#include <bits/stdc++.h>
using namespace std;


void solve(){
char arr[3][3];
int countx=0,uncount=0,counto=0;
int winx=0,wino=0;
for(int i=0;i<3;i++){
	for(int j=0;j<3;j++){
	  cin>>arr[i][j];
			if(arr[i][j]=='X')
			countx++;
		else if(arr[i][j]=='O'){
			counto++;
		}
		else if(arr[i][j]=='_')
			uncount++;
	}
}

for(int i=0;i<3;i++){
	if(arr[i][0]==arr[i][1] && arr[i][1]==arr[i][2])
		{
			if(arr[i][2]=='X')winx++; ////row wise checking
			if(arr[i][2]=='O')wino++;
	}
}
for(int i=0;i<3;i++){
	if(arr[0][i]==arr[1][i] && arr[1][i]==arr[2][i])
		{
			if(arr[2][i]=='X')winx++;
			if(arr[2][i]=='O')wino++; ///column wise checking
	}
}
if(arr[1][1]==arr[0][0] && arr[1][1]==arr[2][2])
		{
			if(arr[2][2]=='X')winx++;
			if(arr[2][2]=='O')wino++; ///diagonal checking
	}

if(arr[0][2]==arr[1][1] && arr[1][1]==arr[2][0])
	{
			if(arr[2][0]=='X')winx++;
			if(arr[2][0]=='O')wino++; ///diagonal checking
	}

if((counto>countx) ||(countx-counto>1)) cout<<3;

else if((countx>counto) && winx==1 && wino==0) cout<<1;
else if((countx==counto) && wino==1 && winx==0) cout<<1;
else if(uncount==0 && (winx+wino==0)) cout<<1;
else if(uncount==0 && winx==2){
	cout<<1;
}

else if(uncount>0 &&(winx + wino==0)){
	cout<<2;
}
else cout<<3;

return;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>> t;
	while (t--){
		solve();
		cout<<endl;
		

	}

	return 0;

}
/*
3
XOX
XXO
O_O
XXX
OOO
___
XOX
OXO
XOX
/
*/