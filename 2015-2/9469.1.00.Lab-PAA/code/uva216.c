#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX_INT 99999
#define MAX_COMPUTERS 8

struct computer
{
    int x;
    int y;
};

float calc_dist_computer(struct computer *c1, struct computer *c2) {
    // this is the weight from v1 to v2
    return 16 + sqrt(pow(c2->x - c1->x, 2) +  pow(c2->y - c1->y, 2));
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


void permute(int *a, int l, int r, float *min_cost, int *sol, float dists[MAX_COMPUTERS][MAX_COMPUTERS])
{
    if (l == r) {
        /* check the cost for this path */
        
        float temp_cost = 0;
        for (int i = 1; i <= r; i++)
            temp_cost += dists[a[i-1]][a[i]];
        
        if (temp_cost < *min_cost) {
            *min_cost = temp_cost;
            
            for (int j = 0; j <= r; j++)
                sol[j] = a[j];
        }
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap((a+l), (a+i));
            permute(a, l+1, r, min_cost, sol, dists);
            swap((a+l), (a+i)); //backtrack
        }
    }
}


void solve(int n, struct computer *computers, float dists[MAX_COMPUTERS][MAX_COMPUTERS]) {
    
    int initial_state[MAX_COMPUTERS], sol[MAX_COMPUTERS];
    float min_cost = MAX_INT;
    
    for (int i = 0; i < n; i++)
        initial_state[i] = i;
    
    permute(initial_state, 0, n - 1, &min_cost, sol, dists);
    
    for (int i = 1; i < n; i++) {
        
        struct computer c1 = computers[sol[i-1]];
        struct computer c2 = computers[sol[i]];
        float dist = dists[sol[i-1]][sol[i]];
        
        printf("Cable requirement to connect (%d,%d) to (%d,%d) is %0.2f feet.\n", c1.x, c1.y, c2.x, c2.y, dist);
        
    }
    
    printf("Number of feet of cable required is %0.2f.\n", min_cost);
    
}


int main (int argc, char **argv) {
    
    int c = 1, i = 0, j = 0, n;
    float dist_computers[MAX_COMPUTERS][MAX_COMPUTERS];
    struct computer computers[MAX_COMPUTERS];
    
    scanf("%d", &n);
    
    while (n != 0) {
        
        for (i = 0; i < n; i++)
            scanf("%d %d", &(computers[i].x), &(computers[i].y));
        
        for (i = 0; i < n; i++) {
            dist_computers[i][i] = 0;
            
            for (j = 0; j < n; j++) {
                
                if (i != j)
                    dist_computers[i][j] = calc_dist_computer(&computers[i], &computers[j]);
            }
        }
        
        printf("**********************************************************\n");
        printf("Network #%d\n", c);
        
        solve(n, computers, dist_computers);
        
        c += 1;
        scanf("%d", &n);
    }
    
    return 0;
}