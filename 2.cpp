#include<bits/stdc++.h>
using namespace std;

void compute(string pat,int* lcs,int m);
int  kmpAlogorithm(string txt,string pat){
   int n=txt.length();
   int m=pat.length();
   int lps[m];
   compute(pat,lps,m);
   int i=0;
   int j=0;
   int count=0;
   while(i<n){
      if(txt[i]==pat[j]){
         i++;
         j++;
      }
      if(j==m){
          count++;
          j=lps[j-1];
      }
      else if(i<n && pat[j]!=txt[i]){
         if(j!=0)
            j=lps[j-1];
         else
            i++;
      }
   }
return count;
}
void compute(string pat,int* lps,int m){
   int len=0;
   lps[0]=0;
   int i=1;
   while(i<m){
      if(pat[i]==pat[len]){
         len++;
         lps[i]=len;
         i++;
      }
      if(len!=0){
         len=lps[len-1];
      }else{
         lps[i]=0;
         i++;
      }
   } 
}
int main(){
   string a;
   cin>>a;
   int n;
   cin>>n;
   while(n--){
      string pat;
      cin>>pat;
      cout<<kmpAlogorithm(a,pat)<<'\n';
   }
   return 0;
}
