/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:23:51 by alejandj          #+#    #+#             */
/*   Updated: 2025/03/31 14:57:39 by alejandj         ###   ########.fr       */
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
void	free_stack(t_stack *stack);
void	print_stack(t_stack *stack);

// Rules
void		swap(t_stack **stack);
void		push(t_stack **stack_a, t_stack **stack_b);

#endif