/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:20:09 by antgalan          #+#    #+#             */
/*   Updated: 2023/10/18 21:00:31 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datalib.h"

// Verifica si el conjunto está vacío.
int	set_empty(t_set *set)
{
	return (set == NULL);
}

// Verifica si un conjunto contiene un elemento específico.
int	set_contains(t_set *set, void *data)
{
	while (set)
	{
		if (set->data == data)
			return 1;
		set = set->next;
	}
	return 0;
}

// Verifica si set1 es un subconjunto de set2.
int	set_subset(t_set *set1, t_set *set2)
{
	t_set *current = set1;

	while (current)
	{
		if (!set_contains(set2, current->data))
			return 0;
		current = current->next;
	}
	return 1;
}

// Verifica si dos conjuntos son iguales.
int	set_equal(t_set *set1, t_set *set2)
{
	// Ambos conjuntos deben ser subconjuntos mutuos para ser iguales.
	return set_subset(set1, set2) && set_subset(set2, set1);
}

// Retorna el tamaño del conjunto.
int	set_size(t_set *set)
{
	int count = 0;
	while (set)
	{
		count++;
		set = set->next;
	}
	return count;
}
