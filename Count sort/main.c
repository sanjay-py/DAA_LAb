#include <stdio.h>
#include <stdlib.h>

void countSort(int a[], int n){

    int count[50];
    int output[50];
    int i, j;

    for(i = 0; i <= n; i++){
        count[i] = 0;
    }

   for(i = 0; i < n - 1; i++)
   {
        for(j = i + 1; j < n; j++)
        {
            if(a[i] < a[j]){
                count[j]++;
            }
            else{
                count[i]++;
            }
        }
   }

    for(i = 0; i < n; i++){
        output[count[i]] = a[i];
   }

   printf("\n\nSorted Elements are: ");
   for(i = 0; i < n; i++)
    {
       printf("%d ",output[i]);
    }
    return;

}

int main()
{
   int i, n;

    printf("Enter size: ");
    scanf("%d",&n);

    int a[n];
    printf("\nEnter the array elements:\n");
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    countSort(a, n);

    printf("\n");
}


