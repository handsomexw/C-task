#include <stdio.h>

int main(int argc,const char* argv[])
{
	float score = 0;
	printf("请输入你的成绩：");
	scanf("%f", &score);
	if(score>100 || score<0)
	{
		printf("成绩有误");	
	}
	else if(score>=90)
	{
		printf("A");	
	}
	else if(core>=80)
	{
		printf("B");	
	}
	else if(score>=70)
	{
		printf("C");	
	}
	else if(score>=60)
	{
		printf("D");	
	}
	else
	{
		printf("E");
	}

	return 0;
}
