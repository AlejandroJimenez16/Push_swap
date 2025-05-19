/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_heavy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:36:02 by alejandj          #+#    #+#             */
/*   Updated: 2025/05/19 12:55:57 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_up_number(t_stack **stack_a, int value)
{
	int		pos;

	pos = get_pos_num(*stack_a, value);
	if (pos == 0)
		return ;
	if (pos <= ft_lstsize((*stack_a)->head) / 2)
		while (pos-- > 0)
			ra(stack_a);
	else
		while (pos++ < ft_lstsize((*stack_a)->head))
			rra(stack_a);
}

void	push_b_chunk(t_stack **stack_a, t_stack **stack_b,
		const t_chunk_info *chunk)
{
	t_list	*current;
	int		value;
	int		found;

	found = 1;
	while (found)
	{
		found = 0;
		current = (*stack_a)->head;
		while (current != NULL)
		{
			value = *(int *)(current->content);
			if (value >= chunk->low && value <= chunk->high)
			{
				move_up_number(stack_a, value);
				pb(stack_b, stack_a);
				if (value < (chunk->low + chunk->high) / 2)
					rb(stack_b);
				found = 1;
				break ;
			}
			current = current->next;
		}
	}
}

void	push_max_a(t_stack **stack_a, t_stack **stack_b)
{
	int	pos_max;
	int	size;

	while ((*stack_b)->head)
	{
		pos_max = get_pos_num_max(*stack_b);
		size = ft_lstsize((*stack_b)->head);
		if (pos_max == 0)
			pa(stack_a, stack_b);
		else
		{
			if (pos_max <= size / 2)
			{
				while (pos_max-- > 0)
					rb(stack_b);
			}
			else
			{
				while (pos_max++ < size)
					rrb(stack_b);
			}
			pa(stack_a, stack_b);
		}
	}
}

void	process_chunks(t_chunk_info *chunk, int *arr,
		t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	while (i < chunk->chunk_count)
	{
		chunk->low = arr[i * chunk->chunk_size];
		if (i == chunk->chunk_count - 1)
			chunk->high = arr[chunk->size - 1];
		else
			chunk->high = arr[(i + 1) * chunk->chunk_size - 1];
		push_b_chunk(stack_a, stack_b, chunk);
		i++;
	}
}

void	sort_heavy(t_stack **stack_a, t_stack **stack_b)
{
	t_chunk_info	chunk;
	int				*arr;

	if (is_sort(stack_a))
		return ;
	chunk.size = ft_lstsize((*stack_a)->head);
	arr = stack_to_array(*stack_a);
	if (!arr)
		return ;
	sort_arr(arr, chunk.size);
	if (chunk.size <= 100)
		chunk.chunk_count = 4;
	else
		chunk.chunk_count = 9;
	chunk.chunk_size = (chunk.size / chunk.chunk_count) + 3;
	process_chunks(&chunk, arr, stack_a, stack_b);
	free(arr);
	push_max_a(stack_a, stack_b);
}
