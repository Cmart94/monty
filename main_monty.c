#include "monty.h"
/**
* main - The entry point for Monty Interpreter
*
* @argc: count of arguments passed to the program
* @argv: pointer to an array of char pointers to arguments
*
* Return: void fuction, EXIT_FAILURE inc case of fail.
*/
char **GLOBAL_BUFFER;
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
	GLOBAL_BUFFER = array_lines;
	/* recorrer array de lineas para comparar con funciones */
	printf("Array de lineas es --------\n");
	for (i = 0; i < line_count; i++)
	{
		printf("\nLinea numero: %d\n", i + 1);
		printf("GLOBAL_VA: %s\n", GLOBAL_BUFFER[i]);
		/* Separar lineas por palabras 
		array_words = line_separator(array_lines[i]);
		if (array_words == NULL)
			continue;
			printf("PRIMER PALABRA: %s\n", array_words[0]);*/
		/*compar cada linea con comando monty
		compare_execution(array_words[0],&head, i);
		free(array_words);*/
	}

	free(buffer);
	free(array_lines);
}
