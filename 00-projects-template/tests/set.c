/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:34:26 by antgalan          #+#    #+#             */
/*   Updated: 2023/01/22 17:59:54 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../datalib/datalib.h"

void	status(char *msg, t_set *set, unsigned int spc)
{
	unsigned int	i;

	i = 0;
	ft_putstr_fd(msg, 1);
	ft_putstr_fd("\t`", 1);
	set_print(set);
	ft_putstr_fd("`\n", 1);
	while (i++ < spc)
		ft_putchar_fd('\n', 1);
}

// Los estudiantes contienen usuarios repetidos.
// Los miembros del STAFF son usuarios únicos.
void	test_addition(t_set **a, t_set **b)
{
	ft_putendl_fd("**Sean los conjuntos:**", 1);
	status("A:", *a, 0);
	status("B:", *b, 2);
	set_add(a, "antgalan");
	status("Se añade *antgalan* a A:", *a, 0);
	set_add(a, "agalan-h");
	status("Se añade *agalan-h* a A:", *a, 0);
	set_add(a, "abello-r");
	status("Se añade *abello-r* a A:", *a, 0);
	set_add(a, "ernesmar");
	status("Se añade *ernesmar* a A:", *a, 1);
	set_add(a, "abello-r");
	status("Se añade *abello-r* a A:", *a, 1);
	set_add(b, "cerbero");
	status("Se añade *cerbero*  a B:", *b, 0);
	set_add(b, "abello-r");
	status("Se añade *abello-r* a B:", *b, 0);
	set_add(b, "steamo");
	status("Se añade *steamo*   a B:", *b, 2);
	set_remove(a, "agalan-h");
	status("Se elimina *agalan-h* de A:", *a, 0);
	set_remove(a, "ernmarti");
	status("Se elimina *ernmarti* de A:", *a, 1);
	set_remove(a, "agalan-h");
	status("Se elimina *agalan-h* de A:", *a, 2);
}

// Se opera con los conjuntos de estudiantes y STAFF.
void	test_operations(t_set *a, t_set *b)
{
	ft_putendl_fd("**Sean los conjuntos:**", 1);
	status("A:", a, 0);
	status("B:", b, 2);
	status("Unión.\nA **o** B:", set_union(a, b), 1);
	status("Intersección.\nA **y** B:", set_inter(a, b), 1);
	status("Diferencia (A - B).\nA **y no** B:", set_diff(a, b), 1);
	status("Diferencia (B - A).\nB **y no** A:", set_diff(b, a), 3);
}

void	test_stats(t_set *a, t_set *b)
{
	ft_putendl_fd("**Sean los conjuntos:**", 1);
	status("A:", a, 0);
	status("B:", b, 2);
	status("C:", set_inter(a, b), 0);
	ft_putstr_fd("¿Es subconjunto de B?\n\tRespuesta: ", 1);
	if (set_subset(set_inter(a, b), b))
		ft_putstr_fd("Sí.\n\n", 1);
	else
		ft_putstr_fd("No.\n\n", 1);
	status("D:", set_union(a, b), 0);
	ft_putstr_fd("¿Es subconjunto de A?\n\tRespuesta: ", 1);
	if (set_subset(set_union(a, b), a))
		ft_putstr_fd("Sí.\n\n", 1);
	else
		ft_putstr_fd("No.\n\n", 1);
	ft_putstr_fd("¿Los conjuntos A y B son iguales?\n\tRespuesta:", 1);
	if (set_equal(a, b))
		ft_putstr_fd("\tSí.\n\n", 1);
	else
		ft_putstr_fd("\tNo.\n\n", 1);
}

// Main function.
int	main(void)
{
	t_set	*cursus;
	t_set	*staff;

	cursus = NULL;
	staff = NULL;
	ft_putstr_fd("# Funciones básicas\n\n", 1);
	test_addition(&cursus, &staff);
	set_add(&cursus, "pmarquez");
	set_add(&cursus, "ernmarti");
	set_add(&cursus, "lagarcia");
	set_add(&staff, "lagarcia");
	set_add(&staff, "catarsis");
	set_add(&staff, "medusa");
	set_add(&staff, "pmarquez");
	ft_putstr_fd("\n# Funciones matemáticas\n\n", 1);
	test_operations(cursus, staff);
	test_operations(cursus, NULL);
	ft_putstr_fd("# Funciones de atributos\n\n", 1);
	test_stats(cursus, staff);
	ft_putchar_fd('\n', 1);
	test_stats(cursus, NULL);
	ft_putchar_fd('\n', 1);
	test_stats(set_inter(cursus, staff), set_inter(staff, cursus));
	return (0);
}
