#include "monty.h"

/**
 * open_file - opens a file
 * @fl_nm: the file namepath
 * Return: void
 */

void open_file(char *fl_nm)
{
	FILE *fdir = fopen(fl_nm, "r");

	if (fl_nm == NULL || fdir == NULL)
		err(2, fl_nm);

	read_file(fdir);
	fclose(fdir);
}


/**
 * read_file - reads a file
 * @fdir: pointer to file descriptor
 * Return: void
 */

void read_file(FILE *fdir)
{
	int ln_number, frm = 0;
	char *buf = NULL;
	size_t length = 0;

	for (ln_number = 1; getline(&buf, &length, fdir) != -1; ln_number++)
	{
		frm = parse_line(buf, ln_number, frm);
	}
	free(buf);
}


/**
 * parse_line - Separates each line into tokens to determine
 * which function to call
 * @buf: line from the file
 * @ln_number: line number
 * @frm:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parse_line(char *buf, int ln_number, int frm)
{
	char *opcode, *val;
	const char *delim = "\n ";

	if (buf == NULL)
		err(4);

	opcode = strtok(buf, delim);
	if (opcode == NULL)
		return (frm);
	val = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_func(opcode, val, ln_number, frm);
	return (frm);
}

/**
 * find_func - find the appropriate function for the opcode
 * @opcode: opcode
 * @val: argument of opcode
 * @frm:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_func(char *opcode, char *val, int ln, int frm)
{
	int k;
	int f;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (f = 1, k = 0; func_list[k].opcode != NULL; k++)
	{
		if (strcmp(opcode, func_list[k].opcode) == 0)
		{
			call_fun(func_list[k].f, opcode, val, ln, frm);
			f = 0;
		}
	}
	if (f == 1)
		err(3, ln, opcode);
}


/**
 * call_fun - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @frm: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_fun(op_func func, char *op, char *val, int ln, int frm)
{
	stack_t *node;
	int f;
	int i;

	f = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			f = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * f);
		if (frm == 0)
			func(&node, ln);
		if (frm == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
