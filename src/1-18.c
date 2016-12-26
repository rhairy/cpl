/* Write a program to remove trailing blanks and tabs from each line of
 * input, and to delete entirely blank lines. */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "fun.h"


int main(int argc, char *argv[])
{
	int c;
	char *inpath = NULL;
	char *outpath = NULL;
	FILE *infile = NULL;
	FILE *outfile = NULL;

	while ( (c = getopt(argc, argv, "i:o:")) != -1 ) {
		switch (c) {
		case 'i':
			inpath = optarg;
			break;
		case 'o':
			outpath = optarg;
			break;
		case '?':
			break;
		default:
			break;
		}
	}

	if (inpath == NULL) {
		infile = stdin;
	} else {
		infile = fopen(inpath, "r");
		if (infile == NULL) {
			perror("fopen: ");
			return -1;
		}
	} 

	if (outpath == NULL) {
		outfile = stdout;
	} else {
		outfile = fopen(outpath, "w");
		if (outfile == NULL) {
			perror("fopen: ");
			fclose(infile);
			return -1;
		}
	}

	char *str = NULL;
	int res;
	size_t len = 0;
	size_t rm_len;

	while ( (res = getline(&str, &len, infile)) != -1 ) {
		if ( (rm_len = rmtrail(str, res)) > 0) {
			fwrite(str, sizeof(char), rm_len, outfile);
		}
		free(str);
		str = NULL;
	}
	return 0;
}
