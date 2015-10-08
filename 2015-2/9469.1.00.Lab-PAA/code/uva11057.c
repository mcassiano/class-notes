#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int binarySearch(int n, int start, int *prices, int N) {
    int left = start;
    int right = N;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;

        if (n == prices[mid]) return mid;
        if (n > prices[mid]) left = mid + 1;
        else right = mid - 1;
    }

    return -1;
}


void solve(int *prices, int N, int M) {
    int i = 0, a = 0, b = 0, diff = -1;
    qsort(prices, N, sizeof(int), comp);

    while (prices[i] <= M/2) {

        int priceToLookFor = M - prices[i];
        int res = binarySearch(priceToLookFor, i + 1, prices, N);

        if (res != -1) {
            int tempDiff = priceToLookFor - prices[i];

            if (diff == -1) {
                a = prices[i];
                b = priceToLookFor;
                diff = b - a;
            }

            if (tempDiff < diff) {
                a = prices[i];
                b = priceToLookFor;
                diff = tempDiff;
            }
        }

        i += 1;
    }

    printf("Peter should buy books whose prices are %d and %d.\n\n", a, b);

}


int main(int argc, char **argv) {

    int numberOfBooks = 0, totalMoney = 0;
    int prices[10001];
    int i;

    for (i = 0; i < 10001; i++)
        prices[i] = 0;

    while (scanf("%d", &numberOfBooks) != EOF) {

        for (i = 0; i < numberOfBooks; i++)
            scanf("%d", &(prices[i]));

        scanf("%d", &totalMoney);

        solve(prices, numberOfBooks, totalMoney);

    }

    return 0;
}