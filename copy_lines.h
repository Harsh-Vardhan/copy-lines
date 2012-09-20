/**
 * This function copies lines beginning with a user-specified character
 *
 * \para	user-specified character
 *
 * \return	number of lines copied
 * */
#include "write_line.h"

int copy_lines(char usr_ch)
{
	/* Local Declarations */
	int	count_chars = 0;
	int	count_lines = 0;
	int	count_blank_lines = 0;
	int	count_lines_copied = 0;
	char	ch;
	FILE*	sp_read;
	FILE*	sp_write;
	
	/* Open streams for reading and writing */
	if ((sp_read = fopen("speech.txt", "r")) == NULL)
	{
		printf("\nERROR 1: The file speech.txt failed to open");
		return -1;
	}

	if ((sp_write = fopen("af_exec.txt", "w")) == NULL)
	{
		printf("\nERROR 1: The file af_exec.txt failed to open");
		return -1;
	}

	/* Read from the 'src' stream until EOF */
	while ((ch = fgetc(sp_read)) != EOF)
	{
		/* Increment the no. of characters read */
		count_chars++;

		/* If a newline begins */
		if (ch == '\n' || (count_chars == 1))
		{
			/* Increment the no. of lines read */
			count_lines++;

			/* Read its first character and check it's not a 
			 * newline again */
			while ((ch = fgetc(sp_read)) == '\n')
			{
				count_chars++;
				count_lines++;
				count_blank_lines++;
			}


			/* If it matches the user specified character */
			if (ch == usr_ch)
			{
				/* Insert the matching character back into the 
				 * input stream, as it is read again while
				 * copying the line */
				ungetc(ch, sp_read);

				/* Copy and write line to target stream */
				count_chars = count_chars + write_line(sp_read, sp_write);

				/* Increment the no. of lines copied */
				count_lines_copied++;
			}
		}
	}

	/* Close all open streams */
	if (fclose(sp_read) == EOF)
	{
		printf("\nERROR 2: The file speech.txt failed to close");
		return -2;
	}

	if (fclose(sp_write) == EOF)
	{
		printf("\nERROR 2: The file af_exec.txt failed to close");
		return -2;
	}

	/* Display function results */
	printf("\n");
	printf("\nCharacters read = %d", count_chars);
	printf("\nLines read = %d", count_lines);
	printf("\nBlank lines found = %d", count_blank_lines);

	/* Exit Function */
	return count_lines_copied;
}


