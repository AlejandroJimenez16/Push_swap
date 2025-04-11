/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:08:50 by alejandj          #+#    #+#             */
/*   Updated: 2025/04/11 14:47:57 by alejandj         ###   ########.fr       */
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

void	sort_options(int a, int b, int c, t_stack **stack)
{
	if (a > b && b > c)
		sa(stack);
	if (a < b && b > a)
		rra(stack);
	if (a > b && b < c)
		sa(stack);
}

void	sort3(t_stack **stack)
{
	t_list	*first;
	t_list	*last;
	int		a;
	int		b;
	int		c;

	if (!stack || !(*stack) || !(*stack)->head || !(*stack)->head->next)
		return ;
	while (1)
	{
		first = (*stack)->head;
		last = ft_lstlast((*stack)->head);
		a = *(int *)(first->content);
		b = *(int *)(first->next->content);
		c = *(int *)(last->content);
		sort_options(a, b, c, stack);
		if (is_sort(stack) == 1)
			break ;
	}
}

void	sort4(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !(*stack_a) || !(*stack_a)->head || !(*stack_a)->head->next)
		return ;
	if (!stack_b || !(*stack_b) || !(*stack_b)->head || !(*stack_b)->head->next)
		return ;
	pb(stack_b, stack_a);
	print_stack(*stack_a);
	print_stack(*stack_b);
	sort3(stack_a);
	pa(stack_a, stack_b);
}
