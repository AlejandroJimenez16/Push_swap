/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:19:54 by alejandj          #+#    #+#             */
/*   Updated: 2025/03/31 15:04:59 by alejandj         ###   ########.fr       */
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
