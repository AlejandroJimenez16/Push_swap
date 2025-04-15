/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 03:59:40 by alejandj          #+#    #+#             */
/*   Updated: 2025/04/15 04:05:07 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_duplicate(t_stack *stack_a, int n)
{
	t_list	*current;

	current = stack_a->head;
	while (current != NULL)
	{
		if (*(int *)(current->content) == n)
			return (1);
		current = current->next;
	}
	return (0);
}