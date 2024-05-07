/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:20:09 by antgalan          #+#    #+#             */
/*   Updated: 2024/05/07 21:14:52 by schamizo         ###   ########.fr       */
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
	// TODO
}

int	set_size(t_set *set)
{
	// TODO
}
