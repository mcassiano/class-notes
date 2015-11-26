#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv) {

	int agec[101];
	int n, i, j, k;

	while (scanf("%d", &n) != EOF && n != 0) {

		memset(agec, 0, 101*sizeof(int));

		for (i = 0; i < n; i++) {
			scanf("%d", &j);
			agec[j-1] += 1;
		}

		int first = 0;

		for (i = 0; i < 101; i++) {
			for (k = 0; k < agec[i]; k++) {

				if (first == 0) {
					printf("%d", i + 1);
					first = 1;
				}
				
				else
					printf(" %d", i + 1);
			}
		}

		printf("\n");

	}

	return 0;
}