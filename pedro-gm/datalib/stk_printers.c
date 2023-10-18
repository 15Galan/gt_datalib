/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_printers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:40:27 by antgalan          #+#    #+#             */
/*   Updated: 2023/01/23 02:16:33 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datalib.h"

void	stk_print(t_stack *stack)
{
	ft_putstr_fd("| ", 1);
	while (stack)
	{
		ft_putstr_fd(stack->data, 1);
		if (stack->next)
			ft_putstr_fd(" | ", 1);
		stack = stack->next;
	}
	ft_putstr_fd(" |", 1);
}
