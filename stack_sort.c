/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:53:33 by mottjes           #+#    #+#             */
/*   Updated: 2023/07/28 15:28:36 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
sorts 3 nodes
*/
void	tiny_sort(t_stack_node **a)
{
	if (stack_sorted(*a))
		return ;
	if ((*a)->value > (*a)->next->value && 
		(*a)->value > (*a)->next->next->value)
		ra(a);
	else if ((*a)->next->value > (*a)->next->next->value)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	push_lowest_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*lowest_node;

	lowest_node = find_lowest(*a);
	if (count_nodes(*a) == 5)
	{
		if (lowest_node == (*a)->next->next->next)
			rra(a);
		if (lowest_node == (*a)->next->next->next->next)
			rra(a);
		else
			while (lowest_node != *a)
				ra(a);
		pb(a, b);
		lowest_node = find_lowest(*a);
	}
	if (count_nodes (*a) == 4)
	{
		if (lowest_node == (*a)->next->next->next)
			rra(a);
		else
			while (lowest_node != *a)
				ra(a);
		pb(a, b);
	}
}

void	sort_small_stack(t_stack_node **a, t_stack_node **b)
{
	if (stack_sorted(*a))
		return ;
	while (count_nodes(*a) > 3)
		push_lowest_nodes(a, b);
	tiny_sort(a);
	while (*b)
		pa(a, b);
}

void	stack_sort(t_stack_node **a, t_stack_node **b)
{
	int	nodes;

	nodes = count_nodes(*a);
	if (nodes == 1)
		return ;
	else if (nodes == 2)
	{
		if (stack_sorted(*a))
			return ;
		else
			return (sa(a));
	}
	else if (nodes <= 5)
		sort_small_stack(a, b);
	else
		radix_sort(a, b);
}
