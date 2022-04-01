//repeating s='soroco'
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="soroco";
    string res="";
    map<char,int> m;
    for(int i=0;i<s.length();i++){
        if(m.find(s[i])==m.end()){
            res+=s[i];
        }
        m[s[i]]=1;
    }
   cout<<res;
}