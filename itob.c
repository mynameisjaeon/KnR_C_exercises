#include <stdio.h>

/* KnR Exercise 3-5 Write function itob(n,s,b) that converts int n into a base b character representation in the string s. (ie. itob(n,s,16) formats s as a hexa integer in s. */

#define MAXLINE 10

void itob(int n, char s[MAXLINE], int b); 

int main (void)
{
	int n;
	char s[MAXLINE];
	int b;
	int i;

	for(i=0; i<10; i++) {
		s[i] = '\0';
	}
	printf("input number : ");
	scanf("%d", &n);
	printf("input base : ");
	scanf("%d", &b);

	itob(n, s, b);	
	printf("result : %s\n", s); 

	return 0;
}
		
void itob(int n , char s[], int b)
{
	char s_0[MAXLINE]; 
	int i=0; 
	int j=0; 

	while ((n/b) != 0) {
		s_0[i] = n%b;
		printf("%d\n", s_0[i]);
		i++;
		n = n/b; 
	}
	s_0[i] = n%b;
	printf("%d\n", s_0[i]);

	while (i >= 0) {
		if (s_0[i] > 9) {
			s[j] = s_0[i] - 10 + 'A'; 
		}
		else
			s[j] = s_0[i] + '0'; 
	       	i--;
		j++;	
	}
}         
