vi 9-insert_nodeint.c

#include "lists.h"

/*
 * * insert_nodeint_at_index - inserts a new node in a linked list,
 * * at a given position
 * * @head: pointer to the first node in the list
 * * @idx: index where the new node is added
 * * @n: data to insert in the new node
 * *
 * * Return: pointer to the new node, or NULL
 * */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *new;
	listint_t *temp = *head;

	new = malloc(sizeof(listint_t));
	if (!new || !head)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	for (i = 0; temp && i < idx; i++)
	{
		if (i == idx - 1)
		{
			new->next = temp->next;
			temp->next = new;
			return (new);
		}
		else
			temp = temp->next;
	}

	return (NULL);
}

vi 10-delete_nodeint.c

#include "lists.h"

/*
 * * delete_nodeint_at_index - deletes a node in a linked list at a certain index
 * * @head: pointer to the first element in the list
 * * @index: index of the node to delete
 * *
 * * Return: 1 (Success), or -1 (Fail)
 * */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp = *head;
	listint_t *current = NULL;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	while (i < index - 1)
	{
		if (!temp || !(temp->next))
			return (-1);
		temp = temp->next;
		i++;
	}


	current = temp->next;
	temp->next = current->next;
	free(current);

	return (1);
}
