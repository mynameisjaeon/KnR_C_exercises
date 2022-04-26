#include <stdio.h> 
/* exercise 2-9 improved bitcount */
int bitcount(int x);

int main(void)
{
	int x;
	
	scanf("%o", &x);
	x = bitcount(x);
	printf("count: %d\n", x);

	return 0;
}

int bitcount(int x)
{
	int b; 

	for(b=0; x!=0; x &= (x-1))
		b++;

	return b; 
}
