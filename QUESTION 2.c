#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    long comparisons;
    long movements;
} Stats;

Stats bubbleSort(int a[], int n) {
    Stats s = {0, 0};
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            s.comparisons++;
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                s.movements++;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
    return s;
}

Stats selectionSort(int a[], int n) {
    Stats s = {0, 0};
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            s.comparisons++;
            if (a[j] < a[min]) min = j;
        }
        if (min != i) {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
            s.movements++;
        }
    }
    return s;
}

Stats insertionSort(int a[], int n) {
    Stats s = {0, 0};
    for (int i = 1; i < n; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0) {
            s.comparisons++;
            if (a[j] > key) {
                a[j + 1] = a[j];
                s.movements++;
                j--;
            } else {
                break;
            }
        }
        a[j + 1] = key;
    }
    return s;
}

void makeArray(int a[], int n, const char *order) {
    for (int i = 0; i < n; i++) a[i] = i + 1;

    if (strcmp(order, "Reverse") == 0) {
        for (int i = 0; i < n; i++) a[i] = n - i;
    } else if (strcmp(order, "Nearly sorted") == 0) {
        for (int i = 0; i + 1 < n; i += 10) {
            int t = a[i];
            a[i] = a[i + 1];
            a[i + 1] = t;
        }
    } else if (strcmp(order, "Random") == 0) {
        for (int i = n - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
}

void testOne(int n, const char *order) {
    int *original = malloc((size_t)n * sizeof(int));
    int *a = malloc((size_t)n * sizeof(int));
    int *b = malloc((size_t)n * sizeof(int));
    int *c = malloc((size_t)n * sizeof(int));

    if (!original || !a || !b || !c) {
        printf("Memory allocation failed.\n");
        free(original); free(a); free(b); free(c);
        return;
    }

    makeArray(original, n, order);
    memcpy(a, original, (size_t)n * sizeof(int));
    memcpy(b, original, (size_t)n * sizeof(int));
    memcpy(c, original, (size_t)n * sizeof(int));

    Stats x = bubbleSort(a, n);
    Stats y = selectionSort(b, n);
    Stats z = insertionSort(c, n);

    printf("%-14s %6d | Bubble: %ld comparisons, %ld swaps"
           " | Selection: %ld comparisons, %ld swaps"
           " | Insertion: %ld comparisons, %ld shifts\n",
           order, n, x.comparisons, x.movements,
           y.comparisons, y.movements, z.comparisons, z.movements);

    free(original); free(a); free(b); free(c);
}

int main(void) {
    const char *orders[] = {"Sorted", "Nearly sorted", "Reverse", "Random"};
    int sizes[] = {100, 1000, 10000};

    srand((unsigned int)time(NULL));
    printf("SORTING COMPARISON RESULTS\n");
    for (int o = 0; o < 4; o++) {
        for (int s = 0; s < 3; s++) {
            testOne(sizes[s], orders[o]);
        }
    }
    return 0;
}
