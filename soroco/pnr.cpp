/*# Given an input integer n, 
count natural numbers in range [1, n] 
whose all permutations are greater than 
or equal to the number itself.
*/
#include<bits/stdc++.h>
using namespace std;
int countNumber(int n){
    int res=0;
    stack<int>s;
    for(int i=1;i<=9;i++){
        if(i<=n){
            s.push(i);
            res++;
        }
    }
    while(!s.empty()){
        int a=s.top();
        s.pop();
        for(int i=a%10;i<=9;i++){
            int j=a*10+i;
            if(j<=n){
                s.push(j);
                res++;
            }
        }
    }
    return res;
}
int main(){
    int n=15;
    cout<<countNumber(n)<<endl;
}