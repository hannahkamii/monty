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
/**
 * free_s - free stack
 * @s: head node of stack
 * Return: 0
 */
void free_s(stack_t *s)
{
	while (s != NULL)
	{
		stack_t *temp = s;

		s = s->next;
		free(temp);
	}
}

/**
 * main - main function
 * Return: 0
 */
int main(void)
{
	stack_t *s = NULL;

	stack_t *nw_nd = malloc(sizeof(stack_t));

	nw_nd->n = 1;
	nw_nd->prev = NULL;
	nw_nd->next = s;
	s = nw_nd;

	nw_nd = malloc(sizeof(stack_t));
	nw_nd->n = 2;
	nw_nd->prev = NULL;
	nw_nd->next = s;
	s = nw_nd;

	nw_nd = malloc(sizeof(stack_t));
	nw_nd->n = 3;
	nw_nd->prev = NULL;
	nw_nd->next = s;
	s = nw_nd;

	pint(&s, 1);

	pint(&s, 2);

	pint(&s, 3);

	free_s(s);

	return (0);
}
