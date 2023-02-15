#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[50];
	char pattern[20];
    int shift[27];
    int n, m, i;

    printf("Enter the string: ");
	scanf("%s", str);

	n =strlen(str);

	printf("Enter the pattern: ");
	scanf("%s", pattern);

	m = strlen(pattern);

	for(i = 0; i < 27; i++)
	{
		shift[i] = m;
	}

	for(i = 0; i < m - 1; i++)
	{
		shift[pattern[i] - 64] = m - i - 1;
	}

	for(i = 0; i < n - m; i++){

	}




    printf("\n");

	return 0;
}
