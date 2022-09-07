#include <stdio.h>
#define MAXLINE 1000 

int getline(char s[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould"; /* pattern to search for */

/* find all lines matching pattern */
int main(void)
{
	char line[MAXLINE];
	int found = 0;
	int index = 0; 

	while (getline(line, MAXLINE) > 0)
		if ((index = strindex(line, pattern)) >= 0) {
			printf("%s", line);
			printf("%d\n", index);  
			found++;
		}
	
	return found;
}

/* getline: get line into s, return length */
int getline(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	
	return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
	int i, j, k;
	int cnt = 0; 	/* no. of patter occurence in line */
	int index = 0; 

	for (i = 0; s[i] != '\0'; i++) {
		for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
			;
	if (k > 0 && t[k] == '\0')
		++cnt;
		index = i; 
	}
	if (cnt > 0) 
		return index;
	return -1;
}
