/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_creators.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:53:46 by antgalan          #+#    #+#             */
/*   Updated: 2024/05/07 21:33:33 by alvaquer         ###   ########.fr       */
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
	// TODO
}

void	dll_add_after(t_dlist *elem, t_dlist *new)
{
	// TODO
}

void	dll_add_last(t_dlist **list, t_dlist *elem)
{
	// TODO
}

t_dlist	*dll_replace(t_dlist *elem, void *data)
{
	// TODO
}
