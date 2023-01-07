#include "Myheader.h"

int strcmp1(const void *a, const void *b) {
    return strcmp((*(char **)a), (*(char **)b));
}

int main(void) {

    char *A[4] = {
        "sdfffff",
        "sdfsf",
        "were",
        "ewr"
    };

    printf("%c\n", *(A[2] + 3));
    qsort(A, sizeof(A) / sizeof(A[0]), sizeof(A[0]), strcmp1);
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        printf("%p, %p, %s\n", A + i, *(A + i), A[i]);
    }
    int arrA[6] = {1, -2, 2, -3, 2, 4};
    int arrB[7] = {1, 1, 1, 1, 1, 1};
    int AA = maxSumOfSubset(arrA, 6);
    int BB = minSumOfSubarr(arrB, 6, 7);
    printf("%d, %d\n", AA , BB);
    printf("%p, %p\n", maxSumOfSubset, maxSumOfSubset);
    system("pause");

    return 0;
}