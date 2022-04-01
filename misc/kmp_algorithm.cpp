#include<bits/stdc++.h>
using namespace std;

void computeLPSArray(char* pat, int M, int* lps);
void KMPSearch(char pat[],char txt[]){
    int M=strlen(pat);
    int N=strlen(txt);
    int lps[M];
    computeLPSArray(pat,M,lps);
    int i=0; // txt
    int j=0; //pat
    while(i<N){
        if(pat[j]==txt[i]){
            i++;
            j++;
        }
        if(j==M){
            printf("Found pattern at index %d ", i - j);
            j=lps[j-1];
        }
        else if(i<N && pat[j]!=txt[i]){
            if (j!=0)
                j=lps[j-1];
            else
                i=i+1;
            
        }

    }
}

void computeLPSArray(char* pat, int M, int* lps)
{
    int len=0;
    lps[0]=0;
    int i=1;
    while(i<M){
        if(pat[i]==pat[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0)
            {
            // This is tricky. Consider the example.
            // AAA C AAA A and i = 7. The idea is similar
            // to search step
                len=lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}
int main(){
    char txt[]="ABABDABACDABABCABAB";
    char pat[]="ABABCABAB";
    KMPSearch(pat,txt);
    return 0;
}

