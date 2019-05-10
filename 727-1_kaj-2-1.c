#include <stdio.h>
int main()
{	
	int a, n, k = 0;
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
	{	
		scanf("%d", &a);
		if(a >= 0)
		{
			k++;
		}
	}
	printf("%d\n", k);
}	
