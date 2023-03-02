/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_stats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvgomez <alvgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:40:27 by antgalan          #+#    #+#             */
/*   Updated: 2023/03/02 19:32:15 by alvgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datalib.h"

/**
 * @brief	Checks if the stack is empty.
 *
 * @param stack	Pointer to the stack.
 *
 * @return	1 if the stack is empty;
 * 			0 otherwise.
 */
int	stk_empty(t_stack *stack)
{
	return (stack == NULL);
}

/**
 * @brief	Counts the number of elements in the stack.
 *
 * @param stack	Pointer to the stack.
 *
 * @return	Number of elements in the stack.
 */
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

/**
 * @brief	Checks the top element of the stack.
 *
 * @param stack	Pointer to the stack.
 *
 * @return 	Pointer to the top element;
 * 			NULL if the stack is empty.
 */
t_stack	*stk_top(t_stack *stack)
{
	if (stk_empty(stack))
		return (NULL);
	return (stack);
}

/**
 * @brief	Checks the top element data of the stack.
 *
 * @param stack	Pointer to the stack.
 *
 * @return	Pointer to the top element data;
 * 			NULL if the stack is empty.
 */
void	*stk_peek(t_stack *stack)
{
	if (stk_empty(stack))
		return (NULL);
	return (stack->data);
}
