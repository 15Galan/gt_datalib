/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:32:56 by antgalan          #+#    #+#             */
/*   Updated: 2023/01/22 17:59:45 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../datalib/datalib.h"

void	status(char *msg, t_list *lst, unsigned int spc)
{
	unsigned int	i;

	i = 0;
	ft_putstr_fd(msg, 1);
	ft_putstr_fd("\t`", 1);
	lst_print(lst);
	ft_putstr_fd("`\n", 1);
	while (i++ < spc)
		ft_putchar_fd('\n', 1);
}

void	test_addition(t_list **list)
{
	t_list	*tmp;

	status("**Sea la lista:**", *list, 1);
	lst_add_first(list, lst_new("antgalan"));
	status("Se añade 'antgalan' al principio:", *list, 0);
	lst_add_first(list, lst_new("ernesmar"));
	status("Se añade 'ernesmar' al principio:", *list, 1);
	lst_add_after(lst_search(*list, "ernesmar"), lst_new("yfuentes"));
	status("Se añade 'yfuentes' después de 'ernesmar':", *list, 0);
	lst_add_after(lst_search(*list, "antgalan"), lst_new("abello-r"));
	status("Se añade 'abello-r' después de 'antgalan':", *list, 1);
	lst_add_last(list, lst_new("pmarquez"));
	status("Se añade 'pmarquez' al final:", *list, 0);
	lst_add_last(list, lst_new("asolano-"));
	status("Se añade 'asolano-' al final:", *list, 2);
	tmp = NULL;
	status("**Sea la lista (constante):**", tmp, 1);
	lst_add_first(&tmp, lst_new("antgalan"));
	status("Se añade 'antgalan' al principio:", tmp, 1);
	tmp = NULL;
	lst_add_last(&tmp, lst_new("antgalan"));
	status("Se añade 'antgalan' al final:", tmp, 1);
	tmp = NULL;
	lst_add_after(lst_search(tmp, "antgalan"), lst_new("abello-r"));
	status("Se añade 'abello-r' después de 'antgalan':", tmp, 3);
}

void	test_stats(t_list *list)
{
	lst_add_after(lst_search(list, "yfuentes"), lst_new("ernesmar"));
	status("**Sea la lista:**", list, 2);
	ft_putstr_fd("El primer elemento:\t", 1);
	if (lst_first(list))
		ft_putendl_fd(lst_first(list)->data, 1);
	else
		ft_putendl_fd("No existe", 1);
	ft_putstr_fd("El último elemento:\t", 1);
	if (lst_last(list))
		ft_putendl_fd(lst_last(list)->data, 1);
	else
		ft_putendl_fd("No existe", 1);
	ft_putstr_fd("\n¿Está 'antgalan'?:\t", 1);
	if (lst_search(list, "antgalan"))
		ft_putendl_fd("Sí", 1);
	else
		ft_putendl_fd("No", 1);
	ft_putstr_fd("¿Está 'sr-galan'?:\t", 1);
	if (lst_search(list, "srgalan"))
		ft_putendl_fd("Sí", 1);
	else
		ft_putendl_fd("No", 1);
	ft_putstr_fd("\n\n\n", 1);
}

void	test_deletion(t_list **list)
{
	status("**Sea la lista:**", *list, 1);
	lst_purge(list, "ernesmar");
	status("Se purga *ernesmar*:", *list, 1);
	lst_remove_first(list);
	status("Se elimina el primer elemento:", *list, 0);
	lst_remove_last(list);
	status("Se elimina el último elemento:", *list, 1);
	lst_remove(list, lst_search(*list, "abello-r"));
	status("Se elimina 'abello-r':", *list, 1);
	lst_clear(list);
	status("Se vacía la lista:", *list, 1);
}

int	main(void)
{
	t_list	*list;
	t_list	*empty;

	empty = NULL;
	list = NULL;
	ft_putstr_fd("# Funciones de creación\n\n", 1);
	test_addition(&list);
	ft_putstr_fd("# Funciones de atributos\n\n", 1);
	test_stats(list);
	test_stats(empty);
	ft_putstr_fd("# Funciones de eliminación\n\n", 1);
	test_deletion(&list);
	ft_putchar_fd('\n', 1);
	test_deletion(&empty);
	return (0);
}
