#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* Código para problema de LCS (baseado em chars,
 * teve que ser convertido para strings)
 *
 * http://www.geeksforgeeks.org/printing-longest-common-subsequence/
 */

int max(int i, int j) {
    if (i > j)
        return i;
    return j;
}

void lcs(char **X, char **Y, int m, int n ) {
    int L[m+1][n+1];

    for (int i=0; i<=m; i++) {
        for (int j=0; j<=n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (strcmp(X[i-1], Y[j-1]) == 0)
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    
    int index = L[m][n];
    
    char* lcs[index];

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (strcmp(X[i-1], Y[j-1]) == 0) {
            lcs[index-1] = X[i-1];
            i--; j--; index--;
        }
        
        else if (L[i-1][j] > L[i][j-1])
            i--;
        else
            j--;
    }
    
    printf("%s", lcs[0]);
    for (int i = 1; i < L[m][n]; i++)
        printf(" %s", lcs[i]);
    printf("\n");
}

void init_text(char **text) {
    for (int i = 0; i < 101; i++)
        text[i] = new char[30];
}

void free_text(char **text) {
    for (int i = 0; i < 101; i++)
        free(text[i]);
}

int main() {
    
    char word[31];
    
    char *text1[101];
    char *text2[101];
    
    init_text(text1);
    init_text(text2);
    
    int current_text = 0;
    
    int count_1 = 0;
    int count_2 = 0;
    
    while (scanf("%s", word) != EOF) {
        
        if (strcmp(word, "#") == 0) {
            
            current_text = 1 - current_text;
            
            if (current_text == 0) {
                lcs(text1, text2, count_1, count_2);
                count_1 = count_2 = 0;
            }
            
            
        }
        
        else {
            
            char **aux;
            int *i;
            
            if (current_text == 0) {
                i = &count_1;
                aux = text1;
            }
            
            else {
                i = &count_2;
                aux = text2;
            }
            
            strcpy(aux[*i], word);
            *i += 1;
            
        }
        
    }
    
    free_text(text1);
    free_text(text2);
    
    return 0;
}