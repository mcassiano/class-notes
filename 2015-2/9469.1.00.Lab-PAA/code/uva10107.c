#include <stdlib.h>
#include <stdio.h>

int compare (const void * a, const void * b) {
  return ( *(long int*)a - *(long int*)b );
}
long int getMedian(long int numbers[], int count) {
	int half = count/2;
	long int resp;

	if (count % 2 == 0)
		resp = (numbers[half - 1] + numbers[half])/2;

	else
		resp = numbers[half];

	return resp;
}

int main (int argc, char **argv) {

	long int numbers[10000];
	long int number;
	size_t count = 0;

	while (scanf("%ld", &number) != EOF) {
		numbers[count] = number;
		count++;
		qsort(numbers, count, sizeof(long int), compare);
		printf("%ld\n", getMedian(numbers, count));
	}

	return 0;
}