#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main()
{

    clock_t begin = clock();
    int n, k, i, temp, j;
    double time_spent;

    printf("Enter n: ");
    scanf("%d", &n);



    int arr[n];
    for(i = 0; i < n; i++){
        arr[i] = rand() % 1000;
    }



    for(i = 0; i < n; i++){
        for(j = 0; j< n-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("\nElements generated are:\n");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    printf("\n\nEnter key element: ");
    scanf("%d", &k);



    int found = BinSearch(arr, 0, n-1, k);

    //sleep(1);

    clock_t end = clock();

    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    if(found == -1){
        printf("\nElement not found!\n");
        printf("Elapsed time: %f secs\n",time_spent);
    }
    else{
        printf("\nElement found at index: %d\n", found);
        printf("Elapsed time: %f secs\n",time_spent);
    }


    return 0;
}

int BinSearch(int a[], int l, int h, int key){
    int mid;
    while(l <= h){
        mid = (l + h) / 2;

        if(key == a[mid]){
            return mid;
        }
        else if(key > a[mid]){
            return BinSearch(a, mid + 1, h, key);
        }
        else if (key < a[mid]){
            return BinSearch(a, l, mid - 1, key);
        }
    }
    return -1;

}

