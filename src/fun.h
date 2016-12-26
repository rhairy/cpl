/* fun.h - Useful functions for CPL exercises. */

#include <stdio.h>

/* Removes trailing blanks and tabs from str. '\n' is preserved.
 * Accepts a pointer to a char array str and the size of the string
 * excluding '\n'. */
size_t rmtrail(char *str, const size_t len);
