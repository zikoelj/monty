#include "monty.h"

/**
 * _div - divides the second top element of
 * the stack by the top element of the stack.
 * @top: head of double list
 * @line_number: line number of opcode
 * Return: none
 */
void _div(stack_t **top, unsigned int line_number)
{
	int value = 0;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		_free(ptr.top);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		_free(ptr.top);
		exit(EXIT_FAILURE);
	}
	value = (*top)->n;
	_pop(&ptr.top, ptr.line_num);
	(*top)->n /= value;
}

/**
 * _mul - multiplies the second top element
 * of the stack with the top element of the stack.
 * @top: head of double list
 * @line_number: line number of opcode
 * Return: none
 */
void _mul(stack_t **top, unsigned int line_number)
{
	int value = 0;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		_free(ptr.top);
		exit(EXIT_FAILURE);
	}
	value = (*top)->n;
	_pop(&ptr.top, ptr.line_num);
	(*top)->n *= value;
}

/**
 * _mod - computes the rest of the division of the second
 *  top element of the stack by the top element of the stack.
 * @top: head of double list
 * @line_number: line number of opcode
 * Return: none
 */
void _mod(stack_t **top, unsigned int line_number)
{
	int value = 0;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		_free(ptr.top);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		_free(ptr.top);
		exit(EXIT_FAILURE);
	}
	value = (*top)->n;
	_pop(&ptr.top, ptr.line_num);
	(*top)->n %= value;
}

/**
 * _pchar - prints the char at the top of the stack (ascii).
 * @top: head of double list
 * @line_number: line number of opcode
 * Return: none
 */
void _pchar(stack_t **top, unsigned int line_number)
{
	if (!*top)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		_free(ptr.top);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n > 127 || (*top)->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		_free(ptr.top);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*top)->n);
}

/**
 * _pstr - prints the string starting at the top of the stack.
 * @top: head of double list
 * @line_number: line number of opcode
 * Return: none
 */
void _pstr(stack_t **top, unsigned int line_number)
{
	stack_t *current = *top;
	int i;
	(void)line_number;

	for (i = 0; current && current->n != 0 &&
				!(current->n > 127 || current->n < 0);
		 i++)
	{
		fprintf(stdout, "%c", current->n);
		current = current->next;
	}
	fprintf(stdout, "\n");
}
