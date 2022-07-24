/* function setbits(x,p,n,y) that returns x with the n bits that begin at pos p set to rightmost n bits of y, leaving other bits unchanged */
#include <stdio.h>

int setbits(unsigned x, int p, int n, unsigned y);

int main(void)
{
	int n, p;
	unsigned x,y,z; 
	/*	
	x = 064;
	y = 057;
	*/
	printf("enter x: ");
	scanf("%o", &x);
	printf("enter y: ");
	scanf("%o", &y);
	
	printf("enter n: ");
	scanf("%d", &n);
	printf("enter p: ");
	scanf("%d", &p);

	printf("n: %d\np: %d\nx: %o\ny: %o\n", n, p, x, y);

	printf("will calculate setbits function with given values\n");
	z = setbits(x, p, n, y);
	printf("result: %o\n", z);


	return 0;
}

int setbits(unsigned x, int p, int n, unsigned y)
{
	return (((x >> (p+1-n)) & ~(~0 << n)) | (y & (~0 << n)));
}
