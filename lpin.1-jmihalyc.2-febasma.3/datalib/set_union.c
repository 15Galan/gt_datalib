/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_union.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.malaga.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:32:27 by lpin              #+#    #+#             */
/*   Updated: 2023/10/18 22:32:58 by lpin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datalib.h"

t_set	*set_union(t_set *set1, t_set *set2)
{
	t_set	*aux;
	t_set	*new;

	new = NULL;
	aux = set1;
	while (aux)
	{
		set_add(&new, aux->data);
		aux = aux->next;
	}
	aux = set2;
	while (aux)
	{
		set_add(&new, aux->data);
		aux = aux->next;
	}
	return (new);
}
