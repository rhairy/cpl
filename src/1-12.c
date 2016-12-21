/* Exercise 1-12. Write a program that prints its input one word per line. */

#include <stdio.h>

#define IN 1
#define OUT 0

int main(int argc, char *argv[])
{
	int c;
	int state = 0;
	while ( (c = getchar()) != EOF ) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (state == IN) {
				state = OUT;
				putchar('\n');
			} else {
				continue;
			}
		} else {
			if (state == OUT) {
				state = IN;
				putchar(c);
			} else {
				putchar(c);
			}
		}
	}
	return 0;
}
