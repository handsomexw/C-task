#include <stdio.h>

int main(int argc,const char* argv[])
{
	int n =0;
	printf("请输入要打印的层数： ");
	scanf("%d", &n);
	int arr[n+1][n+1];
	char a[1] = {' '};
	if(n == 0)
		printf("%c", a[0]);

	for(int i=0;i<n;i++)
	{
			arr[i][0] = 1;
			arr[i][i] = 1;
	}

	for(int i=2; i<n; i++)
	{
		for(int j=1;j<i;j++)
		{
			arr[i][j] = arr[i-1][j-1] + arr[i-1][j];	
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
			printf("%d  ",arr[i][j]);

		printf("\n");
	}
	return 0;
}
