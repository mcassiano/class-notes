#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

int compare (const void * a, const void * b) {
  return ( *(int*)a - *(int*)b );
}

int min(int a, int b) {
	if (a > b)
		return b;
	return a;
}

int main(int argc, char **argv) {

	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {

		int n, P, Q;

		scanf("%d", &n);
		while (n > 30)
			scanf("%d", &n);

		scanf("%d %d", &P, &Q);

		int weights[n];
		int count = 0;
		int sum = 0;

		for (int j = 0; j < n; j++)
			scanf("%d", &weights[j]);

		qsort(weights, n, sizeof(weights[0]), compare);

		for (int j = 0; j < min(n, P); j++) {
			if (sum + weights[j] <= Q) {
				sum += weights[j];
				count += 1;
			}	
		}

		printf("Case %d: %d\n", i+1, count);
		
	}


	return 0;
}
