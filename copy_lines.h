/**
 * This function copies lines beginning with a user-specified character
 *
 * \para	user-specified character
 *
 * \return	number of lines copied
 * */

/* Function Definitions */
int copy_lines(char usr_ch)
{
	/* Local Declarations */
	int	count_lines_read = 0;
	int	count_lines_copied = 0;
	int	current_line = 1
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
		if (ch == '\n')
		{
			/* Read its first character */
			ch = fgetc(sp_read);

			/* If it matches the user specified character */
			if (ch == usr_ch)
			{
				/* Insert the matching character back into the 
				 * input stream, as it is read again while
				 * copying the line */
				ungetc(ch, sp_read);

				/* Copy and write line to target stream */
				write_line(sp_read, sp_write);

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
	/* Exit Function */
	return count_lines_copied;
}


