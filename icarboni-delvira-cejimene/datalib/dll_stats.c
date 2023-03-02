/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_stats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:53:46 by antgalan          #+#    #+#             */
/*   Updated: 2023/03/02 19:49:43 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datalib.h"

/**
 * @brief	Checks if the list is empty.
 * @param list	Pointer to the first element of the list.
 *
 * @return	1 if the list is empty;
 * 			0 otherwise.
 */
int	dll_empty(t_dlist *list)
{
	return (list == NULL);
}

/**
 * @brief   Counts the number of nodes in the list.
 *
 * @param list   Pointer to the first element of the list.
 *
 * @return  Number of nodes in the list.
 */
int	dll_size(t_dlist *list)
{
	int	i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

/**
 * @brief   Returns the first node of the list.
 *
 * @param list	Pointer to an element of the list.
 *
 * @return	Pointer to the first node of the list.
 */
t_dlist	*dll_first(t_dlist *list)
{
	while (list && list->prev)
		list = list->prev;
	return (list);
}

/**
 * @brief   Returns the last node of the list.
 *
 * @param list	Pointer to an element of the list.
 *
 * @return	Pointer to the last node of the list.
 */
t_dlist	*dll_last(t_dlist *list)
{
	while (list && list->next)
		list = list->next;
	return (list);
}

/**
 * @brief	Searches an element in the list.
 *
 * @param list	Pointer to the first element of the list.
 * @param data	The data to search.
 *
 * @return	Pointer to the node containing the data;
 * 			NULL if the data is not found.
 */
t_dlist	*dll_search(t_dlist *list, void *data)
{
	while (list)
	{
		if (list->data == data)
			return (list);
		list = list->next;
	}
	return (NULL);
}