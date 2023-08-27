#include "monty.h"

void push(stack_t **s, int value)
{
	stack_t *nw_nd = malloc(sizeof(stack_t))
	if (value == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", value);
		exit(EXIT_FAILURE);
	}
	s->n[s->next] = value;
	s->next++;
}
int pop(stack_t **stack)
{
	if (stack->next == 0)
	{
		printf("L<line_number>: can't pint, stack empty\n", __LINE__);
		exit(EXIT_FAILURE);
	}
	unsigned int line_number = stack->n[stack->next - 1];

	stack->next--;

	return (line_number);
}
void f_pint(stack_t **stack)
{
	printf("%d\n", pop(stack));
}
int main(void)
{
	stack_t stack;

	stack.next = 0;

	stack.n = NULL;

	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);

	pint(&stack);
	pint(&stack);
	pint(&stack);

	free(stack.n);

	return (0);
}
