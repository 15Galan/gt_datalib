/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_creators.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:53:46 by antgalan          #+#    #+#             */
/*   Updated: 2023/03/02 19:43:23 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datalib.h"

/**
 * @brief   Creates a new node with the given data.
 *
 * @param data  Pointer to the data to be stored in the node.
 *
 * @return  Pointer to the new node.
 */
t_dlist	*dll_new(void *data)
{
	t_dlist	*new;

	new = (t_dlist *) malloc(sizeof(t_dlist));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

/**
 * @brief   Adds a new node at the beginning of the list.
 *
 * @param list	Pointer to the first element of the list.
 * @param elem	Pointer to the new node to be added.
 */
void	dll_add_first(t_dlist **list, t_dlist *elem)
{
	if (dll_empty(*list))
		*list = elem;
	else
	{
		elem->next = *list;
		(*list)->prev = elem;
		*list = elem;
	}
}

/**
 * @brief   Adds a new node after the given node.
 *
 * @param list	Pointer to the first element of the list.
 * @param data  Pointer to the data to be stored in the node.
 */
void	dll_add_after(t_dlist *elem, t_dlist *new)
{
	if (dll_empty(elem) || dll_empty(new))
		return ;
	new->next = elem->next;
	new->prev = elem;
	if (elem->next)
		elem->next->prev = new;
	elem->next = new;
}

/**
 * @brief   Adds a new node at the end of the list.
 *
 * @param list	Pointer to the first element of the list.
 * @param elem	Pointer to the new node to be added.
 */
void	dll_add_last(t_dlist **list, t_dlist *elem)
{
	t_dlist	*last;

	if (dll_empty(*list))
		*list = elem;
	else
	{
		last = dll_last(*list);
		last->next = elem;
		elem->prev = last;
	}
}

/**
 * @brief   Replace the data of the given node.
 *
 * @param elem	Pointer to the node to be modified.
 * @param data  The new data.
 *
 * @return  Pointer to the modified node;
 * 			NULL otherwise.
 */
t_dlist	*dll_replace(t_dlist *elem, void *data)
{
	t_dlist	*new;

	new = dll_new(data);
	if (!new)
		return (NULL);
	if (elem->prev)
		elem->prev->next = new;
	if (elem->next)
		elem->next->prev = new;
	new->prev = elem->prev;
	new->next = elem->next;
	free(elem);
	return (new);
}
