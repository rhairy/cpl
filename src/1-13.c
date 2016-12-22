/* Exercise 1-13. Write a program to print a histogram of the lengths of words in
 * its input. */

#include <stdio.h>

#define IN 1
#define OUT 0

int main(int argc, char *argv[])
{
	int c;
	int state = 0;	
	int len = 0;
	while ( (c = getchar()) != EOF ) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (state == IN) {
				state = OUT;
				for (unsigned i = 0; i < len; i++) {
					putchar('*');
				}
				putchar('\n');
				len = 0;
			} else {
				continue;
			}
		} else {
			if (state == OUT) {
				state = IN;
				len++;
			} else {
				len++;
			}
		}
	}
	return 0;
}
