#include "monty.h"
/**
 * push_ - pushes an element to the stack
 * @head: The linked list
 * @n: Line number
 */

void push_(stack_t **head, unsigned int n)
{
	int i, arg;

	if (!globals.argument)
	{
		fprintf(stderr, "L%u: usage: push integer\n", n);
		_free();
		exit(EXIT_FAILURE);
	}
	for (i = 0; globals.argument[i] != '\0'; i++)
	{
		if (!isdigit(globals.argument[i]) && globals.argument[i] != '-')
		{
			fprintf(stderr, "L%u: usage: push integer\n", n);
			_free();
			exit(EXIT_FAILURE);
		}
	}
	arg = atoi(globals.argument);

	if (globals.stack == 1)
		adddnode_int(head, arg);
	else
		adddnode_int_end(head, arg);
}

/**
 * pull - displays all elements of stack
 * @head: The stack to be displayed
 * @n: Line number
 */
void pull(stack_t **head, unsigned int n)
{
	stack_t *cp;

	(void)n;

	cp = *head;

	while (cp != NULL)
	{
		fprintf(stdout, "%d\n", cp->n);
		cp = cp->next;
	}
}

/**
 * get_line - returns number of bytes read
 * @lineptr: Line read
 * @n: Size of line
 * @stream: Where the input is
 *
 * Return: Number of bytes read
 */
ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t bytesRead = 0;
	size_t bufferSize = 0;
	char *newBuffer;
	int c;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	if (*lineptr == NULL || *n == 0)
	{
		bufferSize = 128;
		*lineptr = (char *)malloc(bufferSize);
		if (*lineptr == NULL)
			return (-1);
		*n = bufferSize;
	}
	while (1)
	{
		c = fgetc(stream);
		if (c == EOF || c == '\n')
			break;
		if (bytesRead >= (ssize_t)(*n) - 1)
		{
			bufferSize *= 2;
			newBuffer = (char *)realloc(*lineptr, bufferSize);
			if (newBuffer == NULL)
			{
				free(*lineptr);
				*lineptr = NULL;
				return (-1);
			}
			*lineptr = newBuffer;
			*n = bufferSize;
		}
		(*lineptr)[bytesRead] = (char)c;
		bytesRead++;
	}
	if (bytesRead == 0 && c == EOF)
		return (-1);
	(*lineptr)[bytesRead] = '\0';
	return (bytesRead);
}

/**
 * prints - prints the value at the top of the stack
 *
 * @head: Pointer to the linked list
 * @n: Line number
 */
void prints(stack_t **head, unsigned int n)
{
	(void)n;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", n);
		_free();
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%d\n", (*head)->n);
}
