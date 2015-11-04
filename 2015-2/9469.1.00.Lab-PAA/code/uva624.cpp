#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

#define MIN_INT -9999
#define MAX_TRACKS 20

void solve(int *tracks, int num_tracks, int sum) {
    
    int max_allowed_sum = MIN_INT;
    
    vector<int> sol;
    vector<int> temp_sol;
    
    int all_masks = (1 << num_tracks);
    
    for (int i = 1; i < all_masks; i++) {
        
        for (int j = 0; j < num_tracks; j++) {
            if ((i & (1 << j)) > 0) {
                temp_sol.push_back(j);
            }
        }
        
        int temp_sum = 0;
        
        for (int i = 0; i < temp_sol.size(); i++)
            temp_sum += tracks[temp_sol[i]];
        
        if (temp_sum <= sum && temp_sum >= max_allowed_sum) {
            
            if (temp_sum == max_allowed_sum) {
                if (temp_sol.size() > sol.size()) {
                    sol = temp_sol;
                }
            }

            else {
            
                max_allowed_sum = temp_sum;
                sol = temp_sol;
            }
            
        }
        
        temp_sol.clear();
    }
    
    for (int i = 0; i < sol.size(); i++)
        printf("%d ", tracks[sol[i]]);
    
    printf("sum:%d\n", max_allowed_sum);
    
}



int main(int arc, char **argv) {
    
    
    int total_minutes, num_tracks, tracks[MAX_TRACKS];
    
    while (scanf("%d", &total_minutes) != EOF) {
        
        scanf("%d", &num_tracks);
        
        for (int i = 0; i < num_tracks; i++)
            scanf("%d", &tracks[i]);
        
        solve(tracks, num_tracks, total_minutes);

    }
    
    return 0;
}