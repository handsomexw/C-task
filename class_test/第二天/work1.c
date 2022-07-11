#include <stdio.h>

int main(int argc,const char* argv[])
{
	int arr[5][5] = {{2,8,9,6,4},{-5,10,7,6,20},
					 {6,8,10,6,5}};
	int m = 0, n = 0;

```c
for(int i=0; i<5;i++)
{
	for(int j=0;j<5;j++)
	{
		if(arr[i][j]<arr[m][n])
		{
			m = i;
			n = j;
		}
	}
}
int sum =0;
printf("min num = %d\n", arr[m][n]);
if(m-1>-1)
	sum +=arr[m-1][n];
if(m+1<5)
	sum +=arr[m+1][n];
if(n-1>-1)
	sum +=arr[m][n-1];
if(n+1<5)
	sum +=arr[m][n+1];
if(m-1>-1&&n-1>-1)
	sum +=arr[m-1][n-1];
if(m-1>-1&&n+1<5)
	sum +=arr[m-1][n+1];
if(m+1<5&&n-1>-1)
	sum +=arr[m+1][n-1];
if(m+1<5&&n+1<5)
	sum +=arr[m+1][n+1];

printf("sum= %d\n",sum);

//  循环累加
for(int x = min_x-1; x<=mix_x+1; x++)
	{
		for(int y=min_y-1;y<=min_y+1;y++)
			{
				if(x>=0&&x<=4&&y>=0&&y<=4)
				sum  += arr[x][y];	
			}
	}
	printf("%d\n", sum -arr[min_x][min_y]);
```


​	
	return 0;
}
