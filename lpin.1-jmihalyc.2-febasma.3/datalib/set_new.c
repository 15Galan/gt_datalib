/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpin <lpin@student.42.malaga.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:34:08 by lpin              #+#    #+#             */
/*   Updated: 2023/10/18 22:34:33 by lpin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datalib.h"

t_set	*set_new(void *data)
{
	t_set	*new;

	new = (t_set *) malloc(sizeof(t_set));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}
