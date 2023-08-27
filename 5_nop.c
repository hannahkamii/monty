#include "monty.h"

/**
 * push - insert elements to stack
 * @s: stack head
 * @value: value to push
 */
void push(stack_t **s, int value)
{
	stack_t *nw_nd = malloc(sizeof(stack_t));

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
 * pall - prints all the values on the stack, starting from the top
 * @s: stack head
 * @line_number: line number
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

/**
 * nop - opcode does non do anything
 * @s: stack head
 * @line_number: linenumber
 */

void nop(stack_t **s, unsigned int line_number)
{
	(void)s;
	(void)line_number;
}

/**
 * main - function
 * Return: 0
 */

int main(void)
{
	stack_t *s = NULL;

	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	pall(&s, 4);

	nop(&s, 5);

	pall(&s, 6);

	while (s != NULL)
	{
		stack_t *temp = s;

		s = s->next;

		free(temp);
	}
	return (0);
}
