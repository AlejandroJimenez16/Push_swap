/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 01:29:07 by alejandj          #+#    #+#             */
/*   Updated: 2025/04/21 02:25:42 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sort(t_stack **stack)
{
	t_list	*current;

	if (!stack || !(*stack) || !(*stack)->head || !(*stack)->head->next)
		return (0);
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

int	get_pos_num_min(t_stack *stack)
{
	t_list	*current;
	int		pos;
	int		min;

	if (!stack || !stack->head)
		return (-1);
	pos = 0;
	current = stack->head;
	min = *(int *)(current->content);
	current = current->next;
	while (current != NULL)
	{
		if (*(int *)(current->content) < min)
			min = *(int *)(current->content);
		current = current->next;
	}
	current = stack->head;
	while (*(int *)(current->content) != min)
	{
		pos++;
		current = current->next;
	}
	return (pos);
}

int	get_pos_num_max(t_stack *stack)
{
	t_list	*current;
	int		pos;
	int		max;

	if (!stack || !stack->head)
		return (-1);
	pos = 0;
	current = stack->head;
	max = *(int *)(current->content);
	current = current->next;
	while (current != NULL)
	{
		if (*(int *)(current->content) > max)
			max = *(int *)(current->content);
		current = current->next;
	}
	current = stack->head;
	while (*(int *)(current->content) != max)
	{
		pos++;
		current = current->next;
	}
	return (pos);
}

int	get_min(t_stack *stack)
{
	t_list	*current;
	int		min;

	if (!stack || !stack->head)
		return (-1);
	current = stack->head;
	min = *(int *)(current->content);
	current = current->next;
	while (current != NULL)
	{
		if (*(int *)(current->content) < min)
			min = *(int *)(current->content);
		current = current->next;
	}
	return (min);
}

int	get_max(t_stack *stack)
{
	t_list	*current;
	int		max;

	if (!stack || !stack->head)
		return (-1);
	current = stack->head;
	max = *(int *)(current->content);
	current = current->next;
	while (current != NULL)
	{
		if (*(int *)(current->content) > max)
			max = *(int *)(current->content);
		current = current->next;
	}
	return (max);
}
