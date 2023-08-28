#include "monty.h"

/**
 * add - add elements of the stack
 * @s: stack head
 * @line_number: line_number
 */

void add(stack_t **s, unsigned int line_number)
{
	if (*s == NULL || (*s)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*s)->next->n += (*s)->n;
	pop(s, line_number);
}
