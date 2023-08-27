#include "monty.h"

/**
 * push - insert elements in stack
 * @s: head pointer
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
 * pop - removes top element of stack
 * @s: head
 * @line_number: linenunmber
 */

void pop(stack_t **s, unsigned int line_number)
{
	stack_t *temp = *s;
	*s = (*s)->next;

	(void)line_number;

	if (*s != NULL)
	{
		(*s)->prev = NULL;
	}

	free(temp);
}

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

/**
 * pall - prints all the values on the stack, starting from the top
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

/**
 * main - main
 * Return: 0
 */
int main(void)
{
	stack_t *s = NULL;

	push(&s, 1);
	push(&s, 2);
	push(&s, 10);
	push(&s, 3);

	sub(&s, 4);

	pall(&s, 5);

	while (s != NULL)
	{
		stack_t *temp = s;

		s = s->next;

		free(temp);
	}
	return (0);
}
