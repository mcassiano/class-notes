#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int compare (const void * a, const void * b) {
    return ( *(int*)b - *(int*)a );
}

int solve(int n, int P, int Q, priority_queue<int, vector<int>, greater<int> > eggs) {
    
    int q = 0, c = 0, i = 0;
    
    while (!eggs.empty() && i < P) {
        
        if (q + eggs.top()  <= Q) {
            q += eggs.top();
            eggs.pop();
            c += 1;
        }
        
        i += 1;
    }
    
    return c;
}

    
int main (int argc, char **argv) {
        
        int tests, n, P, Q, temp;
        scanf("%d", &tests);
        
        for (int i = 1; i <= tests; i++) {
            scanf("%d %d %d", &n, &P, &Q);
            
            priority_queue<int, vector<int>, greater<int> > eggs;
            
            for (int j = 0; j < n; j++) {
                scanf("%d", &temp);
                eggs.push(temp);
            }
            
            int sol = solve(n, P, Q, eggs);
            printf("Case %d: %d\n", i, sol);
        }
        
        return 0;
        
    }