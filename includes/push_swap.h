/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:23:51 by alejandj          #+#    #+#             */
/*   Updated: 2025/05/16 13:26:45 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	t_list	*head;
}			t_stack;

// Additional Functions
void		free_stack(t_stack *stack);
void		free_arr(char **arr);
void		print_errors(t_stack *stack_a, t_stack *stack_b);
void		print_errors_arr(t_stack *stack_a, t_stack *stack_b, char **arr);
void		print_errors_num_node(t_stack *stack_a, t_stack *stack_b,
				t_list *node, int *num);
void		print_stack(t_stack *stack);
int			is_duplicate(t_stack *stack_a, int n);

// Rules
void		swap(t_stack **stack);
void		sa(t_stack **stack_a);
void		sb(t_stack **stack_b);
void		ss(t_stack **stack_a, t_stack **stack_b);

void		push(t_stack **dest, t_stack **src);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_b, t_stack **stack_a);

void		rotate(t_stack **stack);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);

void		reverse_rotate(t_stack **stack);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);

// Sorting functions
int			is_sort(t_stack **stack);
int			get_pos_num_min(t_stack *stack);
int			get_pos_num_max(t_stack *stack);
int			get_min(t_stack *stack);
int			get_max(t_stack *stack);
void		manage_sort(t_stack **stack_a, t_stack **stack_b);

int			*stack_to_array(t_stack *stack);
void		sort_arr(int *arr, int len);

// Simple Sorting functions
void		sort3(t_stack **stack_a);
void		sort4(t_stack **stack_a, t_stack **stack_b);
void		sort5(t_stack **stack_a, t_stack **stack_b);

// Heavy Sorting functions
void		sort_heavy(t_stack **stack_a, t_stack **stack_b);

#endif