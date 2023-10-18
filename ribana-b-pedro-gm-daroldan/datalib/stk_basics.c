/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_basics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daroldan < daroldan@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:40:27 by antgalan          #+#    #+#             */
/*   Updated: 2023/10/18 20:30:08 by daroldan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datalib.h"

t_stack	*stk_new(void *data)
{
	t_stack	*new;

	new = (t_stack *) malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

void	stk_push(t_stack **stack, void *data)
{
	t_stack	*new;

	new = stk_new(data);
	if (new == NULL)
		return ;
	new->next = *stack;
	*stack = new;
}

t_stack	*stk_pop(t_stack **stack)
{
	t_stack	*aux;

	if (*stack == NULL)
		return (NULL);
	aux = *stack;
	*stack = (*stack)->next;
	aux->next = NULL;
	return (aux);
}

void	stk_clear(t_stack **stack)
{
	t_stack	*aux;

	while (*stack != NULL)
	{
		aux = *stack;
		*stack = (*stack)->next;
		free(aux);
	}
}
