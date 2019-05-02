#include <stdio.h>

#include <stdlib.h>

int quick_sort(int *arr, int j)

{

	int size = j;

	int k = 0;

	int c = arr[(int)((j) / 2)];

	int tmp = 0;

	do {

		while (arr[k] < c)k++;

		while (arr[j] > c)j--;

		if (k <= j)

		{

			tmp = arr[k];

			arr[k] = arr[j];

			arr[j] = tmp;

			k++;

			j--;

		}

	} while (k <= j);

	if (j > 0) quick_sort(arr, j);

	if (size > k) quick_sort(arr + k,size-k);

	return 0;

}



int main()

{

	int n;

	int *arr;

	scanf("%d", &n);

	arr = (int*)malloc(n * sizeof(int)); // âûäåëåíèå ïàìÿòè ïîä ìàññèâ

	for (int i = 0; i < n; i++)

	{

		scanf("%d", &arr[i]);

	}

	quick_sort(arr, n-1);

	for (int i = 0; i < n; i++)

	{

		if (i == n - 1)

		{

			printf("%d", arr[i]);

		}

		else

		{

			printf("%d", arr[i]);

			printf(" ");

		}

	}

	printf("\n");

	

	return 0;

}
