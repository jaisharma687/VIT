#include <stdio.h>
#include <string.h>

void computeLPSArray(char *pat, int M, int *lps) {
    int len = 0;
    int i;

    lps[0] = 0;
    i = 1;

    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char *txt, char *pat) {
    int M = strlen(pat);
    int N = strlen(txt);
    int lps[M];

    computeLPSArray(pat, M, lps);

    int i = 0;
    int j = 0;

    while (i < N) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }

        if (j == M) {
            printf("Pattern is found in the string");
            printf("\nNumber of Shifts needed is %d\n", i - j);
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    char txt0[100], txt[100], pat0[100], pat[100];
    int i, j;

    fgets(txt0, sizeof(txt0), stdin);
    txt0[strcspn(txt0, "\n")] = '\0';

    for (i = j = 0; txt0[i] != '\0'; i++) {
        if (txt0[i] != ' ') {
            txt[j++] = txt0[i];
        }
    }
    txt[j] = '\0';

    fgets(pat0, sizeof(pat0), stdin);
    pat0[strcspn(pat0, "\n")] = '\0';

    for (i = j = 0; pat0[i] != '\0'; i++) {
        if (pat0[i] != ' ') {
            pat[j++] = pat0[i];
        }
    }
    pat[j] = '\0';

    KMPSearch(txt, pat);

    return 0;
}
