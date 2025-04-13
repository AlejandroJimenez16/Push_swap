/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:08:50 by alejandj          #+#    #+#             */
/*   Updated: 2025/04/12 20:12:40 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_options_3(int a, int b, int c, t_stack **stack)
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

	if (!stack || !(*stack) || !(*stack)->head)
		return ;
	if (is_sort(stack) == 1)
		return ;
	while (1)
	{
		first = (*stack)->head;
		last = ft_lstlast((*stack)->head);
		a = *(int *)(first->content);
		b = *(int *)(first->next->content);
		c = *(int *)(last->content);
		sort_options_3(a, b, c, stack);
		if (is_sort(stack) == 1)
			break ;
	}
}

void	sort_options_4_5(t_stack **stack_a, t_stack **stack_b, int pos_min)
{
	int	len;

	len = ft_lstsize((*stack_a)->head);
	if (pos_min == 0)
	{
		pb(stack_b, stack_a);
		return ;
	}
	if (pos_min <= len / 2)
	{
		while (pos_min > 0)
		{
			ra(stack_a);
			pos_min--;
		}
	}
	else
	{
		while (pos_min < len)
		{
			rra(stack_a);
			pos_min++;
		}
	}
	pb(stack_b, stack_a);
}

void	sort4(t_stack **stack_a, t_stack **stack_b)
{
	int	pos_min;

	if (!stack_a || !(*stack_a) || !(*stack_a)->head)
		return ;
	if (!stack_b)
		return ;
	if (is_sort(stack_a) == 1)
		return ;
	pos_min = get_pos_num_min(*stack_a);
	sort_options_4_5(stack_a, stack_b, pos_min);
	sort3(stack_a);
	pa(stack_a, stack_b);
}

void	sort5(t_stack **stack_a, t_stack **stack_b)
{
	int	pos_min;

	if (!stack_a || !(*stack_a) || !(*stack_a)->head)
		return ;
	if (!stack_b)
		return ;
	if (is_sort(stack_a) == 1)
		return ;
	pos_min = get_pos_num_min(*stack_a);
	sort_options_4_5(stack_a, stack_b, pos_min);
	sort4(stack_a, stack_b);
	pa(stack_a, stack_b);
}
