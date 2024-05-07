/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_basics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:40:27 by antgalan          #+#    #+#             */
/*   Updated: 2024/05/07 20:26:08 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datalib.h"

t_stack	*stk_new(void *data)
{
	t_stack	*new;

	new = NULL;
	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	if (new)
	{
		new->data = data;
		new->next = NULL;
	}
	return (new);
}

void	stk_push(t_stack **stack, void *data)
{
	// TODO
}

t_stack	*stk_pop(t_stack **stack)
{
	// TODO
}

void	stk_clear(t_stack **stack)
{
	// TODO
}
