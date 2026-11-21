#include <stdio.h>
#include <stdlib.h>

int linearSearch(const int a[], int n, int key, long *comparisons) {
    for (int i = 0; i < n; i++) {
        (*comparisons)++;
        if (a[i] == key) return i;
    }
    return -1;
}

int binarySearch(const int a[], int n, int key, long *comparisons) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        (*comparisons)++;
        if (a[mid] == key) return mid;
        if (a[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

void runExperiment(int n) {
    int *unsorted = malloc((size_t)n * sizeof(int));
    int *sorted = malloc((size_t)n * sizeof(int));
    if (!unsorted || !sorted) {
        printf("Memory allocation failed.\n");
        free(unsorted);
        free(sorted);
        return;
    }

    for (int i = 0; i < n; i++) {
        unsorted[i] = n - i;
        sorted[i] = i + 1;
    }

    int keys[] = {1, n / 2, n, n + 1};
    const char *positions[] = {"Beginning", "Middle", "End", "Missing"};

    printf("\nArray size: %d\n", n);
    printf("%-12s %-12s %-18s %-18s\n",
           "Position", "Key", "Linear comparisons", "Binary comparisons");

    for (int k = 0; k < 4; k++) {
        long lc = 0, bc = 0;
        linearSearch(unsorted, n, keys[k], &lc);
        binarySearch(sorted, n, keys[k], &bc);
        printf("%-12s %-12d %-18ld %-18ld\n",
               positions[k], keys[k], lc, bc);
    }

    free(unsorted);
    free(sorted);
}

int main(void) {
    int n = 100000;
    int *sorted = malloc((size_t)n * sizeof(int));
    if (!sorted) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) sorted[i] = i + 1;

    int keys[] = {1, 50000, 100000, 100001};
    printf("BINARY SEARCH TEST\n");
    for (int i = 0; i < 4; i++) {
        long comparisons = 0;
        int pos = binarySearch(sorted, n, keys[i], &comparisons);
        printf("Key %d -> index %d, comparisons = %ld\n",
               keys[i], pos, comparisons);
    }
    free(sorted);

    printf("\nEXPERIMENTAL INVESTIGATION\n");
    runExperiment(1000);
    runExperiment(10000);
    runExperiment(100000);

    return 0;
}
