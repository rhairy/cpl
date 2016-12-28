/* Write a program to detab that replaces tabs in the input with the proper number
 * of blanks to space to the next tab stop.  Assume a fixed set of tab stops, say 
 * every n columns.  Should n be a variable or a symbolic parameter? */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

	int d;
	while ( (d = getc(infile)) != EOF ) {
		if (d == '\t') {
			putc('\\', outfile);
			putc('t', outfile);
		} else if (d == '\b') {
			putc('\\', outfile);
			putc('b', outfile);	
		} else if (d == '\\') {
			putc('\\', outfile);
			putc('\\', outfile);
		} else if (d == '\n') {
			putc('\\', outfile);
			putc('n', outfile);
			putc('\n', outfile);
		} else {
			putc(d, outfile);
		}
	} 
	
	if (infile != stdin) {
		fclose(infile);
	}
	if (outfile != stdout) {
		fclose(outfile);
	}
	return 0;
}
