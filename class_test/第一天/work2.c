#include <stdio.h>

int main(int argc,const char* argv[])
{
	// 由数学关系可得
	for(int num=0; num<4; num++)
	{
		printf("%d  %d  %d\n", 4*num, 25-7*num, 75+3*num);
	}
	printf("--------------------------\n");
	//暴力穷举
	for(int i=0;i<26;i++)
	{
		for(int j=0; j<(100-5*i)/3; j++)
		{
			int k =(100-5*i-3*j)*3;
			if(100 == (i+j+k))
			{
				printf("%d  %d  %d\n", i, j, k);	
			}
		}
	}
	printf("-----------------\n");

	for(int i=100; i<1001; i++)
	{
		int j = 2;
		for(; j<i/2; j++)
		{
			if(i%j == 0)
			{
				break;	
			}
		}

		if(j >= i/2)
		{
			printf("%d\n", i);	
		}
			
	}
	return 0;
}
