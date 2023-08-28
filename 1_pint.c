#include "monty.h"

/**
 * pint - prints the value at the top of the stack, followed by a new line
 * @s: head node of the stack
 * @line_number: stack line number
 * Return:0
 */

void pint(stack_t **s, unsigned int line_number)
{
	if (*s == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*s)->n);
}
