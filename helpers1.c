#include "monty.h"

/**
 * exec - exec opcode
 * Return: none
 */
void exec(void)
{
	instruction_t ins[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"queue", _mode},
		{"stack", _mode},
		{NULL, NULL},
	};
	int j = 0;

	for (j = 0; ins[j].opcode; j++)
	{
		if (strcmp(ptr.opcode, ins[j].opcode) == 0)
		{
			ins[j].f(&ptr.top, ptr.line_num);
			break;
		}
	}
	if (!ins[j].opcode)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
				ptr.line_num, ptr.opcode);
		_free(ptr.top);
		exit(EXIT_FAILURE);
	}
}
/**
 * remove_spaces - remove spaces
 * @str: string
 * Return: new string
 */
char *remove_spaces(char *str)
{
	while (*str)
	{
		if (*str == ' ')
			str++;
		else
			break;
	}
	return (str);
}
