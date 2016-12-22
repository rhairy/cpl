/* Write a program to print a histogram of the frequencies of different
 * characters in its input */

#include <stdio.h>

int main(int argc, char *argv[])
{
	/* Will hold the frequencies of each char recurrence; initialized to all zeroes. */
	int freq[128] = {0};
	int c;
	while ( (c = getchar()) != EOF ) {
		freq[c] += 1;
	}

	for (int i = 32; i < 128; i++) {
		printf("%c: ", i);
		for (int j = 0; j < freq[i]; j++) {
			putchar('*');
		}
		putchar('\n');
	}
	return 0;
}
