#include <stdio.h>

#include <stdlib.h>

int sort_shell(int *arr, int arr_len)

{

	int temp; // âðåìåííàÿ ïåðåìåííàÿ äëÿ õðàíåíèÿ çíà÷åíèÿ ýëåìåíòà ñîðòèðóåìîãî ìàññèâà

	int	item; // èíäåêñ ïðåäûäóùåãî ýëåìåíòà

	int d = arr_len / 2;

	while (d > 0)

	{

		for (int i = 1; i < arr_len - d; i++)

		{

			int j = i;

			while (j >= 0 && arr[j] > arr[j + d]) // ïîêà èíäåêñ íå ðàâåí 0 è ïðåäûäóùèé ýëåìåíò ìàññèâà áîëüøå òåêóùåãî

			{

				temp = arr[j];

				arr[j] = arr[j + d]; // ïåðåñòàíîâêà ýëåìåíòîâ ìàññèâà

				arr[j + d] = temp;

				j--;

			}

		}

		d = d / 2;

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

	sort_shell(arr, n);

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
