#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX_INT 9999

struct coin {
    int con;
    int it;
};


int solve(struct coin *coins, int m, int S) {
    
    int mem[S+1][S+1], S2 = S*S, min = MAX_INT;
    
    for (int i = 0; i <= S; i++)
        for (int j = 0; j <= S; j++)
            mem[i][j] = MAX_INT;
    
    mem[0][0] = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = coins[i].con; j <= S; j++) {
            for (int k = coins[i].it; k <= S; k++) {
                
                int test = mem[j - coins[i].con][k - coins[i].it] + 1;
                
                if (test < mem[j][k])
                    mem[j][k] = test;
            }
        }
    }
    
    for (int i = 0; i <= S; i++) {
        for (int j = 0; j <= S; j++) {
            if (i*i + j*j == S2 && mem[i][j] < min)
                min = mem[i][j];
        }
    }
    
    return min;
}


int main (int argc, char **argv) {
    
    int i, j, n, m, S;
    struct coin coins[41];
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        
        scanf("%d %d", &m, &S);
        
        for (j = 0; j < m; j++)
            scanf("%d %d", &(coins[j].con), &(coins[j].it));
        
        int sol = solve(coins, m, S);
        
        if (sol == MAX_INT)
            printf("not possible\n");
        else
            printf("%d\n", sol);
        
    }
    
    return 0;
}