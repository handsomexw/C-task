#include <stdio.h>

int main(int argc,const char* argv[])
{
	int year=0, month=0,day=0;
	printf("请输入一个日期：");
	scanf("%d %d %d", &year, &month, &day);
	int sum = 0;
	if(month>12 || day>31)
	{
		printf("输入日期有误！\n");
		return;
	}
	for(int i=1;i<year;i++)
	{
			sum = sum + 365 + (i%4 == 0&& i%100 != 0 || i%400 == 0);
	}
	for(int j=1;j<month;j++)
	{
		switch (j)
		{
			case 2: sum = sum + 28 + (year%4 == 0&& !year%100 == 0 || year%400 == 0);break;
			case 4:
			case 6:
			case 9:
			case 11: sum = sum + 30;break;
			default : sum = sum + 31;

		}
	}
	sum = sum + day-1;
	printf("据日期：%d 天", sum);
	return 0;
}
