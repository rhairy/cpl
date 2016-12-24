/* Write a function reverse(s) that reverses the character string s.
 * Use it to write a program that reverses its input a line at a time. */

#include <stdio.h>

void reverse(char *str, const size_t len);

int main(int argc, char *argv[])
{
	char test1[] = {"hello"};
	char test2[] = {"thankful"};

	reverse(test1, 5);
	reverse(test2, 8);

	printf("%s\n", test1);
	printf("%s\n", test2);
	
	return 0;
}

void reverse(char *str, const size_t len)
{
	int i = 0;
	int j = len - 1;	
	char tmp;

	while (i <= j) {
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;	
		i++;
		j--;
	}
}
