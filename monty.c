#include "monty.h"

int main(void)
{
	stack_t *s = NULL;

	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	pint(&s, 4);

	pop(&s, 5);

	swap(&s, 6);

	pall(&s, 7);

	add(&s, 8);

	nop(&s, 9);

	sub(&s, 10);

	div_no(&s, 11);

	mul(&s, 12);

	mod(&s, 13);

	pop(&s, 14);

	pall(&s, 15);

	pop(&s, 16);

	pall(&s, 17);

	while (s != NULL)
	{
		stack_t *temp = s;

		s = s->next;

		free(temp);
	}

	return (0);
}
