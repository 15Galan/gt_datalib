/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   que_basics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delvira- <delvira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:53:46 by antgalan          #+#    #+#             */
/*   Updated: 2023/03/02 19:43:38 by delvira-         ###   ########.fr       */
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
