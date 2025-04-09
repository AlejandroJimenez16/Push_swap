/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:08:50 by alejandj          #+#    #+#             */
/*   Updated: 2025/04/09 17:01:43 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_move()
{
	
}

void	sort3(t_stack **stack_a)
{
	t_list	*first;
	
	first = (*stack_a)->head;
	if (first->content < first->next->content)
		swap(stack_a);
}