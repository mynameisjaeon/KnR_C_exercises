#include <stdio.h>
/* Exercise 2-10 : Rewrite the fuction 'lower', which converts uppercase letters to lower case, with a conditional expression instead of if-else */
int lower(int c);

int main(void)
{
	char b;
	int c;

	scanf("%c", &b);	
	c = b;	 

	c = lower(c);
	printf("%c\n", c);
	
	return 0;
}

int lower(int c)
{
	int b; 

	b = (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;

	return b;
}

