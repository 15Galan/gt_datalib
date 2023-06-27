/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   que_basics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:53:46 by antgalan          #+#    #+#             */
/*   Updated: 2023/06/27 13:49:03 by mbruzzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datalib.h"

t_queue	*que_new(void *data)
{
	t_queue	*new;

	new = (t_queue *) malloc(sizeof(t_queue));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

void	que_enqueue(t_queue **queue, void *data)
{
	/// TODO
}

void	*que_dequeue(t_queue **queue)
{
	// TODO
}

void	que_clear(t_queue **queue)
{
	// TODO
}
