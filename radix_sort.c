/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:28:40 by mottjes           #+#    #+#             */
/*   Updated: 2023/07/28 15:36:59 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_if_bit_is_0(t_stack_node **a, t_stack_node **b, int i)
{
	if ((((*a)->index >> i) & 1) == 1)
		ra(a);
	else
		pb(a, b);
}

void	push_a_if_bit_is_1(t_stack_node **a, t_stack_node	**b, int i)
{
	if ((((*b)->index >> i) & 1) == 1)
		pa(a, b);
	else
		rb(b);
}

void	radix_sort(t_stack_node **a, t_stack_node **b)
{
	int	nodes;
	int	i;

	i = 0;
	indexing(a);
	while (!stack_sorted(*a))
	{
		nodes = count_nodes(*a);
		while (nodes)
		{
			push_b_if_bit_is_0(a, b, i);
			if (stack_sorted(*a))
				break ;
			nodes--;
		}
		i++;
		nodes = count_nodes(*b);
		while (nodes && !stack_sorted(*a))
		{
			push_a_if_bit_is_1(a, b, i);
			nodes--;
		}
	}
	while (*b)
		pa(a, b);
}
