/* fun.h - Useful functions for CPL exercises. */

#include <stdio.h>

/* Reverses a string. */
void reverse(char *str, const size_t len);

/* Removes trailing blanks and tabs from str by. 
 * Returns the length of the string without the empty space. */
size_t rmtrail(char *str, const size_t len);
