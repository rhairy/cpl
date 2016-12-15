/* Exercise 1-5. Modify the temperature conversion program to print
 * the table in reverse order, that is, from 300 degrees to 0. */

#include <stdio.h>

int main(int argc, char *argv[])
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	celsius = upper;
	
	printf("celsius fahr\n");
	while (celsius >= lower) {
		fahr = (celsius * (9.0 / 5.0)) + 32;
		printf("%3.0f %9.1f\n", celsius, fahr);
		celsius -= step;
	}
	return 0;
}
