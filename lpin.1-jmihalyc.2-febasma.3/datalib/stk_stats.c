/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_stats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:40:27 by antgalan          #+#    #+#             */
/*   Updated: 2023/10/18 21:30:27 by jmihalyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datalib.h"

int	stk_empty(t_stack *stack)
{
	return (stack == NULL);
}

int	stk_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

t_stack	*stk_top(t_stack *stack)
{
	if (stk_empty(stack))
		return (NULL);
	return (stack);
}

void	*stk_peek(t_stack *stack)
{
	if (stk_empty(stack))
		return (NULL);
	return (stack->data);
}
