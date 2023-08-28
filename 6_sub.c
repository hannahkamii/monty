#include "monty.h"

/**
 * sub - subtracts the top element of the stack from the second top element
 * @s: stack head
 * @line_number: linenumber
 */

void sub(stack_t **s, unsigned int line_number)
{
	if (*s == NULL || (*s)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	(*s)->next->n -= (*s)->n;
	pop(s, line_number);
}
