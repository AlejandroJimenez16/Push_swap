/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 03:59:40 by alejandj          #+#    #+#             */
/*   Updated: 2025/04/18 23:57:34 by alejandj         ###   ########.fr       */
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

void	manage_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	
	size = ft_lstsize((*stack_a)->head);
	if (size == 1)
		return;
	else if (size == 2)
	{
		if (*(int *)((*stack_a)->head->content) > *(int *)((*stack_a)->head->next->content))
			sa(stack_a);
	}
	else if (size == 3)
		sort3(stack_a);
	else if (size == 4)
		sort4(stack_a, stack_b);
	else if (size == 5)
		sort5(stack_a, stack_b);
	else if (size > 5)
		sort_heavy(stack_a, stack_b);
}