#include <stdio.h>
#include <string.h>
#include <limits.h>


void itoa(int n, char s[]);
void reverse(char s[]);

int main(void)
{
	int n = INT_MIN;
       	char s[20];	
	
	itoa(n,s);
	printf("%s\n", s);
	
	return 0;
}

void itoa(int n, char s[])
{
	int i, sign; 
	int isMIN = 0;
	if (n == INT_MIN) {
		isMIN = 1;	/* record that n = INT_MIN */ 
		n = n+1;  
	}
	if ((sign = n) < 0) /* record sign */
		n = -n;		
	
	i = 0;

	/* adjust first iteration to store correct digit */
	if (isMIN == 1) {
		s[i++] = (n % 10 + '0') + 1; 
		n /= 10; 
	}	
	do {	/* generate digits in reverse order */
		s[i++] = n % 10 + '0'; /* get next digit */
	} while ((n /= 10) != 0); /* delete it */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	   
	reverse(s);
}

void reverse(char s[])
{
	int c, i ,j;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
