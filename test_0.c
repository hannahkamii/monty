#include "monty.h"

int main(int argc, char *argv[])
{
	char *str = "push 1\npush 2";
	char *tok;
	char *cpy;
	(void)argc;
	(void)argv;

	cpy = malloc(sizeof(char) * strlen(str) + 1);
	strcpy(cpy, str);

	tok = strtok(cpy, " ");
	while (tok)
	{
		printf("opcode: %s\n", tok);
		tok = strtok(NULL, " ");
	}

	return (0);
}
