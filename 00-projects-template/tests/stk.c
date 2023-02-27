/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:32:56 by antgalan          #+#    #+#             */
/*   Updated: 2023/01/22 17:59:58 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../datalib/datalib.h"

void	status(char *msg, t_stack *lst, unsigned int spc)
{
	unsigned int	i;

	i = 0;
	ft_putstr_fd(msg, 1);
	ft_putstr_fd("\t`", 1);
	stk_print(lst);
	ft_putstr_fd("`\n", 1);
	while (i++ < spc)
		ft_putchar_fd('\n', 1);
}

void	test_basics(t_stack **stack)
{
	t_stack	*tmp;

	status("**Sea la pila:**", *stack, 1);
	stk_push(stack, "antgalan");
	status("Se apila 'antgalan':", *stack, 0);
	stk_push(stack, "yfuentes");
	status("Se apila 'yfuentes':", *stack, 0);
	stk_push(stack, "ernesmar");
	status("Se apila 'ernesmar':", *stack, 0);
	stk_push(stack, "antgalan");
	status("Se apila 'antgalan':", *stack, 0);
	stk_push(stack, "pmarquez");
	status("Se apila 'pmarquez':", *stack, 1);
	tmp = stk_pop(stack);
	status("Se desapila un elemento:", *stack, 0);
	status("Elemento desapilado:", tmp, 1);
	stk_clear(stack);
	status("Se vacía la pila:", *stack, 3);
}

void	test_stats(t_stack *stack)
{
	status("**Sea la pila:**", stack, 1);
	ft_putstr_fd("¿Está vacía?: ", 1);
	ft_putnbr_fd(stk_empty(stack), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Tamaño: ", 1);
	ft_putnbr_fd(stk_size(stack), 1);
	ft_putstr_fd("\n\n", 1);
	ft_putstr_fd("Vistazo al tope: ", 1);
	ft_putendl_fd(stk_peek(stack), 1);
}

int	main(void)
{
	t_stack	*stack;

	stack = NULL;
	ft_putstr_fd("# Funciones básicas\n\n", 1);
	test_basics(&stack);
	ft_putstr_fd("# Funciones de atributos\n\n", 1);
	stk_push(&stack, "antgalan");
	stk_push(&stack, "yfuentes");
	stk_push(&stack, "ernesmar");
	stk_push(&stack, "pmarquez");
	test_stats(stack);
	return (0);
}
