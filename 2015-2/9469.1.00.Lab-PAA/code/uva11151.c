/* Dynamic Programming C/C++ implementation of LCS problem */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b);

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( char *X, char *Y, int m, int n )
{
    int L[m+1][n+1];
    int i, j;
    
    /* Following steps build L[m+1][n+1] in bottom up fashion. Note
     that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
    for (i=0; i<=m; i++)
    {
        for (j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            
            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    
    /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
    return L[m][n];
}

/* Utility function to get max of 2 integers */
int max(int a, int b)
{
    return (a > b)? a : b;
}

void reverse(char arr[], int count)
{
    int temp;
    for (int i = 0; i < count/2; ++i)
    {
        temp = arr[i];
        arr[i] = arr[count-i-1];
        arr[count-i-1] = temp;
    }
}

int main (int argc, char **argv) {

    int T, i;
    char X[1000];
    char Y[1000];

    fgets(X, 999, stdin);
    sscanf(X, "%d", &T);

    for (i = 0; i < T; i++) {
        
        if (fgets(X, 999, stdin) != NULL) {

            if (strcmp(X, "\n") == 0 || strlen(X) == 0) {
                printf("0\n");
                continue;
            }

            if (X[strlen(X) - 1] == '\n')
                X[strlen(X) - 1] = '\0';

            strcpy(Y, X);
            reverse(Y, (int) strlen(Y));

            int x = (int)strlen(X);
            int y = (int)strlen(Y);

            printf("%d\n", lcs(X, Y, x, y));

        }
    }

    return 0;

}