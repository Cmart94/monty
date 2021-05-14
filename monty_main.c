#include "monty.h"

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

void *compare_execution(char **array_words, stack_t **head, unsigned int n_line)
{
	instruction_t opcode_functions[] = {{"push", _push}, {"pall", _pall}, {NULL, NULL}};
	unsigned int i;

	/* comparar array words con opcode functions */
	while (opcode_functions[i].opcode != NULL)
	{
		if(strcmp(opcode_functions[i].opcode, array_words[0]) == 0)
		{
			printf("FUNCION COMPARADA, DENTRO DE COMPARE_EXECUTION: %s\n", opcode_functions[i].opcode);
			opcode_functions[i].f(head, n_line );
		}
		i++;
	}
	
}
void _push(stack_t **stack, unsigned int line_number)
{
	printf("ESTAMOS DENTRO FUNCION PUSH --------------------------------------\n");
	printf("direccion head %p\n", stack);
	printf("Numero de linea: %d\n", line_number);
}
void _pall(stack_t **stack, unsigned int line_number)
{
	printf("ESTAMOS DENTRO FUNCION PALL --------------------------------------\n");
        printf("direccion head %p\n", stack);
	printf("Numero de linea: %d\n", line_number);
}

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
