/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmihalyc <jmihalyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:36:44 by jmihalyc          #+#    #+#             */
/*   Updated: 2023/10/18 22:37:58 by jmihalyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datalib.h"

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
