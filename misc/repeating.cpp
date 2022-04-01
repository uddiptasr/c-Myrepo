#include<bits/stdc++.h>
using namespace std;
int main(){
	string s="soroco";
	map<char,int> a;
	for(int i=0;i<s.length();i++){
		if(a.find(s[i])!=a.end()){
			a[s[i]]++;
		}
		else{
			a.insert({s[i],1});
		}
	}
	for(auto i: a){
		cout<<i.first<<" ";
	}
}