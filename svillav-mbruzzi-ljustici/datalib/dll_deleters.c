/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_deleters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljustici <ljustici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:53:46 by antgalan          #+#    #+#             */
/*   Updated: 2023/06/27 14:14:18 by ljustici         ###   ########.fr       */
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
	// TODO
}

void	dll_remove_last(t_dlist **list)
{
	// TODO
}

void	dll_purge(t_dlist **list, void *data)
{
	// TODO
}

void	dll_clear(t_dlist **list)
{
	// TODO
}
