#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;


        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


int main()
{
    int n, i, j;
    double time_spent = 0.0;

    clock_t begin = clock();
    printf("Enter size: ");
    scanf("%d", &n);

    int a[n];

    for(i = 0; i < n; i++){
        a[i] = rand() % 1000;
    }

    printf("\nRandom array:\n");
    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }

    insertionSort(a, n);

    clock_t end = clock();

    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n\nSorted array:\n");
    for (i = 0; i < n; i++){
        printf("%d ", a[i]);
    }

    printf("\n\nElapsed Time: %f", time_spent);
    printf("\n");

    return 0;
}
