#include <stdio.h>

int main(int argc,const char* argv[])
{
	int month = 0;
	printf("请输入月份： ");
	scanf("%d", &month);
	if(month<1 || month>12)
	{
		printf("月份错误");
	}
	else
	{
		switch(month)
		{
			case 1:
			case 2:
			case 3:printf("春,");break;
			case 4:
			case 5:
			case 6:printf("夏,");break;
			case 7:
			case 8:
			case 9:printf("秋,");break;
			case 10:
			case 11:
			case 12:printf("冬,");break;
		}
		switch(month)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:printf("31天");break;
			case 2:printf("29天");break;
			default: printf("30天");break;
		}
	}
	return 0;
}
