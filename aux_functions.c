#include "monty.h"
/**
* file_separator - Separates the buffer lines
*
* Return: An array of input buffer lines
*/
char **file_separator(char *buffer)
{
	char **array_lines = NULL;
	unsigned int line_count = 0, i, j = 0, flag_line = 1;

	/* sacar cantidad de lineas */
	line_count = _line_count(buffer);
	printf("Cantidad de lineas es: %d\n", line_count);
	/* Agregar cada linea a doble puntero de lineas */
	array_lines = malloc(sizeof(char*) * line_count);
	if (array_lines == NULL)
	{
		free(array_lines);
		return (NULL);
	}
        for (i = 0; buffer[i] != '\0'; i++)
	{
		if (flag_line == 1)
		{
			array_lines[j] = &buffer[i];
			flag_line = 0;
		}
		if (buffer[i] == '\n')
		{
			buffer[i] = '\0';
			flag_line = 1;
			j++;
		}
	}
	return (array_lines);
}
/**
* _line_count - counts the buffer lines
*
* Return: The number of lines counted
*/
unsigned int  _line_count(char *buffer)
{
	unsigned int i, line_count = 0;

	for (i = 0; buffer[i] != '\0'; i++)
	{
		if (buffer[i] == '\n')
			line_count++;
	}
	return (line_count);
}
/**
* fill_buffer - fill the buffer with the characters from the file
*
* Return: Buffer full
*/
char *fill_buffer(FILE *fd1, FILE *fd2)
{
	char *buffer, c;
	unsigned int file_len = 0, i = 0;

	while ((c = fgetc(fd1)) != EOF)
		file_len++;
	/* Llenamos el buffer con characteres del archivo */
	buffer = malloc(sizeof(char) * (file_len + 1));
	if (buffer == NULL)
		return (NULL);
	while ((c = fgetc(fd2)) != EOF)
	{
		buffer[i] = c;
		i++;
	}
	buffer[file_len] = '\0';
	return (buffer);
}
/**
* line_separator - separate words from each line
*
* Return: array of words from each line
*/
char **line_separator(char *line_opcode)
{
	char **array_words = NULL, *token = NULL, *cpy = strdup(line_opcode);
	int words_count = 0, i = 0;

	token = strtok(cpy, " ");
	while (token != NULL)
	{
		words_count++;
		token = strtok(NULL, " ");
	}
	free(cpy);
	array_words = malloc(sizeof(char *) * words_count);
	if (array_words == NULL)
		exit(EXIT_FAILURE);
	token = strtok(line_opcode, " ");
	while (token != NULL)
	{
		array_words[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	return (array_words);
}