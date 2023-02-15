#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    int n, i, j, temp;
    double time_spent;

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

    for(i = 0; i < n; i++){
        for(j = 0; j < n - i - 1; j++){
            if(a[j] > a[j + 1]){
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    clock_t end = clock();

    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n\nSorted array:\n");
    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n\nElapsed Time: %f", time_spent);
    printf("\n");

    return 0;
}
