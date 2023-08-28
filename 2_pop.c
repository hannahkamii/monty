#include "monty.h"

/**
 * pop - removes top element of stack
 * @s: stack head
 * line_number: number on line
 */
void pop(stack_t **s, unsigned int line_number)
{
	stack_t *temp;

	if (*s == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *s;
	*s = (*s)->next;

	free(temp);
}
