#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack.
 * @top: head of double list
 * @line_number: line number of opcode
 * Return: none
 */
void _swap(stack_t **top, unsigned int line_number)
{
	stack_t *tmp1;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		_free(ptr.top);
		exit(EXIT_FAILURE);
	}
	tmp1 = *top;
	tmp1->prev = tmp1->next;
	if ((*top)->next->next == NULL)
		tmp1->next = NULL;
	else
	{
		tmp1->next = tmp1->next->next;
		tmp1->next->prev = *top;
	}
	*top = tmp1->prev;
	(*top)->prev = NULL;
	(*top)->next = tmp1;
}

/**
 * _add - adds the top two elements of the stack.
 * @top: head of double list
 * @line_number: line number of opcode
 * Return: none
 */
void _add(stack_t **top, unsigned int line_number)
{
	int value = 0;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		_free(ptr.top);
		exit(EXIT_FAILURE);
	}
	value = (*top)->n;
	_pop(&ptr.top, ptr.line_num);
	(*top)->n += value;
}

/**
 * _nop - doesn’t do anything.
 * @top: head of double list
 * @line_number: line number of opcode
 * Return: none
 */
void _nop(stack_t **top, unsigned int line_number)
{
	(void)top;
	(void)line_number;
}

/**
 * _sub - subtracts the top element of the stack
 *  from the second top element of the stack.
 * @top: head of double list
 * @line_number: line number of opcode
 *
 */
void _sub(stack_t **top, unsigned int line_number)
{
	int value = 0;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		_free(ptr.top);
		exit(EXIT_FAILURE);
	}
	value = (*top)->n;
	_pop(&ptr.top, ptr.line_num);
	(*top)->n -= value;
}
