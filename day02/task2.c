#include <stdio.h>

int main(int argc,const char* argv[])
{
	int a=0, b=0, c=0;
	for(int i=100; i<1000; i++)
	{
		a = i%10;
		b = (i/10)%10;
		c = i/100;

		if(i == a*a*a+b*b*b+c*c*c)
		{
			printf("%d\n", i);	
		}
	}

	int num= 0,k=0;
	printf("请输入一个正整数：");
	scanf("%d", &num);
	for(int i =2; i<num; i++)
	{
		if(num%i == 0)
		{
			printf("不是素数");
		}
		k = i+1;
	}
	if(k == num)
		printf("素数");
	return 0;
}
