/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_printers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 01:29:12 by antgalan          #+#    #+#             */
/*   Updated: 2023/01/23 01:52:57 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datalib.h"

void	lst_print(t_list *list)
{
	ft_putstr_fd("[ ", 1);
	while (list)
	{
		ft_putstr_fd(list->data, 1);
		if (list->next)
			ft_putstr_fd(" -> ", 1);
		list = list->next;
	}
	ft_putstr_fd(" ]", 1);
}
