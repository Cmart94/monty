#include "monty.h"
char **GLOBAL_BUFFER;
/**
 * _push - Pushes a value to a stack_t linked list.
 * @stack: A pointer to the head of the linked list
 * @line_number: line number of a Monty bytecodes file.
 */
void _push(stack_t **stack, unsigned int line_number)
{
	char *cpy_line = NULL, **array_words = NULL;
	printf("ESTAMOS DENTRO FUNCION PUSH --------------------------------------\n");
	cpy_line = strdup(GLOBAL_BUFFER[line_number]);
	array_words = line_separator(cpy_line);
	if (isdigit(array_words[1]) == 0)
	{
		/*fprintf(2, "L<%d>: unknown instruction <%s>\n", line_number,  GLOBAL_BUFFER[line_number]);*/
		exit(EXIT_FAILURE);
	}
	printf("VAMOS A INSERTAR %d A LA LISTA", atoi(array_words[1]));
}
/**
 * _pall - Prints the values of a stack_t linked list
 * @stack: A pointer to the head of the linked list
 * @line_number: line number of a Monty bytecodes file.
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	printf("ESTAMOS DENTRO FUNCION PALL --------------------------------------\n");
        printf("direccion head %p\n", stack);
	printf("Numero de linea: %d\n", line_number);
//HOLA ESTE ES UN COMENTARIO DE PRIEBA
}
/**
 * _pint - Prints the top value of a stack_t linked list
 * @stack: A pointer to the head of the linked list
 * @line_number: line number of a Monty bytecodes file.
 */
void _pint(stack_t **stack, unsigned int line_number);

/**
 * _pop - Removes the top value element of a stack_t linked list
 * @stack: A pointer to the head of the linked list
 * @line_number: line number of a Monty bytecodes file.
 */
void _pop(stack_t **stack, unsigned int line_number);
/**
 * _swap - Swaps the top two value elements of a stack_t linked list.
 * @stack: A pointer to the head of the linked list
 * @line_number: line number of a Monty bytecodes file.
 */
void _swap(stack_t **stack, unsigned int line_number);
