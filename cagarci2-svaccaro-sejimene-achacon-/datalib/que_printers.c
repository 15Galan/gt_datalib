/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   que_printers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:53:46 by antgalan          #+#    #+#             */
/*   Updated: 2023/01/22 12:49:57 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datalib.h"

void	que_print(t_queue *queue)
{
	t_queue	*aux;

	aux = queue;
	ft_putstr_fd("( ", 1);
	while (aux)
	{
		ft_putstr_fd(aux->data, 1);
		if (aux->next)
			ft_putstr_fd(" >> ", 1);
		aux = aux->next;
	}
	ft_putstr_fd(" )", 1);
}
