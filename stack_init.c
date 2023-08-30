/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:15:23 by mottjes           #+#    #+#             */
/*   Updated: 2023/07/28 14:54:04 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_stack_node **a)
{
	t_stack_node	*lowest_node;
	int				i;

	i = 0;
	lowest_node = find_lowest(*a);
	while (lowest_node)
	{
		lowest_node->index = i;
		i++;
		lowest_node = find_lowest(*a);
	}
}

/*
converst ascii input to a long
*/
long	ft_atol(const char *str)
{
	int		i;
	int		minus;
	long	number;

	i = 0;
	number = 0;
	minus = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		number *= 10;
		number += str[i] - 48;
		i++;
	}
	return (number * minus);
}

/*
append a new node to the stack
*/
int	append_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	node = malloc(sizeof(t_stack_node));
	if (!node)
		return (1);
	node->next = NULL;
	node->value = nbr;
	if (*stack == NULL)
		*stack = node;
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
	}
	return (0);
}

/*
initialises the stack and checks if the input is correct
-> returns NULL if in the input is a non int or duplicates
*/
t_stack_node	*stack_init(char *av[])
{
	t_stack_node	*stack;
	long			nbr;

	stack = NULL;
	while (*av)
	{
		if (error_no_int(*av))
			return (free_stack(stack), NULL);
		nbr = ft_atol(*av);
		if (nbr > 2147483647 || nbr < -2147483648)
			return (free_stack(stack), NULL);
		if (append_node(&stack, (int)nbr))
			return (free_stack(stack), NULL);
		if (error_duplicates(stack, (int)nbr))
			return (free_stack(stack), NULL);
		av++;
	}
	return (stack);
}
