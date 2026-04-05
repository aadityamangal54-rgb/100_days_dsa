#include <stdio.h>
#include <stdlib.h>
#define MAX 100000
int countZeroSumSubarrays(int arr[], int n) {
    int prefixSum = 0;
    int count = 0;
    int *freq = (int*)calloc(2 * MAX + 1, sizeof(int));
    int offset = MAX;
    freq[offset] = 1;
    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];
        count += freq[prefixSum + offset];
        freq[prefixSum + offset]++;
    }
    free(freq);
    return count;
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int result = countZeroSumSubarrays(arr, n);
    printf("%d\n", result);
    return 0;
}