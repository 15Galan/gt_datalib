/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_maths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:48:46 by antgalan          #+#    #+#             */
/*   Updated: 2023/10/18 21:00:41 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datalib.h"
#include <stdlib.h>

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

t_set	*set_union(t_set *set1, t_set *set2)
{
	t_set *result = NULL;
	t_set *current;

	// Añadir todos los elementos de set1 al resultado.
	current = set1;
	while (current)
	{
		set_add(&result, current->data);
		current = current->next;
	}

	// Añadir elementos de set2 que no están ya en el resultado.
	current = set2;
	while (current)
	{
		if (!set_contains(result, current->data))
		{
			set_add(&result, current->data);
		}
		current = current->next;
	}

	return result;
}

t_set	*set_inter(t_set *set1, t_set *set2)
{
	t_set *result = NULL;
	t_set *current;

	current = set1;
	while (current)
	{
		if (set_contains(set2, current->data))
		{
			set_add(&result, current->data);
		}
		current = current->next;
	}

	return result;
}

t_set	*set_diff(t_set *set1, t_set *set2)
{
	t_set *result = NULL;
	t_set *current;

	current = set1;
	while (current)
	{
		if (!set_contains(set2, current->data))
		{
			set_add(&result, current->data);
		}
		current = current->next;
	}

	return result;
}
