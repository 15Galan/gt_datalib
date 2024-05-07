/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dell_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonmart <leonmart@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:48:34 by leonmart          #+#    #+#             */
/*   Updated: 2024/05/07 21:48:39 by leonmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


t_dlist *dll_new(void *data)
{
t_dlist *new;

new = (t_dlist *) malloc(sizeof(t_dlist));
if (!new)
	return (NULL);
new->data = data;
new->next = NULL;
new->prev = NULL;
return (new);
}
