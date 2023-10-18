/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_equal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febasma <nicobasma_@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:21:10 by febasma           #+#    #+#             */
/*   Updated: 2023/10/18 22:21:37 by febasma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datalib.h"

int	set_equal(t_set *set1, t_set *set2)
{
	if (set_size(set1) != set_size(set2))
		return (0);
	return (set_subset(set1, set2));
}
