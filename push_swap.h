/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:05:23 by mottjes           #+#    #+#             */
/*   Updated: 2023/07/28 15:31:35 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node	*next;
}				t_stack_node;

//		stack_init
t_stack_node	*stack_init(char *av[]);
int				append_node(t_stack_node **stack, int nbr);
long			ft_atol(const char *str);
void			indexing(t_stack_node **a);

//		split
char			**split(char const *s, char c);

//		stack_error
void			free_stack(t_stack_node	*stack);
int				error_duplicates(t_stack_node *stack, int nbr);
int				error_no_int(char *str_nbr);
void			ft_free_av(char **av);

//		stack_utils
t_stack_node	*find_last_node(t_stack_node *head);
int				count_nodes(t_stack_node *stack);
int				stack_sorted(t_stack_node *stack);
t_stack_node	*find_node_before_last(t_stack_node *head);
t_stack_node	*find_lowest(t_stack_node *stack);

//		stack_sort
void			stack_sort(t_stack_node **a, t_stack_node **b);
void			tiny_sort(t_stack_node **a);
void			push_lowest_nodes(t_stack_node **a, t_stack_node **b);
void			sort_small_stack(t_stack_node **a, t_stack_node **b);

//		radix_sort
void			radix_sort(t_stack_node **a, t_stack_node **b);
void			push_a_if_bit_is_1(t_stack_node **a, t_stack_node	**b, int i);
void			push_b_if_bit_is_0(t_stack_node **a, t_stack_node **b, int i);

//		ops_p_s
void			sa(t_stack_node **a);
void			sb(t_stack_node	**b);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);

//		ops_r
void			rotate(t_stack_node **stack);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
//		ops_rr
void			reverse_rotate(t_stack_node **stack);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

#endif
