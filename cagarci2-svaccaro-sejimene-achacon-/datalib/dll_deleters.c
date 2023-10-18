/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_deleters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagarci2 <cagarci2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:53:46 by antgalan          #+#    #+#             */
/*   Updated: 2023/10/18 21:23:57 by cagarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datalib.h"

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
