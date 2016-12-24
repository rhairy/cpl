/* Write a program to remove trailing blanks and tabs from each line of
 * input, and to delete entirely blank lines. */

#include <stdio.h>
#include <stdlib.h>

#define IN 1
#define OUT 0

int main(int argc, char *argv[])
{
	char *str = NULL;
	int res;
	size_t len = 0;
	int i;

	while ( (res = getline(&str, &len, stdin)) != -1 ) {
		// Set i equal to the last element of the string, not counting the null terminator..
		i = res;
		// Work backwards to find the first whitespace char.
		while (i > 0 && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\0')) {
			i--;
		}
		// If a non-whitespace char was found, set the char after it to the null terminator.
		if (i > 0) {
			i = i + 1;
			str[i] = '\0';	
		}
		printf("%s\n", str);
		free(str);
		str = NULL;
	}
	return 0;
}
