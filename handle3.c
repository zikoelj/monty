#include "monty.h"

/**
 * _rotl -  rotates the stack to the top.
 * @top: head of double list
 * @line_number: line number of opcode
 * Return: none
 */
void _rotl(stack_t **top, unsigned int line_number)
{
	stack_t *last = *top;
	int i;

	if (!*top)
		return;
	(void)line_number;
	for (i = 0; last; i++)
	{
		if (!last->next)
			break;
		last = last->next;
	}
	last->next = *top;
	(*top)->prev = last;
	(*top) = (*top)->next;
	(*top)->prev->next = NULL;
	(*top)->prev = NULL;
}

/**
 * _rotr - rotates the stack to the bottom.
 * @top: head of double list
 * @line_number: line number of opcode
 * Return: none
 */
void _rotr(stack_t **top, unsigned int line_number)
{
	stack_t *last = *top;
	int i;

	if (!*top || (*top)->next == NULL)
		return;
	(void)line_number;
	for (i = 0; last; i++)
	{
		if (!last->next)
			break;
		last = last->next;
	}
	last->next = *top;
	last->prev->next = NULL;
	(*top)->prev = last;
	(*top) = last;
	last->prev = NULL;
}
