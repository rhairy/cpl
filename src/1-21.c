/* Exercise 1-21. Write a program entab that replaces strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing. Use the same
 * tab stops as for detab.  When either a tab or a single blank would suffice
 * to reach a tab stop, which should be given preference? */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define IN 1
#define OUT 0

int main(int argc, char *argv[])
{
	int c;
	int n = 4;
	char *inpath = NULL;
	char *outpath = NULL;
	FILE *infile = NULL;
	FILE *outfile = NULL;

	while ( (c = getopt(argc, argv, "i:n:o:")) != -1 ) {
		switch (c) {
		case 'i':
			inpath = optarg;
			break;
		case 'n':
			n = atoi(optarg);
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
	if (n <= 0) {
		n = 4;
	} 
	
	int d;
	int nb = 0; // Number of blanks.
	int state = OUT;
	while ( (d = getc(infile)) != EOF ) {
		if (d == ' ') {
			if (state == IN) {
				nb++;	
			} else {
				state = OUT;
				nb++;
			}
		} else {
			if (state == IN) {
				state = OUT;
				if (nb == n) {
					putc('\t', outfile);
					nb -= n;
				} else if (nb > n) {
					while (nb > 0) {
						if (nb > n) {
							putc('\t', outfile);
							nb -= n;
						} else {
							putc(' ', outfile);
							nb--;
						}
					}
				}
				putc(d, outfile);
			} else {
				putc(d, outfile);
		}
		}
	}
}
