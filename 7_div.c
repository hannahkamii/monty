#include "monty.h"

/**
 * div_no - divides the second top element of the stack by the top elemen
 * @s: head
 * @line_number: linenumber
 */

void div_no(stack_t **s, unsigned int line_number)
{
	if (*s == NULL || (*s)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*s)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero", line_number);
		exit(EXIT_FAILURE);
	}
	(*s)->next->n /= (*s)->n;
	pop(s, line_number);
}
