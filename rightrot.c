#include <stdio.h>
unsigned rightrot(unsigned x, int n);

/*  KnR C Exercise 2-8
 * "Write a function rightrot(x,n) that return the value of int x rotated to the right by n position."
 * This program takes inputs in octal format only; also operates only up to 15 bits(5 octal digits)  */

int main(void)
{
	int n;
	unsigned x, z; 
	
	printf("enter x: ");
	scanf("%o", &x);
	printf("enter n: ");
	scanf("%d", &n);

	z = rightrot(x, n);
	if (z != -1) 
		printf("result: %o\n", z);	
	else
	       	printf("error: out of bounds\n");
	
	return 0;
}

unsigned rightrot(unsigned x, int n)
{
	int bit_cnt; 	/* in conducting rotation of bits, assumes the bit count of input by number of digits in the octal input. (i.e. bits in 023 is 6 04343 				is 12. */
	if (x < 8){
		bit_cnt = 3;
	}
	else if (x < 64){
		bit_cnt = 6;
	}
	else if (x < 512){
		bit_cnt = 9;
	}
	else if (x < 4096){
		bit_cnt = 12;
	}
	else if (x < 32768){
		bit_cnt = 15;
	}
	else if (x >= 32768){
		bit_cnt = -1; /* denotes out of bounds */
	}
	printf("%d\n", bit_cnt);
	/* return format experiment */
	if (bit_cnt != -1) 
		return ((x >> n) | ((x & ~(~0 << n)) << (bit_cnt - n)));
	else
	       	return bit_cnt;
}
/*    notes:
 * 1. copy rt most n-bits :	x & ~(~0 << n)
 * 2. shift x accordingly :	x >> n 
 * 3. paste 1. to 2. at lt-most position
 */
