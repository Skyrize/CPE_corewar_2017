#include <limits.h>

int char_to_int(unsigned char *num_champ)
{
	return (*(int *)num_champ);
}

int main()
{
	unsigned char test[4];
	test[0] = 133;
	test[1] = 147;
	test[2] = 166;
	test[3] = 187;
	//char c = 30;
	//unsigned int u = (unsigned char)c;
	printf("%d\n", char_to_int(test));
	printf("%d\n", 2147483647 - 3148256133);
}