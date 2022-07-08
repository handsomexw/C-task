#include <stdio.h>

int main(int argc,const char* argv[])
{
	int max_num = 0,second_num = 0;
	int third_num =0;
	printf("请输入三个随机整数：");
	int num_1= 0, num_2 = 0, num_3= 0;
	scanf("%d%d%d", &num_1, &num_2, &num_3);
	if(num_1>num_2)
	{
		max_num = num_1;
		second_num = num_2;
	}
	else
	{
		max_num = num_2;
		second_num = num_1;
	}

	if(num_3>max_num)
	{
		printf("%d,%d,%d", num_3, max_num, second_num);	
	}
	else
	{
		if(num_3>second_num)
		{
			printf("%d,%d,%d", max_num, num_3, second_num);	
		}
		else
		{
			printf("%d,%d,%d", max_num, second_num, num_3);	
		}
	}

	return 0;
}
