#include "lists.h"

/**
 * reverse_list - reverses a linked list
 * @head: pointer to the head of the list
 *
 * Return: pointer to the new head
 */
listint_t *reverse_list(listint_t *head)
{
	listint_t *prev = NULL;
	listint_t *next = NULL;

	while (head)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}

	return (prev);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to the head of the list
 *
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow = *head, *fast = *head;
	listint_t *first_half, *second_half;

	if (!head || !*head || !(*head)->next)
		return (1);

	while (fast && fast->next)
	{
		fast = fast->next->next;
		if (fast)
			slow = slow->next;
	}

	second_half = reverse_list(slow->next);
	first_half = *head;

	while (second_half)
	{
		if (first_half->n != second_half->n)
		{
			reverse_list(slow->next);
			return (0);
		}
		first_half = first_half->next;
		second_half = second_half->next;
	}

	reverse_list(slow->next);
	return (1);
}
