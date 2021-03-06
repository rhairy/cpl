/* fun.c - Useful functions for CPL exercises. */
#include "fun.h"

void reverse(char *str, const size_t len)
{
	int i = 0;
	int j = len - 1;	
	char tmp;

	while (i <= j) {
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;	
		i++;
		j--;
	}
}

size_t rmtrail(char *str, const size_t len)
{
	/* Starting at the penultimate element (assuming last '\0'),
 	 * work backwords until a non-whitespace char is found. */ 
	unsigned i = len - 1;
	while (i > 0 && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')) {
		i--;
	}
	/* If i is 0, then then the line has no non-whitespace characters,
 	 * and can be ignored. Otherwise return the length of the new string. */
	if (i == 0) {
		return 0;
	} else {
		str[++i] = '\n';
		str[++i] = '\0';
		return i;
	}
}
