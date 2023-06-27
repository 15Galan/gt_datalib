/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   que_basics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruzzi <mbruzzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:53:46 by antgalan          #+#    #+#             */
/*   Updated: 2023/06/27 13:54:57 by mbruzzi          ###   ########.fr       */
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
	t_queue	*new;

	new = que_new(data);
	if (!new)
		return ;
	if (que_empty(*queue))
	{
		*queue = new;
		return ;
	}
	que_last(*queue)->next = new;
}

void	*que_dequeue(t_queue **queue)
{
	t_queue	*aux;
	void	*data;

	if (que_empty(*queue))
		return (NULL);
	aux = *queue;
	*queue = (*queue)->next;
	data = aux->data;
	free(aux);
	return (data);
}

void	que_clear(t_queue **queue)
{
	while (!que_empty(*queue))
		que_dequeue(queue);
}
