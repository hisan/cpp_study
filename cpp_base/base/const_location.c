#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int d = 20;
static int e = 30;
int f = 50;
int g;
static int h;
const int i;

int main()
{
	char *a = "memry test";
	const int b = 10;
	static int c = 40;
	const int j;
	static int k;
	
	printf("&a: 0x%x\n",&a);
	printf("a: 0x%x\n",a);
	printf("&b: 0x%x\n",&b);
	printf("&c: 0x%x\n",&c);
	printf("&d: 0x%x\n",&d);
	printf("&e: 0x%x\n",&e);
	printf("&f: 0x%x\n",&f);
	printf("&g: 0x%x\n",&g);
	printf("&h: 0x%x\n",&h);
	printf("&i: 0x%x\n",&i);
	printf("&j: 0x%x\n",&j);
	printf("&k: 0x%x\n",&k);
	
	int *pheap = (int *)malloc(sizeof(int)*10);
	printf("pheap: 0x%x\n",pheap);
	printf("&pheap: 0x%x\n",&pheap);

	while(1)
	{
		
	}

	return 0;
}


#if 0

	1.整理打印结果,如下:
	
		&a: 0xbff1491c
		&b: 0xbff14920
		&j: 0xbff14924
	&pheap: 0xbff14928
		
		&d: 0x8048620
		 a: 0x8048624
		 
		&e: 0x804a020
		&f: 0x804a024
		&c: 0x804a028
		&h: 0x804a030
		&k: 0x804a034
		&g: 0x804a038
		&i: 0x804a03c
		
	 pheap: 0x9c3f410
	
	
	2.找到该进程的pid并进入该进程的目录下查看maps:
	
	root@ubuntu:/proc/2858# cat maps
	08048000-08049000 r-xp 00000000 08:01 794013     /home/zyb/CODE/CPP/cpp_base/base/location
	08049000-0804a000 r--p 00000000 08:01 794013     /home/zyb/CODE/CPP/cpp_base/base/location
	0804a000-0804b000 rw-p 00001000 08:01 794013     /home/zyb/CODE/CPP/cpp_base/base/location
	087cd000-087ee000 rw-p 00000000 00:00 0          [heap]
	b7dc3000-b7dc4000 rw-p 00000000 00:00 0
	b7dc4000-b7f74000 r-xp 00000000 08:01 938786     /lib/i386-linux-gnu/libc-2.23.so
	b7f74000-b7f75000 ---p 001b0000 08:01 938786     /lib/i386-linux-gnu/libc-2.23.so
	b7f75000-b7f77000 r--p 001b0000 08:01 938786     /lib/i386-linux-gnu/libc-2.23.so
	b7f77000-b7f78000 rw-p 001b2000 08:01 938786     /lib/i386-linux-gnu/libc-2.23.so
	b7f78000-b7f7b000 rw-p 00000000 00:00 0
	b7f92000-b7f93000 rw-p 00000000 00:00 0
	b7f93000-b7f96000 r--p 00000000 00:00 0          [vvar]
	b7f96000-b7f98000 r-xp 00000000 00:00 0          [vdso]
	b7f98000-b7fbb000 r-xp 00000000 08:01 938797     /lib/i386-linux-gnu/ld-2.23.so
	b7fbb000-b7fbc000 r--p 00022000 08:01 938797     /lib/i386-linux-gnu/ld-2.23.so
	b7fbc000-b7fbd000 rw-p 00023000 08:01 938797     /lib/i386-linux-gnu/ld-2.23.so
	bfa03000-bfa24000 rw-p 00000000 00:00 0          [stack]


	map文件分析:
	1).前三行,为可执行文件location的内存映射。
		1.1). 第一行,为代码区(文本段)，所以权限为读和执行。
		
		1.2). 第二行,为数据段中的只读数据段,所以权限为只读.
		
		1.3). 第三行,为数据段中的剩余部分.
		
		对照我们的变量，可知:
			1) 全局常量和字符串常量位于代码区.
			
			2) 函数内的常量(无论是否初始化)和函数内的变量位于栈区.
			
			3) 函数内的静态变量(无论是否初始化)、函数外的静态变量(无论是否初始化)、全局变量(无论是否初始化)、未初始化的全局常量,都位于数据段的非只读数据段中.
			
			4) 动态分配的内存位于堆区中.
#endif

	
	
	
	
	
	
			
	
	
	
	
	
	
	
	