#include <stdio.h>
#include <stdlib.h>

void countSort(int a[], int size){
    int output[10];

    int max = a[0];
    for(int i = 1; i < size; i++){
        if(a[i] > max){
            max = a[i];
        }
    }

    int count[10];

    for(int i = 0; i <= max; ++i){
        count[i] = 0;
    }

    for(int i = 0; i < size; i++){
        count[a[i]]++;
    }

    for(int i = 1; i <= max; i++){
        count[i] += count[i - 1];
    }

    for(int i = size - 1; i >= 0; i--){
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }

    for(int i = 0; i < size; i++){
        a[i] = output[i];
    }
}

void printArray(int a[], int size){
    printf("\n");
    for(int i = 0; i < size; ++i){
        printf("%d ", a[i]);
    }
    printf("\n");
}


int main()
{
    int n;
    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];

    printf("\nEnter %d elements:\n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    //int n = sizeof(arr) / sizeof(arr[0]);
    countSort(arr, n);
    printArray(arr, n);

}
