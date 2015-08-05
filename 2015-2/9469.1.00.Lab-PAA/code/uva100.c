#include<stdlib.h>
#include<stdio.h>


int calcNumberOfCycles(int n) {

	int cycles = 1;

	while (n != 1) {
		if (n % 2 == 0)
			n = n/2;
		else
			n = 3*n + 1;

		cycles += 1;
	}

	return cycles;
}

int main (int argc, char** argv) {

	int i, j;

	while (fscanf(stdin, "%d %d", &i, &j) != EOF) {
		int currentMax = -1;
		int m;
		for (m = i; m <= j; m++) {
			int nCycles = calcNumberOfCycles(m);
			if (nCycles > currentMax)
				currentMax = nCycles;
		}

		printf("%d %d %d\n", i, j, currentMax);
	}
	
	return 0;
}
