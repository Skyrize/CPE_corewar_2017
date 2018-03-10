int my_atoi(unsigned char *p) {
    int k = 0;
    int active = 0;

	printf("debug p : %s\n", p);
    while (*p) {
	k = (k<<3)+(k<<1)+(*p)-'0';
	printf("debug : %d\n", k);
	p++;
     }
     return k;
}

int main()
{
	printf("%d\n", my_atoi("42"));
}