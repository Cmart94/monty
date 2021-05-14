#include "monty.h"
/**
* compare_execution - compare array words with opcode functions 
*
* Return: void
*/
void *compare_execution(char *word, stack_t **head, unsigned int n_line)
{
	instruction_t opcode_functions[] = {{"push", _push}, {"pall", _pall}, {NULL, NULL}};
	unsigned int i;

	/* comparar array words con opcode functions */
	while (opcode_functions[i].opcode != NULL)
	{
		if(strcmp(opcode_functions[i].opcode, word) == 0)
		{
			printf("FUNCION COMPARADA, DENTRO DE COMPARE_EXECUTION: %s\n", opcode_functions[i].opcode);
			opcode_functions[i].f(head, n_line );
		}
		i++;
	}
}
