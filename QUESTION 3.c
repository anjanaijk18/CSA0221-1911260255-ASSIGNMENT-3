#include <stdio.h>

int mergeDescending(const int a[], int m, const int b[], int n, int out[]) {
    int i = 0, j = 0, k = 0;

    while (i < m && j < n) {
        if (a[i] >= b[j]) {
            out[k++] = a[i++];
        } else {
            out[k++] = b[j++];
        }
    }

    while (i < m) out[k++] = a[i++];
    while (j < n) out[k++] = b[j++];

    return k;
}

void printArray(const int a[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

int main(void) {
    int campusA[] = {98, 91, 85, 72};
    int campusB[] = {95, 91, 80};
    int m = sizeof(campusA) / sizeof(campusA[0]);
    int n = sizeof(campusB) / sizeof(campusB[0]);
    int merged[7];

    int k = mergeDescending(campusA, m, campusB, n, merged);

    printf("Campus A: ");
    printArray(campusA, m);
    printf("Campus B: ");
    printArray(campusB, n);
    printf("Merged merit list: ");
    printArray(merged, k);

    return 0;
}
