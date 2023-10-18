/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_creators.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconde-a <jconde-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:53:46 by antgalan          #+#    #+#             */
/*   Updated: 2023/10/18 21:02:54 by jconde-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datalib.h"

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
