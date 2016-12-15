/* Excercise 1-3. Modify the temperature conversion program to print a 
 * above the table. */

#include <stdio.h>

int main(int argc, char *argv[])
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	/* ADDED STATEMENT HERE. */
	printf("fahr celsius\n");
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	return 0;
}
