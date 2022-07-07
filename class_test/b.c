#include <stdio.h>

int main(int argc,const char* argv[])
{
	int year = 0, month = 0;
	printf("请输入需要判断的年份和月份： ");
	scanf("%d%d", &year, &month);
	int valu_1 =0, valu_2 = 0,valu_3 = 0;
	valu_1 = ((year%4 ==0) && (year%400 == 0));
	valu_2 = (year%100 == 0);
	if((valu_1 && !valu_2))
	{
		printf("润年,");	
		valu_3 = 1;
	}
	else
	{
		printf("非润年,");
		valu_3 = 2;
	}
	valu_1 = month == 1 || month==3||month==5||month==7||month==8||month==10||month==12;
	valu_2 = month==4||month==6||month==9||month==11;
	if(valu_1)
	{
		printf("31天");	
	}
	if(valu_2)
	{
		printf("30天");	
	}
	if(valu_3==1)
	{
		printf("28天");
	}
	else
	{
		printf("29天");	
	}

	return 0;
}
