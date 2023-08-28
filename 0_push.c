#include "monty.h"

/**
 * push - insert elements into stack
 * @s: stack head
 * @value: value to push
 */

void push(stack_t **s, int value)
{
	stack_t *nw_nd = malloc(sizeof(stack_t));

	if (*s == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", value);
		exit(EXIT_FAILURE);
	}
	nw_nd->n = value;
	nw_nd->prev = NULL;
	nw_nd->next = *s;
	
	if (*s != NULL)
	{
		(*s)->prev = nw_nd;
	}
	*s = nw_nd;
}

/**
 * pall - print content of stack
 * @s: stack head
 * @line_number: linenumber
 */

void pall(stack_t **s, unsigned int line_number)
{
	stack_t *cnt = *s;

	(void)line_number;

	while (cnt != NULL)
	{
		printf("%d\n", cnt->n);

		cnt = cnt->next;
	}
}
