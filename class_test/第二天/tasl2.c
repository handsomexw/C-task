#include <stdio.h>

int main(int argc,const char* argv[])
{
	int arr[10] = {3,5,9,6,8,12,90,65,63,25};
	int val = 0;
	int max_1 = arr[0], max_2 = arr[1];
	for(int i =1;i<10;i++)
	{
		if(max_1<arr[i])
		{
			max_2=max_1;
			max_1= arr[i];
		}
		else if(max_2<arr[i])
		{
			max_2 = arr[i];	
		}
	}

	printf("max_1=%d max_2=%d\n",max_1,max_2);
	for(int i=0;i<9;i++)
	{
		val = arr[i]>arr[i+1]?i:i+1;	
	}
	int num = 0;
	for(int i =0;i<9;i++)
	{
		if(i!=val)
		{
			num = (arr[val]-arr[i])<(arr[val]-arr[i+1])?i:i+1;	
		}
	}
	printf("%d", arr[num]);

	return 0;
}
