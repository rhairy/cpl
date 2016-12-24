/* Write a program to remove trailing blanks and tabs from each line of
 * input, and to delete entirely blank lines. */

#include <stdio.h>
#include <stdlib.h>

#include "fun.h"


int main(int argc, char *argv[])
{
	char *str = NULL;
	int res;
	size_t len = 0;

	while ( (res = getline(&str, &len, stdin)) != -1 ) {
		rmtrail(str, res);
		printf("%s\n", str);
		free(str);
		str = NULL;
	}
	return 0;
}
