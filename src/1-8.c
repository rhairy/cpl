/* Exercise 1-8. Write a program to count blanks, tabs, and newlines. */

#include <stdio.h>

int main(int argc, char *argv[])
{
	int c, nb, nt, nl;
	nb = nt = nl = 0;

	while ( (c = getchar()) != EOF) {
		if (c == ' ') {
			nb++;
		} else if (c == '\t') {
			nt++;
		} else if (c == '\n') {
			nl++;
		} else {
			continue;
		}
	}
	printf("blanks: %i\ntabs: %i\nlines: %i\n", nb, nt, nl);
	return 0;
}
