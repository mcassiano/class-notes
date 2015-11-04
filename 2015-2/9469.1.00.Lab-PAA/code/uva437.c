#include <stdlib.h>
#include <stdio.h>

#define MAX_BLOCKS 31*6
#define MIN_INT -9999

struct block {
    int a, b, h;
};

int compare(const void *a, const void *b) {
    
    struct block *b1 = (struct block*)a;
    struct block *b2 = (struct block*)b;
    
    int resp;
    
    if (b1->a != b2->a)
        resp = (b1->a) - (b2->a);
    
    else if (b1->b != b2->b)
        resp = (b1->b) - (b2->b);
    
    else
        resp = (b1->h) - (b2->h);
    
    return resp;
}

void assign_value(struct block *block, int a, int b, int h) {
    block->a = a;
    block->b = b;
    block->h = h;
}

int max(int a, int b) {
    
    if (a > b)
        return a;
    
    return b;
}

int solve(struct block *blocks, int n) {
    
    int heights[MAX_BLOCKS];
    int resp = MIN_INT;
    
    for (int i = 0; i < 6*n; i++)
        heights[i] = 1;
    
    for (int i = 0; i < 6*n; i++) {
        int max_height = 0;
        
        for (int j = 0; j < i; j++)
            if (blocks[i].a > blocks[j].a && blocks[i].b > blocks[j].b)
                max_height = max(max_height, heights[j]);
        
        heights[i] = max_height + blocks[i].h;
    }
    
    for (int i = 0; i < 6*n; i++)
        resp = max(resp, heights[i]);
    
    return resp;
}

int main (int argc, char **argv) {
    
    int c = 1, i = 0, n;
    int a, b, h;
    
    struct block blocks[MAX_BLOCKS];
    
    scanf("%d", &n);
    
    while (n != 0) {
        
        for (i = 0; i < n; i++) {
            scanf("%d %d %d", &a, &b, &h);
            
            assign_value(&blocks[6*i + 0], a, b, h);
            assign_value(&blocks[6*i + 1], a, h, b);
            assign_value(&blocks[6*i + 2], b, a, h);
            assign_value(&blocks[6*i + 3], b, h, a);
            assign_value(&blocks[6*i + 4], h, a, b);
            assign_value(&blocks[6*i + 5], h, b, a);
        }
        
        qsort(blocks, 6*n, sizeof(struct block), compare);
        
        int sol = solve(blocks, n);
        printf("Case %d: maximum height = %d\n", c, sol);
        
        c += 1;
        scanf("%d", &n);
    }
    
    return 0;
}