/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmihalyc <jmihalyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:47:46 by jmihalyc          #+#    #+#             */
/*   Updated: 2023/10/18 22:48:21 by jmihalyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datalib.h"

void	set_remove(t_set **set, void *data)
{
	t_set	*aux;
	t_set	*prev;

	if (!set_contains(*set, data))
		return ;
	aux = *set;
	prev = NULL;
	while (aux)
	{
		if (aux->data == data)
		{
			if (prev)
				prev->next = aux->next;
			else
				*set = aux->next;
			free(aux);
			return ;
		}
		prev = aux;
		aux = aux->next;
	}
}
