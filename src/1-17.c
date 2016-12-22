/* Write a program to print all input lines that are longer than
 * 80 characters. */

#include <stdio.h>
#define MAX 256
#define LEN 80

int rgetline(char *str, const unsigned max);

int main(int argc, char *argv[])
{
	char str[MAX];
	if (rgetline(str, MAX) >= LEN) {
		printf("%s\n", str);
	}
	return 0;
}

int rgetline(char *str, const unsigned max)
{
	int c;
	int len = 0;
	while ( (c = getchar()) != EOF && c != '\n' && len < max - 1 ) {
		str[len] = c;	
		len++;
	}
	str[len] = '\0';
	return len;
}
