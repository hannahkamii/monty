#include "monty.h"

void f_push(stack_t **stack, unsigned int line_number)
{
	if (line_number == '\0')
	{
		fprintf(stderr, "L<line_number>: usage: push integer\n");
		exit(EXIT_FAILURE);
	}
	stack->n[stack->next] = line_number;
	stack->next++;
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
