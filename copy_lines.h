/**
 * This function copies lines beginning with a user-specified character
 *
 * \para	user-specified character
 *
 * \return	number of lines copied
 * */

#define LINEBREAK printf("\n")

/* Function Declarations */
int copy_lines(char usr_ch);
char write_line(char ch, FILE* sp_read, FILE* sp_write);

/* Function Definitions */
int copy_lines(char usr_ch)
{
	/* Local Declarations */
	int	count_lines = 0;
	int	count_lines_copied = 0;
	char	ch;
	FILE*	sp_read;
	FILE*	sp_write;
	
	/* Open streams for reading and writing */
	if ((sp_read = fopen("speech.txt", "r")) == NULL)
	{
		LINEBREAK;
		printf("ERROR 1: The file speech.txt failed to open");
		return -1;
	}

	if ((sp_write = fopen("af_exec.txt", "w")) == NULL)
	{
		LINEBREAK;
		printf("ERROR 1: The file af_exec.txt failed to open");
		return -1;
	}

	/* Read from the 'src' stream */
	do
	{
		ch = fgetc(sp_read);


	}
	while ((ch = fgetc(sp_read)) != EOF)
	{	
		/* if you are reading the first character in 'src' and it
		 * matches the user specified character */
		if ((count_chars_src == 1) && (ch == usr_ch))
			count_lines_copied = write_line();

		/* if you start reading a newline */
		if (ch == '\n')
		{
			/* and you find it beginning with the user specified character */
			if ((ch = fgetc(sp_read)) == usr_ch)
			{

				/* copy the line */
				ch = write_line (ch, sp_read, sp_write);
				count_lines_copied++;
				ungetc(ch, sp_read);
			}
		}
	}

	/* Close all open streams */
	if (fclose(sp_read) == EOF)
	{
		LINEBREAK;
		printf("ERROR 2: The file speech.txt failed to close");
		return -2;
	}

	if (fclose(sp_write) == EOF)
	{
		LINEBREAK;
		printf("ERROR 2: The file af_exec.txt failed to close");
		return -2;
	}
	/* Exit Function */
	return count_lines_copied;
}

/* Write line */
int write_line (char ch, FILE* sp_read, FILE* sp_write)
{

	/* begin newline in 'tgt' stream*/
	fputc('\n', sp_write);
	
	/* and write all characters from 'src' until end of line */
	while (ch != '\n' && ch != EOF)
	{
		fputc(ch, sp_write);
		ch = fgetc(sp_read);
	}

	return ch;
}

