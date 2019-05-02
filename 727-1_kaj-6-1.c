#include <stdio.h>

#include <stdlib.h>

int sort_hairbrush(int *arr, int arr_len)

{

	int x;

	double fakt = 1.2473309; // ôàêòîð óìåíüøåíèÿ

	int d = arr_len - 1; //øàã

	while (d >= 1)

	{

		for (int i = 0; (i + d) < arr_len; i++)//ãîíèì êðàéíèå ýëåìåíòû

		{

			if (arr[i] > arr[i + d])

			{

				x = arr[i];

				arr[i] = arr[i + d];

				arr[i + d] = x;

			}

		}

		d /= fakt;

	}

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

	sort_hairbrush(arr, n);

	

	for (int i = 0; i < n; i++)

	{
		if(i == n -1)
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
