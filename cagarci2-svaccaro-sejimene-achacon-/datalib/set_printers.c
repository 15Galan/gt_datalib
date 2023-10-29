/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_printers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:51:42 by antgalan          #+#    #+#             */
/*   Updated: 2023/01/20 13:00:52 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datalib.h"

void	set_print(t_set *set)
{
	t_set	*aux;

	aux = set;
	ft_putchar_fd('{', 1);
	while (aux)
	{
		ft_putstr_fd(aux->data, 1);
		if (aux->next)
			ft_putstr_fd(", ", 1);
		aux = aux->next;
	}
	ft_putchar_fd('}', 1);
}
