/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   que.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:32:56 by antgalan          #+#    #+#             */
/*   Updated: 2023/01/22 17:59:49 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../datalib/datalib.h"

void	status(char *msg, t_queue *lst, unsigned int spc)
{
	unsigned int	i;

	i = 0;
	ft_putstr_fd(msg, 1);
	ft_putstr_fd("\t`", 1);
	que_print(lst);
	ft_putstr_fd("`\n", 1);
	while (i++ < spc)
		ft_putchar_fd('\n', 1);
}

void	test_basics(t_queue **queue)
{
	void	*tmp;

	status("**Sea la cola:**", *queue, 1);
	que_enqueue(queue, "antgalan");
	status("Se encola 'antgalan':", *queue, 0);
	que_enqueue(queue, "yfuentes");
	status("Se encola 'yfuentes':", *queue, 0);
	que_enqueue(queue, "ernesmar");
	status("Se encola 'ernesmar':", *queue, 0);
	que_enqueue(queue, "antgalan");
	status("Se encola 'antgalan':", *queue, 0);
	que_enqueue(queue, "pmarquez");
	status("Se encola 'pmarquez':", *queue, 1);
	tmp = que_dequeue(queue);
	status("Se desencola un elemento:", *queue, 0);
	ft_putstr_fd("\tDesencolado: ", 1);
	ft_putendl_fd(tmp, 1);
	ft_putchar_fd('\n', 1);
	que_clear(queue);
	status("Se vacía la cola:", *queue, 1);
	tmp = que_dequeue(queue);
	status("Se desencola un elemento:", *queue, 0);
	ft_putstr_fd("\tDesencolado: ", 1);
	ft_putendl_fd(tmp, 1);
	ft_putstr_fd("\n\n\n", 1);
}

void	test_stats(t_queue *queue)
{
	status("**Sea la cola:**", queue, 1);
	ft_putstr_fd("¿Está vacía?: ", 1);
	if (que_empty(queue))
		ft_putstr_fd("Sí\n", 1);
	else
		ft_putstr_fd("No\n", 1);
	ft_putstr_fd("Tamaño de la cola: ", 1);
	ft_putnbr_fd(que_size(queue), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("\nPrimer elemento: ", 1);
	if (que_first(queue))
		ft_putstr_fd(que_first(queue)->data, 1);
	else
		ft_putstr_fd("No existe", 1);
	ft_putstr_fd("\nÚltimo elemento: ", 1);
	if (que_last(queue))
		ft_putstr_fd(que_last(queue)->data, 1);
	else
		ft_putstr_fd("No existe", 1);
	ft_putchar_fd('\n', 1);
}

int	main(void)
{
	t_queue	*queue;

	queue = NULL;
	ft_putstr_fd("# Funciones básicas\n\n", 1);
	test_basics(&queue);
	que_enqueue(&queue, "antgalan");
	que_enqueue(&queue, "yfuentes");
	que_enqueue(&queue, "ernesmar");
	que_enqueue(&queue, "pmarquez");
	ft_putstr_fd("# Funciones de atributos\n\n", 1);
	test_stats(queue);
	ft_putstr_fd("\n\n", 1);
	test_stats(NULL);
	return (0);
}
