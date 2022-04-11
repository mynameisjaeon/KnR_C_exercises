/* Write a function invert(x,p,n) that return x with the n bits that begin at position p inverted(i.e., 1 changed into 0 and vice versa), leaving the others unchanged */
#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main(void)
{
	int n, p;
	unsigned x, z;
	
	printf("Enter x: ");
	scanf("%x", &x);
	printf("Enter n: ");
	scanf("%d", &n);
	printf("Enter p: ");
	scanf("%d", &p);

	z = invert(x,p,n);
	printf("result is: %x\n", z);

	return 0;
}

unsigned invert(unsigned x, int p, int n)
{
	return (((~(x >> (p+1-n)) << (p+1-n)) & ~(~0 << n) << (p+1-n)) | (x & ~(~(~0 << n) << (p+1-n)))); 	
	/* ( ~가& 나)<<(p+1-n)  = ~(x >> (p+1-n)) & ~(~0 << n) << (p+1-n)	......	00[inv.]00
	 *  (x & ~(~(~0 << 4) << (p+1-n))) 					......	xx 0000	xx	*/ 
}	
