#include "monty.h"

/**
 * push - insert elements into stack
 * @s: stack head
 * @value: push argument
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
 * @s: stack head
 * @line_number: line number
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
 * pall - prints all values on the stack
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

/**
 * main - main
 * Return: 0
 */
int main(void)
{
	stack_t *s = NULL;

	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	pall(&s, 4);

	swap(&s, 5);

	pall(&s, 6);

	while (s != NULL)
	{
		stack_t *temp = s;

		s = s->next;
		free(temp);
	}
	return (0);
}
