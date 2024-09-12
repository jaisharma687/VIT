# include <stdio.h>
# include <string.h>
# include <math.h>

# define b 26
# define q 31

void rabinKarp(char *text, char *pattern){
    int n = strlen(text);
    int m = strlen(pattern);
    int patternHash = 0;
    int textHash = 0;
    int h = 1;

    for (int i = 0; i < m - 1; i++)
		h = (h * b) % q;

    for(int i=0;i<m;i++){
        patternHash = (patternHash * b + pattern[i]) % q;
        textHash = (textHash * b + text[i]) % q;
    }

    for(int i=0;i<=n-m;i++){
        if(patternHash == textHash){
            int j;
            for(j=0;j<m;j++){
                if(text[i+j]!= pattern[j])
                    break;
            }
            if(j==m){
                printf("Pattern is found at index %d\n",i);
            }
        }
        if(i<n-m){
            textHash = (b * (textHash - text[i] * h) + text[i+m]) % q;
            if(textHash < 0){
                textHash += q;
            }
        }
    }
    printf("Pattern not found");
}


int main(){
    char text[100], pattern[100];
    fgets(text,sizeof(text),stdin);
    fgets(pattern,sizeof(pattern),stdin);
    text[strcspn(text,"\n")] = '\0';
    pattern[strcspn(pattern,"\n")] = '\0';
    rabinKarp(text,pattern);
    return 0;
}