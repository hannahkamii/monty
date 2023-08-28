#include "monty.h"

/**
 * mod - modulus of numbers
 * @s: stack head
 * @line_number: linenumber
 */
void mod(stack_t **s, unsigned int line_number)
{
	if (*s == NULL || (*s)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*s)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*s)->next->n %= (*s)->n;
	pop(s, line_number);
	free(*s);
}
