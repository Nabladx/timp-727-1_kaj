#include <stdio.h>

#include <stdlib.h>



int heap(int *a, int i, int n)

{

	int max = i;

	while(1)

	{

		int child = 2 * i + 1;

		if (child < n && a[child] > a[max])

			max = child;

		child++;

		if (child < n && a[child] > a[max])

			max = child;

		if (max == i)

			break;

		else

		{

			int tmp = a[max];

			a[max] = a[i];

			a[i] = tmp;

			i = max;

		}

	}

	return 0;

}



int heapsort(int *a, int n)

{

	for (int i = n / 2; i >= 0; i--)

		heap(a, i, n);

	for (int i = n - 1; i >= 1; i--)

	{

		int tmp = a[0];

		a[0] = a[i];

		a[i] = tmp;

		heap(a, 0, i);

	}

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

	heapsort(arr, n);

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
