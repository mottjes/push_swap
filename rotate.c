/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:29:34 by mottjes           #+#    #+#             */
/*   Updated: 2023/07/07 14:15:19 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack_node **stack)
{
	t_stack_node	*node_1;
	t_stack_node	*last_node;

	if (*stack == NULL)
		return ;
	else if ((*stack)->next == NULL)
		return ;
	node_1 = *stack;
	last_node = find_last_node(*stack);
	*stack = node_1->next;
	node_1->next = NULL;
	last_node->next = node_1;
}

/*
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
*/
void	ra(t_stack_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

/*
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
*/
void	rb(t_stack_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

/*
rr : ra and rb at the same time.
*/
void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
