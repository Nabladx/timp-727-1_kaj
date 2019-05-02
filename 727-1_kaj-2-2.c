#include <stdio.h>
int main()
{	
	int n, x, k = 0;
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
	{
		scanf("%d", &x);
		k = k + x - i;
	}
	printf("%d\n", k);
	return 0;
}
