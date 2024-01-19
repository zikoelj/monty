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
	int i = 0;

	for (i = 0; ins[i].opcode; i++)
	{
		if (strcmp(ptr.opcode, ins[i].opcode) == 0)
		{
			ins[i].f(&ptr.top, ptr.line_num);
			break;
		}
	}
	if (!ins[i].opcode)
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
