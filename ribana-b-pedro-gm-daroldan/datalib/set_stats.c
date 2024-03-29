/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:20:09 by antgalan          #+#    #+#             */
/*   Updated: 2023/10/20 02:44:50 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datalib.h"

int	set_empty(t_set *set)
{
	return (set == NULL);
}

int	set_contains(t_set *set, void *data)
{
	while (set)
	{
		if (set->data == data)
			return (1);
		set = set->next;
	}
	return (0);
}

int	set_subset(t_set *set1, t_set *set2)
{
	while (set1)
	{
		if (!set_contains(set2, set1->data))
			return (0);
		set1 = set1->next;
	}
	return (1);
}

int	set_equal(t_set *set1, t_set *set2)
{
	if (set_size(set1) != set_size(set2))
		return (0);
	return (set_subset(set1, set2));
}

int	set_size(t_set *set)
{
	int	i;

	i = 0;
	while (set)
	{
		i++;
		set = set->next;
	}
	return (i);
}
