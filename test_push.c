#include "monty.h"

/**
 * push - push elements into the stack
 * @s: head pointer
 * @line_number: line number
 * Return: 0
 */
#define length 100

void push(stack_t **s, unsigned int line_number)
{
	int n;
	char line[length];
	stack_t *nw_nd;

	if (fgets(line, length, stdin) == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}

	n = atoi(line);

	nw_nd = malloc(sizeof(stack_t));
	nw_nd->n = n;
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
 * @s: head node
 * @line_number: line number
 * Return: 0
 */

void pall(stack_t **s, unsigned int line_number)
{
	stack_t *cnt;
	(void)line_number;

	while (cnt != NULL)
	{
		cnt = *s;
		printf("%d\n", cnt->n);
		cnt = cnt->next;
	}
}
/**
 * main - main
 * @argc: argument count
 * @argv: argumnt vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	stack_t *s = NULL;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	unsigned int line_number = 1;
	char line[length];
	(void)argc;
	(void)argv;

	while (fgets(line, length, stdin) != NULL)
	{
		char *opcode = strtok(line, " \n");
		int i;

		for (i = 0; instructions[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(&s, line_number);
				break;
			}
		}
		line_number++;
	}
	return (0);
}
