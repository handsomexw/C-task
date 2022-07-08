#include <stdio.h>

int main(int argc,const char* argv[])
{
	int arr[10] = {10,9,8};
	int a=arr[0];
	for(int i=0; i<9;i++)
	{
		if(arr[i+1]>arr[i])
			a = arr[i+1];
	}
	printf("max num = %d\n", a);
	int b=arr[0];
	for(int i=0; i<9;i++)
	{
		if(arr[i+1]<arr[i])
			b = arr[i+1];
	}
	printf("mim num = %d\n", b);
	int c=0,avg=0;
	for(int i=0; i<9;i++)
	{
		c += arr[i];
	}
	avg = c/9;
	printf("avg num = %d\n", avg);
	int temp=0,k=0;
	int ar[10] = {10,9,8,7,6,5,4,3,2,1};
	for(int i=0;i<9;i++)
	{
		for(int j=0; j<10; j++)
		{
			if(ar[j]<ar[i])
				k = j;
		}
		temp = ar[i];
		ar[i] = ar[k];
		ar[k]= temp;
	}

	for(int i =0; i<10; i++)
	{
		printf("%d  ", ar[i]);	
	}


	return 0;
}
