/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_maths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:48:46 by antgalan          #+#    #+#             */
/*   Updated: 2023/01/22 12:35:28 by antgalan         ###   ########.fr       */
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

t_set	*set_diff(t_set *set1, t_set *set2)
{
	t_set	*aux;
	t_set	*new;

	new = NULL;
	aux = set1;
	while (aux)
	{
		if (!set_contains(set2, aux->data))
			set_add(&new, aux->data);
		aux = aux->next;
	}
	return (new);
}
