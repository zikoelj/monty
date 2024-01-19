#include "monty.h"
/**
 * _mode -  a switch function
 * @top: head of double list
 * @line_number: line number of opcode
 * 
 */
void _mode(stack_t **top, unsigned int line_number)
{
	(void)top;
	(void)line_number;

	if (strcmp(ptr.opcode, "queue") == 0)
		ptr.mode = 1;
	else if (strcmp(ptr.opcode, "stack") == 0)
		ptr.mode = 0;
}

/**
 * _push -  a function that adds a new node at the top
 * @top: head of double list
 * @line_number: line number of opcode
 * 
 */
void _push(stack_t **top, unsigned int line_number)
{
	stack_t *new, *last;
	int i = 0;

	(void)line_number;
	if (!top)
		return;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed");
		_free(ptr.top);
		exit(EXIT_FAILURE);
	}
	new->n = ptr.push_value;
	if (ptr.mode == 0 || !*top)
	{
		if (*top)
		{
			new->next = *top;
			(*top)->prev = new;
		}
		else
			new->next = NULL;
		new->prev = NULL;
		*top = new;
	}
	else if (ptr.mode == 1)
	{
		last = *top;
		for (i = 0; last; i++)
		{
			if (!last->next)
				break;
			last = last->next;
		}
		last->next = new;
		new->prev = last;
		new->next = NULL;
	}
}

/**
 * _pall -  prints all the elements of a dlistint_t list
 * @top: head of double list
 * @line_number: line number of opcode
 * Return: none
 */
void _pall(stack_t **top, unsigned int line_number)
{
	stack_t *current = *top;
	int i;

	(void)line_number;
	for (i = 0; current; i++)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
	fflush(stdout);
}

/**
 * _pint -  prints the value at the top of the stack
 * @top: head of double list
 * @line_number: line number of opcode
 * Return: none
 */
void _pint(stack_t **top, unsigned int line_number)
{
	if (!*top)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		_free(ptr.top);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*top)->n);
	fflush(stdout);
}

/**
 * _pop - removes the top element of the stack
 * @top: head of double list
 * @line_number: line number of opcode
 * Return: none
 */
void _pop(stack_t **top, unsigned int line_number)
{

	if (!*top)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		_free(ptr.top);
		exit(EXIT_FAILURE);
	}
	if ((*top)->next == NULL)
	{
		free(*top);
		*top = NULL;
	}
	else
	{
		*top = (*top)->next;
		free((*top)->prev);
		(*top)->prev = NULL;
	}
}
