#include <stdio.h>

void constexpr_test()
{
	int num = 10;
	int array[num] = {0};
}

int main()
{
	constexpr_test();
	return 0;
}