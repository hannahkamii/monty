#include "monty.h"

/**
 * mod - modulus of numbers
 * @s: stack head
 * @line_number: linenumber
 */
void mod(stack_t **s, unsigned int line_number)
{
	if (*s == NULL || (*s)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*s)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*s)->next->n %= (*s)->n;
	pop(s, line_number);
}

/**
 * push - insert into stack
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
 * pop - removes elements from stack
 * @s: stack head
 * @line_number: linenumber
 */

void pop(stack_t **s, unsigned int line_number)
{
	stack_t *temp = *s;

	(void)line_number;

	*s = (*s)->next;

	if (*s != NULL)
	{
		(*s)->prev = NULL;
	}

	free(temp);
}

/**
 * pall - prints elements of a list
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
 * main - main function
 * Return: 0
 */

int main(void)
{
	stack_t *s = NULL;

	push(&s, 3);
	push(&s, 4);
	push(&s, 5);

	mod(&s, 4);

	pall(&s, 5);

	while (s != NULL)
	{
		stack_t *temp = s;

		s = s->next;

		free(temp);
	}
	return (0);
}
