/* Write a program to detab that replaces tabs in the input with the proper number
 * of blanks to space to the next tab stop.  Assume a fixed set of tab stops, say 
 * every n columns.  Should n be a variable or a symbolic parameter? */

#include <stdio.h>

#define N 1

int main(int argc, char *argv[])
{
	int c;
	while ( (c = getchar()) != EOF ) {
		if (c == '\t') {
			for (unsigned i = 0; i < N; i++) {
				putchar(' ');	
			}
		} else {
			putchar(c);
		}
	}
	return 0;
}
