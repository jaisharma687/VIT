#include <stdio.h>
#include <string.h>

void compute_lps(char *pat, int m, int *lps){
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while(i<m){
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len!=0)
                len = lps[len-1];
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmp(char *text, char *pattern){
    int n = strlen(text);
    int m = strlen(pattern);
    int lps[m];
    compute_lps(pattern,m,lps);
    for(int i=0;i<m;i++)
        printf("%d ",lps[i]);
    printf("\n");
    int i=0,j=0;
    while(i<n){
        if(pattern[j]==text[i]){
            i++;
            j++;
        }
        if(j==m){
            printf("Pattern is found and after %d shifts\n",i-j);
            j = lps[j-1];
        }
        else if(i<n && pattern[j] != text[i]){
            if(j!=0){
                j = lps[j-1];
            }else{
                i++;
            }
        }
    }
}

int main(){
    char text[100],pattern[100];
    fgets(text,sizeof(text),stdin);
    text[strcspn(text,"\n")] = '\0';
    fgets(pattern,sizeof(pattern),stdin);
    pattern[strcspn(pattern,"\n")] = '\0';
    
    kmp(text,pattern);
    return 0;
}