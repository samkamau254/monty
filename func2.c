#include "monty.h"

/**
 * pops - removes the top element of the stack
 *
 * @head: Pointer to the start of the list
 * @n: The line number
 * Return: no return
 */
void pops(stack_t **head, unsigned int n)
{
	stack_t *temp;

	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", n);
		free();
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = (*head)->next;
	free(temp);
}

/**
 * swaps - swaps the top two elements of the stack
 * @head: Pointer to the head
 * @n: The line number
 */
void swaps(stack_t **head, unsigned int n)
{
	int i = 0;
	stack_t *temp = NULL;

	temp = *head;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}

	if (i < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", n);
		free();
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = (*head)->next;
	temp->next = (*head)->next;
	temp->prev = *head;
	(*head)->next = temp;
	(*head)->prev = NULL;
}

/**
 * adds - adds the top two elements of the stack
 * @head: Pointer to the head
 * @n: line number;
 */
void adds(stack_t **head, unsigned int n)
{
	stack_t *temp = NULL;
	int i = 0;

	temp = *head;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}

	if (i < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", n);
		free();
		exit(EXIT_FAILURE);
	}

	temp = (*head)->next;
	temp->n += (*head)->n;
	pops(head, n);
}

/**
 * no - doesn't do anything
 * @head: Pointer to the head
 * @n: line number;
 */
void no(stack_t **head, unsigned int n)
{
	(void)head;
	(void)n;
}

/**
 * subtr - subtracts the top element of the stack from the second
 * top element of the stack
 * @head: Pointer to the head
 * @n: The line number;
 */
void subtr(stack_t **head, unsigned int n)
{
	stack_t *temp = NULL;
	int i = 0;

	temp = *head;

	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", n);
		free();
		exit(EXIT_FAILURE);
	}

	temp = (*head)->next;
	temp->n -= (*head)->n;
	pops(head, n);
}
