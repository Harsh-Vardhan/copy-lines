/* 
 * Main Program
 * */

#include <stdio.h>
#include "copy_lines.h"

#define LINEBREAK printf("\n")
#define FLUSH while (getchar() != '\n')

int main(void)
{
	/* Local Declarations */
	int	count_lines_copied;
	char	usr_ch;

	/* Program Intro */
	LINEBREAK;
	printf("This program copies lines beginning with the user specified character");

	/* Read user specified character */
	LINEBREAK;
	printf("Please type in a character (a-z): ");
	while(scanf("%c", &usr_ch) != 1 )
		printf("ERROR: Invalid input, try again: ");

	/* Call function to copy lines matching the user specified character */
	LINEBREAK;
	printf("Copying lines...");
	count_lines_copied = copy_lines(usr_ch);
	LINEBREAK;
	printf("Done... a total of %d lines were copied", count_lines_copied);

	/* Exit Program */
	LINEBREAK; LINEBREAK;
	return 0;
}

