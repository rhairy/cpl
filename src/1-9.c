/* Exercise 1-9. Write a program to copy its input to its input
 * to its output, replacing each string of one or more blanks
 * by a single blank. */

#include <stdio.h>

int main(int argc, char *argv[])
{
	int c;
	int state = 0;

	while ( (c = getchar()) != EOF) {
		if (c == ' ' && state == 0) {
			state = 1;
			printf("%c", c);
		} else if (c == ' ' && state == 1) {
			continue;
		} else if (c != ' ' && state == 1) {
			state = 0;
			printf("%c", c);
		} else {
			printf("%c", c);
		}	
	}

	return 0;
}
