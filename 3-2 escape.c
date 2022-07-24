#include <stdio.h>
#define MAXLINE 1000

/* 
exercise 3-2 : write a function escape(s,t) that converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for the other direction as well, converting escape sequences into the real characters. */



void escape(char s[MAXLINE], char t[MAXLINE]);

int main(void)
{
	int i=0;
	int c; 
	char s[MAXLINE], t[MAXLINE];
	
	while ((c=getchar()) != EOF) {
		t[i++] = c;
	}
	t[i] = '\0'; 		/* NULL to indicate end of str */

	escape(s,t); 
	printf("%s", s); 		
	
	return 0;
}

void escape(char s[], char t[])
{
	int i, j;
	i=0;
	j=0;
	while (t[i] != '\0') {
		switch (t[i]) {
		case '\n':
			s[j++] = '\\';
			s[j++] = 'n';
			i++;
			break;
		case '\a' : 
			s[j++] = '\\';
			s[j++] = 'a';
			i++;
			break;
		case '\b' :
			s[j++] = '\\';
			s[j++] = 'b';
			i++;
			break;
		case '\t' :
			s[j++] = '\\';
			s[j++] = 't';
			i++;
			break;
		case '\v' :
			s[j++] = '\\';
			s[j++] = 'v';	
			i++;
			break;
		case '\r' :
			s[j++] = '\\';
			s[j++] = 'r';
			i++;
			break;
		case '\\' :
			s[j++] = '\\';
			s[j++] = '\\';
			i++;
			break;
		case '\?' :
			s[j++] = '\\';
			s[j++] = '?';
			i++;
			break;
		case '\'' : 
			s[j++] = '\\';
			s[j++] = '\'';
			i++;
			break; 
		case '\"' :
			s[j++] = '\\';
			s[j++] = '\"';
			i++;
			break;
 
		default :
			s[j++] = t[i++];
			break;
		}
	}
	s[j] = '\0';
}
