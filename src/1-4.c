/* Exercise 1-4. Write a program to print the corresponding
 * Celsius to Fahrenheit. */

#include <stdio.h>

int main(int argc, char *argv[])
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	celsius = lower;
	/* ADDED STATEMENT HERE. */
	printf("celsius fahr\n");
	while (celsius <= upper) {
		fahr = (celsius * (9.0 / 5.0)) + 32;
		printf("%3.0f %9.1f\n", celsius, fahr);
		celsius += step;
	}
	return 0;
}
