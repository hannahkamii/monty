#include "monty.h"

/**
 * mul - multiplies the second top element of the stack with the top element
 * @s: head
 * @line_number: linenumber
 */

void mul(stack_t **s, unsigned int line_number)
{
	if (*s == NULL || (*s)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*s)->next->n *= (*s)->n;
	pop(s, line_number);
}
