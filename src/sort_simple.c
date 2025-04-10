/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:08:50 by alejandj          #+#    #+#             */
/*   Updated: 2025/04/10 16:18:56 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sort(t_stack **stack)
{
	t_list	*current;

	if (!stack || !(*stack) || !(*stack)->head || !(*stack)->head->next)
		return (1);
	current = (*stack)->head;
	while (current->next != NULL)
	{
		if (*(int *)(current->content) > *(int *)(current->next->content))
		{
			return (0);
		}
		current = current->next;
	}
	return (1);
}

void	sort3(t_stack **stack)
{
	t_list	*first;
	t_list	*last;
	int		sorted;

	if (!stack || !(*stack) || !(*stack)->head || !(*stack)->head->next)
		return ;
	first = (*stack)->head;
	last = ft_lstlast((*stack)->head);
	sorted = 0;
	while (sorted == 0)
	{
		sorted = 1;
		if (*(int *)(first->content) > *(int *)(first->next->content))
		{
			sa(stack);
			sorted = 0;
		}
		if (*(int *)(first->content) > *(int *)(last->content))
		{
			rra(stack);
			sorted = 0;
		}
		if (*(int *)(first->next->content) > *(int *)(last->content))
		{
			rra(stack);
			sorted = 0;
		}
		sorted = is_sort(stack);
		first = (*stack)->head;
		last = ft_lstlast((*stack)->head);
	}
}

void	sort4(t_stack **stack_a)
{
	
}
