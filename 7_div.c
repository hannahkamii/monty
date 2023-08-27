#include "monty.h"

/**
 * push - insert into stack
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
 * pop - removes top element of stack
 * @s: head
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

/**
 * pall - prints elements of stack
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

	push(&s, 5);
	push(&s, 2);

	div_no(&s, 3);

	pall(&s, 4);

	while (s != NULL)
	{
		stack_t *temp = s;

		s = s->next;

		free(temp);
	}
	return (0);
}
