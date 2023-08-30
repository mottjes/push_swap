/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:04:22 by mottjes           #+#    #+#             */
/*   Updated: 2023/08/30 13:34:14 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		a = stack_init(av);
		ft_free_av(av);
	}
	else
		a = stack_init(av + 1);
	if (!a)
		return (write (2, "Error\n", 6), 1);
	stack_sort(&a, &b);
	free_stack(a);
}
