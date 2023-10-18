/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   que_printers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagarci2 <cagarci2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:53:46 by antgalan          #+#    #+#             */
/*   Updated: 2023/10/18 21:47:41 by cagarci2         ###   ########.fr       */
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
