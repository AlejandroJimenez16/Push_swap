/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_heavy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:36:02 by alejandj          #+#    #+#             */
/*   Updated: 2025/04/21 17:21:06 by alejandj         ###   ########.fr       */
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

void	push_b_chunk(t_stack **stack_a, t_stack **stack_b, int chunck_low,
		int chunck_hight)
{
	t_list	*current;
	int		pos;

	current = (*stack_a)->head;
	while (current != NULL)
	{
		if ((*(int *)(current->content) >= chunck_low)
			&& (*(int *)(current->content) <= chunck_hight))
		{
			pos = get_pos_num(*stack_a, *(int *)(current->content));
			if (pos <= ft_lstsize((*stack_a)->head) / 2)
				while (pos-- > 0)
					ra(stack_a);
			else
			{
				while (pos++ < ft_lstsize((*stack_a)->head))
					rra(stack_a);
			}
			pb(stack_b, stack_a);
			break ;
		}
		else
			current = current->next;
	}
}

void	push_max_a(t_stack **stack_a, t_stack **stack_b)
{
	int	pos_max;

	while ((*stack_b)->head)
	{
		pos_max = get_pos_num_max(*stack_b);
		if (pos_max == 0)
			pa(stack_a, stack_b);
		else
		{
			if (pos_max <= ft_lstsize((*stack_b)->head) / 2)
			{
				while (pos_max-- > 0)
					rb(stack_b);
			}
			else
			{
				while (pos_max++ < ft_lstsize((*stack_b)->head))
					rrb(stack_b);
			}
			pa(stack_a, stack_b);
		}
	}
}

void	sort_heavy(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	max;
	int	step;
	int	chunck_low;
	int	chunck_hight;

	max = get_max(*stack_a);
	while (1)
	{
		min = get_min(*stack_a);
		step = (max - min) / 10;
		chunck_low = min;
		chunck_hight = (min + step);
		push_b_chunk(stack_a, stack_b, chunck_low, chunck_hight);
		if (ft_lstsize((*stack_a)->head) == 0)
			break ;
	}
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