#include "monty.h"
/**
* main - The entry point for Monty Interpreter
*
* @argc: count of arguments passed to the program
* @argv: pointer to an array of char pointers to arguments
*
* Return: Success (EXIT_SUCCESS) or error (EXIT_FAILURE)
*/
void main(int argc, char *argv[])
{
	FILE *fd1, *fd2;
	int cl1, cl2;
	unsigned int i = 0, line_count = 0, j = 0;
	char *buffer = NULL, **array_lines = NULL, **array_words = NULL;
	stack_t *head = NULL;

	/* numero Argumentos es diferente a 2?*/
	if (argc != 2)
	{
		perror("cantidad de argumentos invalido");
		exit(EXIT_FAILURE);
	}
	/* Abrir archivo */
	fd1 = fopen(argv[1], "r");
	fd2 = fopen(argv[1], "r");
	if ((fd1 == NULL) | (fd2 == NULL))
	{
		perror("No se pudo abrir archivo");
		exit(EXIT_FAILURE);
	}
	/* Llenamos el buffer con characteres del archivo */
	buffer = fill_buffer(fd1, fd2);
	if (buffer == NULL)
	{
		perror("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	/* Cerramos descriptores*/
	cl1 = fclose(fd1);
	cl2 = fclose(fd2);
	if ((cl1 == EOF) | (cl2 == EOF))
	{
		printf("No se pudo cerrar archivo");
		exit(EXIT_FAILURE);
	}
	printf("Contenido de archivo en array -------------\n");
	printf("%s", buffer);
	line_count = _line_count(buffer);
	/* Agregar cada linea a doble puntero de lineas */
	array_lines = file_separator(buffer);
	if (array_lines == NULL)
	{
		perror("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	/* recorrer array de lineas para comparar con funciones */
	printf("Array de lineas es --------\n");
	for (i = 0; i < line_count; i++)
	{
		printf("numero de linea: %d", i);
		printf("%s\n", array_lines[i]);
		/* Separar lineas por palabras */
		array_words = line_separator(array_lines[i]);
		/*compar cada linea con comando monty*/
		compare_execution(array_words,&head, i);
		free(array_words);
	}

	free(buffer);
	free(array_lines);
}