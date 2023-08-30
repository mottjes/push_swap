/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:34:48 by mottjes           #+#    #+#             */
/*   Updated: 2023/07/07 16:12:59 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*node_1;
	t_stack_node	*last_node;
	t_stack_node	*node_before_last;

	if (*stack == NULL)
		return ;
	else if ((*stack)->next == NULL)
		return ;
	node_1 = *stack;
	node_before_last = find_node_before_last(*stack);
	last_node = find_last_node(*stack);
	last_node->next = node_1;
	node_before_last->next = NULL;
	*stack = last_node;
}

/*
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
*/
void	rra(t_stack_node **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

/*
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
*/
void	rrb(t_stack_node **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

/*
rrr : rra and rrb at the same time.
*/
void	rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
