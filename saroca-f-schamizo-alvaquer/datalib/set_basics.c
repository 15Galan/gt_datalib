/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_basics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:44:57 by antgalan          #+#    #+#             */
/*   Updated: 2024/05/07 20:24:21 by schamizo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datalib.h"

t_set	*set_new(void *data)
{
	t_set	*new;

	new = (t_set *) malloc(sizeof(t_set));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

void	set_add(t_set **set, void *data)
{
	t_set	*new;

	new = set_new(data);
	if (!new || set_contains(*set, data))
		return ;
	while (*set)
		set = &(*set)->next;
	*set = new;
}

void	set_remove(t_set **set, void *data)
{
	// TODO
}

void	set_clear(t_set **set)
{
	// TODO
}
