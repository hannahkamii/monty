#include "monty.h"

/**
 * push - insert elements in the stack
 * @s: stack head
 * @value: value to push
 * Return: 0
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
 * line_number: number on line
 */
void pop(stack_t **s, unsigned int line_number)
{
	stack_t *temp;

	if (*s == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *s;
	*s = (*s)->next;

	free(temp);
}

/**
 * pall - prints all value of stack
 * @s: stak head
 * line_number: line number
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
	push(&s, 3);

	pall(&s, 4);
	pop(&s, 5);
	pall(&s, 6);
	pop(&s, 7);
	pall(&s, 8);
	pop(&s, 9);
	pall(&s, 10);

	while (s != NULL)
	{
		stack_t *temp = s;
		s = s->next;
		free(temp);
	}

	return (0);
}
