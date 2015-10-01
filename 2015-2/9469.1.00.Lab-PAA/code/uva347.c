#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int equalDigits(int n) {
    
    int cur = n % 10;
    int d[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    while(n != 0) {
        if(d[cur] || cur == 0) return 1;
        d[cur] = 1;
        n /= 10;
        cur = n % 10;
    }
    
    return 0;
}

int allVisited(int *visited, int n) {
    int i;
    
    for (i = 0; i < n; i++)
        if (!visited[i])
            return 0;
    return 1;
}

int isRunaround(int r) {
    
    if (equalDigits(r))
        return 0;
    
    char digits[8];
    int i = 0, n, current = 0, steps = 0;
   	int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    
    sprintf(digits, "%d", r);
    n = (int) strlen(digits);
    
    while (i++ < n) {
        
        if (visited[current] == 1)
            return 0;
        
        visited[current] = 1;
        steps = digits[current] - '0';
        current = (current + steps) % n;
    }
    
    return allVisited(visited, n) && (current == 0);
}

int main(int arg, char **argv) {
    
    int r = 0, case_n = 1;
    
    while (scanf("%d", &r) && r != 0) {
        
        while (!isRunaround(r))
            r += 1;
        
        printf("Case %d: %d\n", case_n, r);
        case_n += 1;
    }
    
    return 0;
}