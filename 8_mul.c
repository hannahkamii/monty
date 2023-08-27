#include "monty.h"

/**
 * push - insert elements into stack
 * @s: head
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
 * mul - multiplies the second top element of the stack with the top element
 * @s: head
 * @line_number: linenumber
 */

void mul(stack_t **s, unsigned int line_number)
{
	if (*s == NULL || (*s)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*s)->next->n *= (*s)->n;
	pop(s, line_number);
}

/**
 * pop - removes top element of stack
 * @s: head
 * @line_number: linenumber
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
 * pall - prints all the values on the stack, starting from the top
 * @s: head
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
 * main - main function
 * Return: 0
 */

int main(void)
{
	stack_t *s = NULL;

	push(&s, 10);
	push(&s, 2);
	push(&s, 3);

	mul(&s, 4);

	pall(&s, 5);

	while (s != NULL)
	{
		stack_t *temp = s;

		s = s->next;

		free(temp);
	}
	return (0);
}
