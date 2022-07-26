字符串相关操作函数：
    int atoi(const char *nptr);
    功能：字符串转int类型
    long atol(const char *nptr);
    功能：字符串转long类型
    long long atoll(const char *nptr);
    功能：字符串转long long类型
    double atof(const char *nptr);
    功能：字符串转double类型

```c
char *strstr(const char *haystack,const char *needle);
功能：在haystack中查找是否存在子串needle
返回值：needle在haystack中首次出现的位置，如果找不到则返回NULL

int sprintf(char *str,const char *format, ...);
功能：把各种类型的数据输出给字符串str
返回值：转换后字符个数

int sscanf(const char *str,const char *format,...);
功能：从str中解析读取数据到变量中
返回值：成功解析出来的变量个数
```

  void *memcpy(void *dest,const void *src,size_t n);
  功能：从src位置拷贝n个字节到dest的位置
  功能：链式调用

  int memcmp(const void *s1,const void *s2,size_t n);
  功能：比较两块内存的值，按照字节比较，一旦比较出结果后面不再比较
    返回值： s1 == s2  0
             s1 < s2  负数
             s1 > s2  正数

小项目：通讯录系统
    要求：存储联系人信息：
            姓名、性别、电话 
         最大存储量50人
    功能要求：
        1、增加联系人
        2、按名字删除联系人
        3、按名字修改联系人信息
        4、查找联系人，按照电话或者姓名，支持模糊查找
        5、显示所有联系人信息
        6、退出系统

