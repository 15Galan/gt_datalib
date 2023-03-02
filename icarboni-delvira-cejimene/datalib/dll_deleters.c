/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_deleters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:53:46 by antgalan          #+#    #+#             */
/*   Updated: 2023/03/02 19:49:00 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datalib.h"

/**
 * @brief   Removes the first node of the list.
 *
 * @param list	Pointer to the first element of the list.
 */
void	dll_remove_first(t_dlist **list)
{
	t_dlist	*aux;

	if (dll_empty(*list))
		return ;
	aux = *list;
	*list = (*list)->next;
	if (*list)
		(*list)->prev = NULL;
	free(aux);
}

/**
 * @brief   Removes the given node from the list.
 *
 * @param list	Pointer to the first element of the list.
 * @param elem	Pointer to the element to be removed.
 */
void	dll_remove(t_dlist **list, t_dlist *elem)
{
	if (dll_empty(*list))
		return ;
	if (elem->prev)
		elem->prev->next = elem->next;
	else
		*list = elem->next;
	if (elem->next)
		elem->next->prev = elem->prev;
	free(elem);
}

/**
 * @brief   Removes the last node of the list.
 *
 * @param list	Pointer to the first element of the list.
 */
void	dll_remove_last(t_dlist **list)
{
	t_dlist	*aux;

	if (dll_empty(*list))
		return ;
	aux = *list;
	while (aux->next)
		aux = aux->next;
	if (aux->prev)
		aux->prev->next = NULL;
	else
		*list = NULL;
	free(aux);
}

/**
 * @brief	Removes all the nodes with the given data.
 *
 * @param list	Pointer to the first element of the list.
 * @param data	Pointer to the data to be removed.
 */
void	dll_purge(t_dlist **list, void *data)
{
	t_dlist	*aux;

	if (dll_empty(*list))
		return ;
	aux = *list;
	while (aux)
	{
		if (aux->data == data)
			dll_remove(list, aux);
		aux = aux->next;
	}
}

/**
 * @brief   Removes all the nodes of the list.
 *
 * @param list	Pointer to the first element of the list.
 */
void	dll_clear(t_dlist **list)
{
	t_dlist	*aux;

	if (dll_empty(*list))
		return ;
	while (*list)
	{
		aux = *list;
		*list = (*list)->next;
		free(aux);
	}
}
