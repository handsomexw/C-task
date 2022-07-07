# C语言第三天



## 数据类型转换

​	**只有相同类型的数据才能运算，如果类型不同，需要先转换同类型后在进行计算。**

- 自动类型转换：

  - 转换规则：以不丢失数据为规则，可以适当浪费一些空间

  1. 字节少的向字节多的转： char --> int
  2. 有符号的向无符号的转： signed --> unsigned
  3. 整型向浮点型转换:  int --> float

  - 转换优先级从1到3
  - short 和 char 与不同类型数据运算时,会先提升到int类型后参与运算

- 强制类型转换:

  - (新类型名) 数据:   这种方法可能会丢失数据





## switch分支语句

```c
// switch 语句是开关,不是选择
switch() // n 的结果只能是整数
{
	case val: // val 必须是常量
		...
        break; // 关闭执行开关,结束switch语句.
    case val:
        ...
    default: //任何情况都会执行,放在任何位置最后执行.
        ...
}			 //switch 语句不能与continue同用.
```



**switch语句练习**

```c
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

```



## for循环语句

```c
for(循环变量; 循环条件; 改变循环变量)
{
    ... // 满足循环条件执行
    
}
//先读取循环变量,然后判断循环条件,执行代码,执行改变循环变量,判断循环条件.

```







tips:sizeof()取结果最大的