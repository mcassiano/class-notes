#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <string>

using namespace std;

int main(int argc, char **argv) {
    
    int numberOfTestCases;
    char cityNameBuffer[31];
    int c = 0;
    
    map<string, int> m;
    
    
    scanf("%d\n", &numberOfTestCases);
    int i;
    
    for (i = 0; i < numberOfTestCases; i++) {
        
        while (fgets(cityNameBuffer, 30, stdin) != NULL) {
            
            if (strcmp(cityNameBuffer, "\n") == 0)
                break;
            
            if (cityNameBuffer[strlen(cityNameBuffer) - 1] == '\n')
                cityNameBuffer[strlen(cityNameBuffer) - 1] = '\0';
            
            m[string(cityNameBuffer)] += 1;
            c += 1;
            
        }
        
        for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
            printf("%s %0.4f\n", it->first.c_str(), 100*it->second/(float)c);
        
        if (i != numberOfTestCases - 1)
            printf("\n");
        
        m.clear();
        c = 0;
    }
    
    return 0;
}