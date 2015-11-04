#include <stdio.h>
#include <stdlib.h>

#define MIN_INT -1000

int min(int a, int b) {
    if (a < b)
        return a;
    return b;
}

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int main(int arc, char **argv) {
    
    int i, j, tests, l, n, pos, min_t, max_t;
    scanf("%d", &tests);
    
    for (i = 0; i < tests; i++) {
        
        min_t = MIN_INT;
        max_t = MIN_INT;
        
        scanf("%d %d", &l, &n);
        
        for (j = 0; j < n; j++) {
            scanf("%d", &pos);
            max_t = max(max_t, max(pos, l-pos));
            min_t = max(min_t, min(pos, l-pos));
        }
        
        printf("%d %d\n", min_t, max_t);
    }
    
    return 0;
}