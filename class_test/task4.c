#include <stdio.h>

int main(int argc,const char* argv[])
{
	int code = 123456;
	int code_n = 0;
	printf(" 请输入6位密码： ");
	int num = 1;
	do{
		scanf("%6d", &code_n);
		if(code_n == code)
		{
			printf("登录成功");
			break;
		}
		else if(num == 3)
		{
			break;	
		}
		else
		{
			printf("密码错误，重新输入密码：");
			num += 1;
		}
	}while(num<=3);
	
	if(num == 3)
		printf("帐号已锁定，请联系柜台");

	return 0;
}
