/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_basics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:44:57 by antgalan          #+#    #+#             */
/*   Updated: 2023/10/18 20:57:31 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datalib.h"
#include <stdlib.h>

t_set	*set_new(void *data)
{
	t_set *new_node;

	new_node = (t_set *)malloc(sizeof(t_set));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;

	return new_node;
}

int set_contains(t_set *set, void *data)
{
	while (set)
	{
		if (set->data == data)
			return (1);
		set = set->next;
	}
	return (0);
}

void	set_add(t_set **set, void *data)
{
	t_set *current;

	if (!set || set_contains(*set, data))
		return;

	if (!*set)
	{
		*set = set_new(data);
		return;
	}

	current = *set;
	while (current->next)
	{
		current = current->next;
	}
	current->next = set_new(data);
}

void	set_remove(t_set **set, void *data)
{
	t_set *current;
	t_set *prev;

	if (!set || !*set)
		return;

	current = *set;
	prev = NULL;

	while (current)
	{
		if (current->data == data)
		{
			if (prev)
				prev->next = current->next;
			else
				*set = current->next;

			free(current);
			return;
		}

		prev = current;
		current = current->next;
	}
}

void	set_clear(t_set **set)
{
	t_set *current;
	t_set *tmp;

	if (!set)
		return;

	current = *set;

	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}

	*set = NULL;
}

