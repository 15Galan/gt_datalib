/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_maths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:48:46 by antgalan          #+#    #+#             */
/*   Updated: 2024/05/07 21:14:48 by saroca-f         ###   ########.fr       */
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

t_set	*set_inter(t_set *set1, t_set *set2)
{
	// TODO
}

t_set	*set_diff(t_set *set1, t_set *set2)
{
	// TODO
}
