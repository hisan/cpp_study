#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int *p = malloc(sizeof(int)*10);
	char *str = malloc(20000);
	
	printf("%d\n",(int)str[-1]);
	printf("%d\n",p[-1]);
	
	free(p);
	free(str);
	return 0;
}
