#include <stdio.h>
#include <ctype.h>
#define MAXLINE 	1000
#define PROCEEDEXPAND 	1
#define HOLD		0

enum chartypes { ISDIGIT = 1, ISLOWER = 2, ISUPPER = 3 };

/* expand.c : expand string such as a-z to equivalent complete list */ 

void expand(char s1[], char s2[]);

int main(void)
{
	int i,c;
	char s1[MAXLINE], s2[MAXLINE];
	i=0;

	while((c=getchar())!=EOF)
	{
		s1[i++] = c;
	}
	s1[i++] = '\0'; 

	expand(s1, s2);
	printf("%s\n", s2);
	
	return 0;
}

void expand(char s1[], char s2[])
{
	int i,j,k, i_ref;
	char lt, rt;
	int status, char_code1, char_code2; /* char_code is number enumerated above */

	i = 0; j = 0; 	
	status = HOLD;		

	while(s1[i] != '\0')
	{
		status = HOLD;
		i_ref = i; 
		if(isalnum(s1[i]))
		{
			if(isdigit(s1[i])) char_code1 = ISDIGIT; 	/* 1 */
			else if (islower(s1[i])) char_code1 = ISLOWER;	/* 2 */
			else if (isupper(s1[i])) char_code1 = ISUPPER; 	/* 3 */
			lt = s1[i++];
			if(s1[i] == '-')
			{
				i++;	
				if(isalnum(s1[i]))
				{
				rt = s1[i];
				if(isdigit(s1[i])) char_code2 = ISDIGIT; 	/* 1 */
				else if (islower(s1[i])) char_code2 = ISLOWER;	/* 2 */
				else if (isupper(s1[i])) char_code2 = ISUPPER; 	/* 3 */
					/* modify later to account for cases where rt-lt = 0 */
					if (char_code1 == char_code2 && (rt-lt > 0))  
					{
						status = PROCEEDEXPAND;
						i++;
					}	 	
				}	
			}
		}
		if(status == PROCEEDEXPAND)
		{
			for(k = 0; k <= (rt-lt); k++)
			{
				s2[j++] = lt + k; 
			}	
		}
		if(status == HOLD)	
		{
			i = i_ref; 
			s2[j++] = s1[i++];
		}
	}
}
