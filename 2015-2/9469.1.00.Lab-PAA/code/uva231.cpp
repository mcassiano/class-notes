#include <stdio.h>
#include <stdlib.h>

int lis( int arr[], int n ) {
   int lis[n], i, j, max = 0;
 
   /* Initialize LIS values for all indexes */
   for ( i = 0; i < n; i++ )
      lis[i] = 1;
    
   /* Compute optimized LIS values in bottom up manner */
   for ( i = 1; i < n; i++ )
      for ( j = 0; j < i; j++ )
         if ( arr[i] >= arr[j] && lis[i] <= lis[j] + 1)
            lis[i] = lis[j] + 1;
    
   /* Pick maximum of all LIS values */
   for ( i = 0; i < n; i++ )
      if ( max < lis[i] )
         max = lis[i];
  
   return max;
}

void reverse(int *arr, int count) {
    int temp;

    for (int i = 0; i < count/2; ++i)
    {
        temp = arr[i];
        arr[i] = arr[count-i-1];
        arr[count-i-1] = temp;
    }
}


int main(int argc, char **argv) {

	int t = 1, count = 0, temp;
	int missiles[100000];

	while (scanf("%d", &temp) != EOF) {

		if (temp != -1) {
			missiles[count] = temp;
			count += 1;
		}

		else if (count > 0) {
			reverse(missiles, count);

			if (t != 1)
				printf("\n");

			printf("Test #%d:\n", t);
			printf("  maximum possible interceptions: %d\n", lis(missiles, count));
			count = 0;
			t += 1;
		}

	}


	return 0;
}