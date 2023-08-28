#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @s: stack head
 * @line_number: line number
 */

void swap(stack_t **s, unsigned int line_number)
{
	int temp;

	if (*s == NULL || (*s)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*s)->n;
	(*s)->n = (*s)->next->n;
	(*s)->next->n = temp;
}
