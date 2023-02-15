#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;

    printf("Enter the size of n: ");
    scanf("%d", &n);

    int a[n];

    //printf("Enter elements in the array:\n");
    for(i = 0; i < n; i++){
        a[i] = rand() %1000;
    }

    selection(a, n);

    printf("Sorted array using selection sort:\n");
    for(i = 0; i < n; i++){
        printf("%d  ", a[i]);
    }

    printf("\n");

    return 0;
}

/*void swap(int num1, int num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}*/


void selection(int arr[], int n){
    int min, i, j, temp;
    for(i = 0; i < n-1; i++){
        min = i;

        for(j = i + 1; j < n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }

        if(min != i){
            //swap(arr[i], arr[min]);

            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}
