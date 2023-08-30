/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:30:33 by mottjes           #+#    #+#             */
/*   Updated: 2023/07/26 16:31:59 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
returns a ptr to the node before the last node
*/
t_stack_node	*find_node_before_last(t_stack_node *head)
{
	if (!head)
		return (NULL);
	while (head->next->next)
		head = head->next;
	return (head);
}

/*
check if a given stack is sorted
*/
int	stack_sorted(t_stack_node *stack)
{
	int	tmp;

	if (!stack)
		return (1);
	tmp = stack->value;
	while (stack->next)
	{
		stack = stack->next;
		if (stack->value < tmp)
			return (0);
		tmp = stack->value;
	}
	return (1);
}

/*
counts nodes in the stack
*/
int	count_nodes(t_stack_node *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (i);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

/*
returns a ptr to the last node
*/
t_stack_node	*find_last_node(t_stack_node *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

/*
finds and returns the node with the lowest value 
and no index in the stack 
*/
t_stack_node	*find_lowest(t_stack_node *stack)
{
	int				lowest;
	t_stack_node	*lowest_node;

	if (stack == NULL)
		return (NULL);
	lowest_node = NULL;
	while (stack->next && stack->index)
		stack = stack->next;
	if (!stack->index)
	{
		lowest = stack->value;
		lowest_node = stack;
	}
	while (stack->next)
	{
		stack = stack->next;
		if (stack->value < lowest && !stack->index)
		{
			lowest = stack->value;
			lowest_node = stack;
		}
	}
	return (lowest_node);
}
