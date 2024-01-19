#include "monty.h"


/**
 * main -  count how many charachter in number
 * @argc: number
 * @argv: number
 * Return: the number lentgh
 */
int main(int argc, char **argv)
{
	char line[100], *token;
	int i = 0;

	ptr.mode = 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	ptr.fd = openfile(argv[1]);
	while (fgets(line, sizeof(line), ptr.fd) != NULL)
	{
		if (strlen(remove_spaces(line)) < 3 || remove_spaces(line)[0] == '#')
		{
			ptr.line_num++;
			continue;
		}
		ptr.line_num++;
		token = strtok(line, " \n");
		for (i = 0; token != NULL && i < 2; i++)
		{
			if (i == 0) /*first part command first loop*/
				ptr.opcode = token;
			if (strcmp(ptr.opcode, "push") != 0) /*if opcode is not push break*/
				break;
			if (i == 1)
				verify_number(token);
			token = strtok(NULL, " \n");
		}
		if (strcmp(ptr.opcode, "push") == 0 && i == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", ptr.line_num);
			_free(ptr.top);
			exit(EXIT_FAILURE);
		}
		exec();
	}
	_free(ptr.top);
	exit(EXIT_SUCCESS);
}
