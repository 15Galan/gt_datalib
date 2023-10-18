/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_inter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.malaga.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:30:05 by lpin              #+#    #+#             */
/*   Updated: 2023/10/18 22:31:05 by lpin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datalib.h"

t_set	*set_inter(t_set *set1, t_set *set2)
{
	t_set	*aux;
	t_set	*new;

	new = NULL;
	aux = set1;
	while (aux)
	{
		if (set_contains(set2, aux->data))
			set_add(&new, aux->data);
		aux = aux->next;
	}
	return (new);
}
