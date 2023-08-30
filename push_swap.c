/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:28:31 by mottjes           #+#    #+#             */
/*   Updated: 2023/07/06 18:53:56 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
*/
void	sa(t_stack_node **a)
{
	t_stack_node	*node_1;
	t_stack_node	*node_2;

	if (*a == NULL)
		return ;
	else if ((*a)->next == NULL)
		return ;
	node_1 = *a;
	node_2 = (*a)->next;
	node_1->next = node_2->next;
	node_2->next = node_1;
	*a = node_2;
	write(1, "sa\n", 3);
}

/*
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
*/
void	sb(t_stack_node	**b)
{
	t_stack_node	*node_1;
	t_stack_node	*node_2;

	if (*b == NULL)
		return ;
	else if ((*b)->next == NULL)
		return ;
	node_1 = *b;
	node_2 = (*b)->next;
	node_1->next = node_2->next;
	node_2->next = node_1;
	*b = node_2;
	write(1, "sb\n", 3);
}

/*
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
*/
void	pa(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*node_1;
	t_stack_node	*node_2;

	if (*b == NULL)
		return ;
	else if ((*b)->next == NULL)
	{
		node_1 = *b;
		*b = NULL;
		node_2 = NULL;
	}
	else
	{
		node_1 = *b;
		node_2 = (*b)->next;
		*b = node_2;
	}
	if (*a == NULL)
		node_1->next = NULL;
	else
		node_1->next = *a;
	*a = node_1;
	write(1, "pa\n", 3);
}

/*
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
*/
void	pb(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*node_1;
	t_stack_node	*node_2;

	if (*a == NULL)
		return ;
	else if ((*a)->next == NULL)
	{
		node_1 = *a;
		*a = NULL;
		node_2 = NULL;
	}
	else
	{
		node_1 = *a;
		node_2 = (*a)->next;
		*a = node_2;
	}
	if (*b == NULL)
		node_1->next = NULL;
	else
		node_1->next = *b;
	*b = node_1;
	write(1, "pb\n", 3);
}
