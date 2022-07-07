#include <stdio.h>

int main(int argc,const char* argv[])
{
	int i=0,j=0,temp=0;
	for(i=1;i<10;i++)
	{
		for(j=1;j<=i;j++)
		{
			temp = i*j;
			printf("%d*%d=%d\t", j, i, temp);
		}

		printf("\n");
	}

	return 0;
}
