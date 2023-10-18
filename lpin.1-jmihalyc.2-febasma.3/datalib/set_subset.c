/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_subset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febasma <nicobasma_@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:22:49 by febasma           #+#    #+#             */
/*   Updated: 2023/10/18 22:23:13 by febasma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datalib.h"

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
