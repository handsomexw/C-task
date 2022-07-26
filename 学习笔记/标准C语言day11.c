复习：
堆内存管理
    1、C语言中没有管理堆内存的语句，只能使用标准库中的函数
    void *malloc(size_t size);
    功能：从堆内存申请size个字节的连续内存块
    返回值：内存块的首地址
    注意：void* 在C语言中是万能指针，可以与任意类型指针相互转换，但是在C++中不能自动转换成其它类型的指针，如果想让代码在C++编译器中兼容，需要进行强制类型转换
        int* p = (int*)malloc(4);

```c
free
功能：释放一块堆内存
注意：不能连续释放同一个地址，但是可以释放NULL
calloc、realloc

常见的面试题：
1、堆内存与栈内存区别？
    是什么、谁管理、大小、使用、安全、优点、缺点
2、堆内存越界的后果？
    1、超过分配的33页产生段错误
    2、破坏了malloc的维护信息，再次使用malloc\free会出错
    3、脏数据
3、什么是内存泄漏？如何定位内存泄漏？
    由于业务逻辑出错或者粗心大意导致使用完毕的堆内存没有正常释放，当再次需要时又重新申请，又没有释放，长时间积累下导致可用的内存越来越少，系统就会越来越慢甚至系统崩溃，这种就叫做内存泄漏
    1、windows查看任务管理器、Linux命令ps -aux、GDB查看进程中的内存分布情况
    2、借助mtrace代码分析工具，查看漏写了free
    3、封装malloc、free函数，记录申请、释放内存信息到日志中
```

一、字符串
    字符：
        在计算机中字符都是以整数形式存储的，当需要显示成字符时，就会根据ASCII码表中的对应关系显示出相应的符号或图案
        '\0'    0       空字符
        '0'     48
        'A'     65
        'a'     97

    串：是一种数据结构，由一组连续的若干个类型相同的数据组成，末尾一定有一个结束标志
        对于这种数据结构的处理都是批量性，从开始的地方一直处理到结束标志停止
    字符串：
        由字符组成的串形结构，结束标志是 '\0'

二、字符串的存在形式
    字符数组：
        char str[6] = {'a','b','c','d','e'};
        由char类型组成的数组，要为'\0'预留位置
        使用是栈内存，数据可以中途修改的
    

    字符串字面值：
        "由双引号包含的若干个字符"
        末尾会自动补'\0'
        字符串字面值以地址形式存在，字符数据存在代码段，如果修改一定会产生段错误
        注意：完全相同的字符串字面值，在代码段中只存在一份
        const char* p = "字符串字面值";
        sizeof(p);     4/8
        sizeof("abcd"); 5 计算字符串字面值在代码段中所占的内存字节数，包括'\0'   
    
    常用方式：
        字符数组[] = "字符串字面值";
        会自动给'\0'预留位置、可以修改内容、初始化简单
        赋值完成后字符串存在两份，一份在代码段、一份在栈内存(可被修改)

三、字符串的输入、输出
    输入：
    char str[256] = {};
    scanf("%s",str);
    缺点：不能输入带空格的字符串，也存在越界的可能性

    char *gets(char *s);
    功能：可以输入带空格的字符串
    返回值：返回s，为了链式调用，一个函数的返回值直接作为了另一个函数的参数
    缺点：不限制输入长度，有安全隐患，编译器会有警告
    
    char *fgets(char *s, int size, FILE *stream);
    功能：从stream中最多输入size-1个字符到s中
    s：字符数组
    size：最多接收的字符个数+1
    stream：stdin 相当于键盘文件 固定写
    返回值：链式调用
    注意：如果输入超过size-1个字符，多出来不接收
          如果输入不足size-1，'\n'也会接收
    
    输出：
        printf("%s",字符数组/字符串字面值);
        int puts(const char *s);
        功能：输出字符串
        返回值：成功输出字符的个数
        注意：会自动打印换行符
    
    练习1：实现一个判断字符串是否是回文串的函数
    "abccba" "abcba"
    练习2：实现一个函数，把一个由数字字符组成的字符串转换成对应的整数
    "1234"  1234
    练习3：实现一个函数，把一个字符串逆序
    "abcd" "dcba"

四、输出缓冲区
    程序中要输出显示内容并不会立即显示到屏幕上，而是先存储在输出缓冲区中，当满足一定条件时才会从缓冲区中显示内容到屏幕上
    1、遇到 '\n' 后
    2、遇到输入语句时
    3、当输出缓冲区满了 4k
    4、程序结束时
    5、手动刷新 fflush(stdout);

五、输入缓冲区
    程序并不是立即从键盘获取输入的内容，而是当按下回车后，终端输入的内容会先存储到输入缓冲区中，然后输入函数再从输入缓冲区中读取数据到内容中。
    1、当想要读取整型或浮点型数据，但是缓冲区中的数据是符号或字母时，读取会失败，数据会残留在缓冲区中，影响接下来所有数据的读取
        解决：判断scanf的返回值是否全部数据输入正确，如果不是，先清理输入缓冲区再重新输入，直到全部正确为止

2、fgets可以接受指定size-1个字符，如果有多余的字符会残留在缓冲区中，可能会影响接下来的输入
    解决方法1：
        1、先判断'\n'在不在字符串内，如果不在，则说明在缓冲区内，需要清理缓冲区
        2、如果在缓冲区内，则
        scanf("%\*[\^\\n]");
        从缓冲区中读任意数据并丢弃，如果不是'\n'，继续读取，直到遇到'\n'，停止读取(正则表达式)
        scanf("%*c");
        从缓冲区中读一个字符，并丢弃
        注意：可以考虑封装新的fgets函数解决输入过多问题
    解决方法2：
        把输入缓冲区中的当前位置指针，移动到缓冲区末尾，相当于清理了输入缓冲区，但是只能在Linux/UNIX系统中使用这两个位置指针
        stdin->_IO_read_ptr = stdin->_IO_read_end;

3、当先输入整型、浮点型数据（其他类型的数据），再输入字符、字符串时，前一次的输入会残留'\n'（或者空格）,影响了后面字符、字符串的输入
    解决：scanf(" %c",&ch);（不同数据直接加空格）

六、字符串相关操作函数
    #include <string.h>
    size_t strlen(const char *s);
    功能：计算字符串字符长度，不包括'\0'

    char *strcpy(char *dest, const char *src);
    功能：把src拷贝给dest，相当于给dest赋值 =
    返回值：链式调用
    
    char *strcat(char *dest, const char *src);
    功能：把src追加到dest末尾，相当于合并两个字符串，+=
    返回值：链式调用
    
    int strcmp(const char *s1, const char *s2);
    功能：比较两个字符串大小
         从头开始，每个字符一对一进行比较，按照字典序，谁出现在前谁小，一旦比较出结果，立即返回结果，后面的不再比较
    返回值：
        0       s1 == s2
        正数    s1 > s2
        负数    s1 < s2
    
    作业：自己实现strlen\strcpy\strcat\strcmp 四个字符串处理函数 【常考】


    char *strncpy(char *dest, const char *src, size_t n);
    char *strncat(char *dest, const char *src, size_t n);
    int strncmp(const char *s1, const char *s2, size_t n);

​       

```c
#include <stdio.h>
#include <assert.h>
size_t  m_strlen(const char* s)
{
	assert(s != NULL);
	const char* temp = s;
	while(*temp++);
	return temp-s-1;
/*	int len = 0;
	while(s[len]) len++;
	return len;
*/
}

char* m_strcpy(char* s1, const char* s2)
{
//	int i=0;
//	for( ;s2[i]!=0; i++) s1[i] = s2[i];
//	s1[i] = 0;
	assert(s1 != NULL && s2 != NULL);
	char* start = s1;
	while((*s1++=*s2++)!=0);
	return start;
}
char* m_strcat(char* s1, const char* s2)
{
/*	int i = 0,j = 0;
	while(s1[i]!=0) i++;
	while(s2[j++]!=0) s1[i++] = s2[j-1];s1[i]=0;
	return s1;
	*/
	assert(s1 != NULL && s2 != NULL);
	char* temp = s1;
	while(*temp) temp++;
	while(*temp++=*s2++);
	return s1;
}
int m_strcmp(const char* s1,const char* s2)
{
/*	int i = 0;
	while(s1[i]!=0 && s2[i]!= 0 && s1[i]-s2[i]==0) i++;
	if(s1[i]-s2[i]==0) return 0;else if(s1[i]-s2[i]>0) return 1; else return -1;
	*/
	assert(s1 != NULL && s2 != NULL);
	while(*s1 == *s2 && *s1) s1++,s2++;
	return *s1-*s2>0?1:*s1-*s2<0?-1:0;
}
int main(int argc,const char* argv[])
{
	char str[50] = "hahaxixicaca";
	char str1[50] = "hehe";
//	printf("%d\n", m_strlen(str));
//	printf("%s\n", m_strcpy(str1,str));
//	printf("%s\n", m_strcat(str,str1));
	printf("%d\n", m_strcmp(str,str1));
	return 0;
}
```


​    
​    



小项目：通讯录系统

​	要求：存储联系人信息：

​	姓名，性别，电话

功能要求

1. 增删改查

2. 显示所有联系人信息



注意事项：空指针判断，

思路构建：

数据存储用指针数组

增：增加之后加排序，冒泡排序

删：指针后退；

改：只改关键信息，

查：如何实现模糊查找：？



功能菜单：switch



printf()显示界面

switch()实现功能选择

模糊查找



getch（）？