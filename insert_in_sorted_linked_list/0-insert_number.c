#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: double pointer to the head of the list
 * @number: number to be inserted
 *
 * Return: address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node;
	listint_t *current;

	if (head == NULL)
		return (NULL);

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = number;
	new_node->next = NULL;

	/* If the list is empty or number should be inserted at the beginning */
	if (*head == NULL || (*head)->n > number)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	/* Traverse the list to find the correct insertion point */
	current = *head;
	while (current->next != NULL && current->next->n < number)
	{
		current = current->next;
	}

	/* Insert the new node */
	new_node->next = current->next;
	current->next = new_node;

	return (new_node);
}
