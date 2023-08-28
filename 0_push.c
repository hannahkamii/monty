#include "monty.h"

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
int main(void)
{
	stack_t *s = NULL;

	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	pall(&s, 4);

	while (s != NULL)
	{
		stack_t *temp = s;

		s = s->next;

		free(temp);
	}

	return (0);
}
