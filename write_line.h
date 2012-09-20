/**
 * This function copies 1 line from a file to another
 *
 * \para	source stream	
 * \para	target stream
 *
 * \return	void
 * */

int write_line(FILE* sp_read, FILE* sp_write)
{
	/* Local Declarations */
	int	count_chars;
	char	ch;

	/* Begin new line */
	fputc('\n', sp_write);

	/* Unless a character is a NEWLINE or EOF */
	while ((ch = fgetc(sp_read)) != '\n' && ch != EOF)
	{
		count_chars++;
		/* copy character to the target stream */
		fputc(ch, sp_write);
	}
	
	/* Insert the NEWLINE or EOF back into the input stream
	 * for use by the calling function */
	ungetc(ch, sp_read);
	count_chars--;

	/* Exit Function */
	return count_chars;
}

