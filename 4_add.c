#include "monty.h"

/**
 * push - insert items in stack
 * @s: head of stack
 * @value: value to be pushed
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
 * pall - prints all the values on the stack
 * @s: head of stack
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
 * add - adds top two elements of stack
 * @s: head of stack
 * @line_number: line number
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

/**
 * pop - removes top element of stack
 * @line_number: line number
 * @s: head of stack
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
 * main - main code
 * Return: 0
 */

int main(void)
{
	stack_t *s = NULL;

	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	pall(&s, 4);

	add(&s, 5);

	pall(&s, 6);

	pop(&s, 7);

	while (s != NULL)
	{
		stack_t *temp = s;

		s = s->next;

		free(temp);
	}

	return (0);
}
