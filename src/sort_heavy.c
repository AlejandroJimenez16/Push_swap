/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_heavy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:36:02 by alejandj          #+#    #+#             */
/*   Updated: 2025/05/16 14:37:40 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_pos_num(t_stack *stack, int num)
{
	t_list	*current;
	int		pos;

	pos = 0;
	current = stack->head;
	while (*(int *)(current->content) != num)
	{
		pos++;
		current = current->next;
	}
	return (pos);
}

void	push_b_chunk(t_stack **stack_a, t_stack **stack_b, int low, int high)
{
	t_list	*current;
	int		pos;
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
			if (value >= low && value <= high)
			{
				pos = get_pos_num(*stack_a, value);
				if (pos <= ft_lstsize((*stack_a)->head) / 2)
					while (pos-- > 0)
						ra(stack_a);
				else
					while (pos++ < ft_lstsize((*stack_a)->head))
						rra(stack_a);
				pb(stack_b, stack_a);
				if (value < (low + high) / 2)
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
	int size;

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

void	sort_heavy(t_stack **stack_a, t_stack **stack_b)
{
	int i;
	int size;
	int	*arr;
	int	chunk_size;
	int	chunk_count;
	int	low;
	int	high;

	if (is_sort(stack_a))
		return ;
	size = ft_lstsize((*stack_a)->head);
	arr = stack_to_array(*stack_a);
	if (!arr)
		return ;
	sort_arr(arr, size);
	if (size <= 100)
		chunk_count = 4;
	else
		chunk_count = 7;
	chunk_size = size / chunk_count;
	i = 0;
	while (i < chunk_count)
	{
		low = arr[i * chunk_size];
		if (i == chunk_count - 1)
			high = arr[size - 1];
		else
			high = arr[(i + 1) * chunk_size - 1];
		push_b_chunk(stack_a, stack_b, low, high);
		i++;
	}
	free(arr);
	push_max_a(stack_a, stack_b);
}

// No consegui que funcione
/*
void	sort_heavy(t_stack **stack_a, t_stack **stack_b)
{
	int		rot_count;
	int		send;
	int		pos_min;
	int		len;
	int		spin;
	int		groups;
	int		i;
	t_list	*current;
	t_list	*num;

	pos_min = 0;
	len = ft_lstsize((*stack_a)->head);
	rot_count = 0;
	groups = len / 5;
	i = 0;
	while (i < groups)
	{
		// Envio 5 numeros
		send = 0;
		while(send < 5)
		{
			pb(stack_b, stack_a);
			send++;
		}
		// Ordeno el stack_b
		sort5(stack_b, stack_a);
		//Recorrer a y colocar los nums en su posicion
		current = (*stack_a)->head;
		while (current)
		{
			if (!(*stack_b) || !(*stack_b)->head)
				break ;
			num = (*stack_b)->head;
			if (*(int *)(num->content) < *(int *)(current->content))
			{
				pa(stack_a, stack_b);
				current = (*stack_a)->head;
				rot_count = 0;
			}
			else if ((*(int *)(num->content) < *(int *)(current->next->content))
				&& (*(int *)(num->content) > *(int *)(current->content)))
			{
				ra(stack_a);
				pa(stack_a, stack_b);
				current = (*stack_a)->head;
				rot_count = 0;
			}
			else
			{
				if (current->next == NULL)
				{
					pa(stack_a, stack_b);
					current = (*stack_a)->head;
					rot_count = 0;
				}
				else
				{
					ra(stack_a);
					current = (*stack_a)->head;
					rot_count++;
				}
				if (rot_count >= len)
				{
					pa(stack_a, stack_b);
					current = (*stack_a)->head;
					rot_count = 0;
				}
			}
		}
		// Colocar los nums en orden ascendente
		pos_min = get_pos_num_min(*stack_a);
		if (pos_min < len / 2)
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
		//Giro para enviar los 5 siguientes
		spin = 0;
		while (spin < 5)
		{
			ra(stack_a);
			spin++;
		}
		i++;
	}
	// Colocar los nums en orden ascendente
	pos_min = get_pos_num_min(*stack_a);
	if (pos_min < len / 2)
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
	//Imprimir el stack
	ft_printf("Stack a\n");
	print_stack(*stack_a);
	ft_printf("Stack b\n");
	print_stack(*stack_b);
}
*/

// 30k movs
/*
void	sort_heavy(t_stack **stack_a, t_stack **stack_b)
{
	int	len;
	int	pos_min;
	int	i;
	int	size;

	size = ft_lstsize((*stack_a)->head);
	i = 0;
	while (i < size)
	{
		len = ft_lstsize((*stack_a)->head);
		pos_min = get_pos_num_min(*stack_a);
		if (pos_min == 0)
			pb(stack_b, stack_a);
		else if (pos_min <= len / 2)
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
		i++;
	}
	ft_printf("Stack_a\n");
	print_stack(*stack_a);
	ft_printf("Stack_b\n");
	print_stack(*stack_b);
	i = 0;
	while (i < size)
	{
		pa(stack_a, stack_b);
		i++;
	}
	ft_printf("Stack_a\n");
	print_stack(*stack_a);
	ft_printf("Stack_b\n");
	print_stack(*stack_b);
}
*/