/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:23:51 by alejandj          #+#    #+#             */
/*   Updated: 2025/03/30 20:59:25 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
    t_list *head;
} t_stack;

// Additional Functions
void	free_stack(t_stack *stack);

// Rules
void    swap_a(t_stack **stack_a);
void    swap_b(t_stack **stack_b);

#endif