/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:19:54 by alejandj          #+#    #+#             */
/*   Updated: 2025/04/24 17:31:45 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack *stack)
{
	t_list	*current;
	t_list	*next;

	current = stack->head;
	while (current != NULL)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	free(stack);
}

void	free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	print_errors(t_stack *stack_a, t_stack *stack_b)
{
	write(2, "Error\n", 6);
	free_stack(stack_a);
	free_stack(stack_b);
	exit(1);
}

void	print_errors_arr(t_stack *stack_a, t_stack *stack_b, char **arr)
{
	write(2, "Error\n", 6);
	free_arr(arr);
	free_stack(stack_a);
	free_stack(stack_b);
	exit(1);
}

void	print_stack(t_stack *stack)
{
	t_list	*current;

	current = stack->head;
	while (current != NULL)
	{
		ft_printf("%d\n", *(int *)(current->content));
		current = current->next;
	}
}
