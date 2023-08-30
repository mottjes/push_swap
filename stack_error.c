/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:09:22 by mottjes           #+#    #+#             */
/*   Updated: 2023/07/26 15:41:19 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
checks if the input has non number values
returns 1 if there is a non number
*/
int	error_no_int(char *str_nbr)
{
	if (!(*str_nbr == '+' || *str_nbr == '-' 
			|| (*str_nbr >= '0' && *str_nbr <= '9')))
		return (1);
	if ((*str_nbr == '+' || *str_nbr == '-') 
		&& (str_nbr[1] < '0' || str_nbr[1] > '9'))
		return (1);
	while (*++str_nbr)
	{
		if (*str_nbr < '0' || *str_nbr > '9')
			return (1);
	}
	return (0);
}

/*
checks for duplicates in stack
returns 1 if there are duplicates
*/
int	error_duplicates(t_stack_node *stack, int nbr)
{
	while (stack->next)
	{
		if ((stack->value == nbr) && (stack->next != NULL))
			return (1);
		stack = stack->next;
	}
	return (0);
}

/*
frees the allocated "fake" av
*/
void	ft_free_av(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

/*
frees the stack
*/
void	free_stack(t_stack_node	*stack)
{
	t_stack_node	*current;
	t_stack_node	*next;

	current = stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
