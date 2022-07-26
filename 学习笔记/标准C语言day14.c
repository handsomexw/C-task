### Makefile
    Makefile是由一系列编译指令组成的可执行文本文件，也叫编译脚本
    在终端执行 make 命令，就会自动执行Makefile脚本文件中的编译指令，它可根据文件的最后修改时间来判断哪些文件需要重新编译、哪些不需要重新编译，从而提高编译效率

```c
编译规则：
1. 如果这个工程没有编译过，那么我们的所有c 文件都要编译并被链接。
2. 如果这个工程的某几个c 文件被修改，那么我们只编译被修改的c 文件，并链接目标程序。
3. 如果这个工程的头文件被改变了，那么我们需要编译引用了这几个头文件的c 文件，并链接目标程序。

一个最简单Makefile格式：      
执行目标: 依赖
    编译指令
被依赖的目标1：依赖文件
    编译指令
被依赖的目标2：依赖文件
    编译指令
    ...
```

2048游戏：
    文件规则：
    main.c                  程序入口
    game2048.c game2048.h   游戏的业务逻辑
    direction.c direction.h 四个方向处理
    tools.c tools.h         工具函数
    Makefile                编译脚本
    

![](D:\C++课程笔记\老师完整版\makefile_pic.png)



2048小游戏代码实现：

```c
//主函数
#include <stdio.h>
#include "game2048.h"

int main(int argc,const char* argv[])
{
	init_game();
	start_game();
	end_game();	
	return 0;
}
//功能函数
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game2048.h"
#include "tools.h"

int if_same(void)
{
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(infe[i][j]==infe[i+1][j] || infe[i][j]==infe[i][j+1])
			{
				return 1;	
			}
		}
	}
	return 0;
}
void rand_num(void)
{
	if(cnt == 1) 
		return;
	cnt = 1;
	int sum=0;
	//判断是否还有空位
	int q=0,k=0;
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			if(infe[i][j] == 0)
			{
				sum = 1;
				q = i; k = j;
				i = 4; j = 4;
			}	
		}
	}
	int x=0,y=0,l=5;	
	if(sum == 0) 
	{
		if(if_same())
		{
			return;
		}
		else
		{
			flag = 0;
			return;
		}
	}
	int num = 0;
	while(l)
	{
		srand(time(NULL));
		x = rand()%4;
		y = rand()%4;
		num = (rand()%2 + 1)*2;
		if(infe[x][y]==0)
		{
			infe[x][y] = num;
			break;
		}
		l--;
	}
	if(l==0)
	{
		infe[q][k] = num;	
	}

}
void show(void)
{
	system("clear");
	for(int i=0; i<4; i++)
	{
		printf("---------------------\n");
		for(int j=0; j<4; j++)
		{
			if(infe[i][j])
				printf("|%4d", infe[i][j]);
			else
				printf("|    ");
		}
		printf("|\n");
	}
	printf("---------------------\n");
}
void if_win(void)
{
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			if(infe[i][j] == 64)
				flag = 0;
		}
	}
}

//游戏业务逻辑
#include <stdio.h>
#include <stdlib.h>
#include <getch.h>
#include "tools.h"
#include "direction.h"
#include "game2048.h"

int (*infe)[4] = NULL;
int score = 0;
int flag = 1;
int cnt = 0;

void init_game(void)
{
	//申请堆内存
	infe = calloc(4*4,4);
}
void start_game(void)
{
	for(;;)
	{
		//随机位置生成2/4
		rand_num();
		//显示界面
		show();
		//获取方向键并处理
		if(flag)
		{
			switch(getch())
			{
				case 183: up(); break;
				case 184: down(); break;
				case 186: left(); break;
				case 185: right(); break;
			}
		}
		

		if_win();
		if(!flag) break;
	}

}

void end_game()
{
	show();
	printf("您的得分是：%d，请再接再厉！\n",score);
	free(infe);
    infe = NULL;
}



```

```c
//各方向指令处理
#include "game2048.h"
#include "tools.h"

void up(void)
{
	//检测并合并
	int m=0,n=0;
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			if(infe[i][j])
			{
				m = i;
				n = i-1;
				for(;n>=0;n--)
				{
					if(infe[m][j] == infe[n][j])
					{
						infe[n][j] += infe[m][j];
						infe[m][j] = 0;	
						score++;
						cnt = 0;
					}
					if(infe[n][j] !=0 && infe[m][j] != infe[n][j])
						break;
				}
			

			}
		
		}
	}
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			if(infe[i][j])
			{
				m = i;
				n = i-1;
				for(;n>=0;n--)
				{
					if( 0 == infe[n][j])
					{
						infe[n][j] = infe[m][j];
						infe[m][j] = 0;	
						m--;
						cnt = 0;
					}
				}
			}
		}
	}
}

void right(void)
{
	int m=0,n=0;
	for(int i=3; i>=0; i--)
	{
		for(int j=3; j>=0; j--)
		{
			if(infe[i][j])
			{
				m = j;
				n = j+1;
				for(;n<4;n++)
				{
					if( infe[i][m] == infe[i][n])
					{
						infe[i][n] += infe[i][m];
						infe[i][m] = 0;	
						score++;
						cnt = 0;
					}
					if(infe[i][n] != 0 && infe[i][m] != infe[i][n])
						break;
				}
			}
		}
	}
	

	for(int i=3; i>=0; i--)
	{
		for(int j=3; j>=0; j--)
		{
			if(infe[i][j])
			{
				m = j;
				n = j+1;
				for(;n<4;n++)
				{
					if( 0 == infe[i][n])
					{
						infe[i][n] = infe[i][m];
						infe[i][m] = 0;
						m++;
						cnt = 0;
					}
				}
			}
		}
	}

}

void down(void)
{
	int m=0,n=0;
	for(int i=3; i>=0; i--)
	{
		for(int j=3; j>=0; j--)
		{
			if(infe[i][j])
			{
				m = i;
				n = i+1;
				for(;n<4;n++)
				{
					if( infe[m][j] == infe[n][j])
					{
						infe[n][j] += infe[m][j];
						infe[m][j] = 0;	
						score++;
						cnt = 0;
					}
					if(infe[n][j] != 0 && infe[m][j] != infe[n][j])
						break;
				}
			}
		}
	}
	

	for(int i=3; i>=0; i--)
	{
		for(int j=3; j>=0; j--)
		{
			if(infe[i][j])
			{
				m = i;
				n = i+1;
				for(;n<4;n++)
				{
					if( 0 == infe[n][j])
					{
						infe[n][j] = infe[m][j];
						infe[m][j] = 0;
						m++;
						cnt = 0;
					}
				}
			}
		}
	}

}

void left(void)
{
	//检测并合并
	int m=0,n=0;
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			if(infe[i][j])
			{
				m = j;
				n = j-1;
				for(;n>=0;n--)
				{
					if(infe[i][m] == infe[i][n])
					{
						infe[i][n] += infe[i][m];
						infe[i][m] = 0;	
						score++;
						cnt = 0;
					}
					if(infe[i][n] !=0 && infe[i][m] != infe[i][n])
						break;
				}
			

			}
		
		}
	}
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			if(infe[i][j])
			{
				m = j;
				n = j-1;
				for(;n>=0;n--)
				{
					if(0 == infe[i][n])
					{
						infe[i][n] = infe[i][m];
						infe[i][m] = 0;
						m--;
						cnt = 0;	
					}
				}	
			}
		}
	}

}
```

