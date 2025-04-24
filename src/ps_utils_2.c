/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 03:59:40 by alejandj          #+#    #+#             */
/*   Updated: 2025/04/24 17:32:52 by alejandj         ###   ########.fr       */
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

void	print_errors_num_node(t_stack *stack_a, t_stack *stack_b, t_list *node,
		int *num)
{
	write(2, "Error\n", 6);
	free(num);
	free(node);
	free_stack(stack_a);
	free_stack(stack_b);
	exit(1);
}

void	manage_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_lstsize((*stack_a)->head);
	if (size == 1)
		return ;
	else if (size == 2)
	{
		if (*(int *)((*stack_a)->head->content) >
			*(int *)((*stack_a)->head->next->content))
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

/*
int	*stack_to_array(t_stack *stack)
{
	t_list	*current;
	int		*arr;
	int		size;
	int		i;

	size = ft_lstsize(stack->head);
	arr = malloc(size * sizeof(int));
	i = 0;
	if (!arr)
		return (NULL);
	current = stack->head;
	while ((current != NULL) && i < size)
	{
		arr[i] = *(int *)(current->content);
		current = current->next;
		i++;
	}
	return (arr);
}

void	sort_arr(int *arr, int len)
{
	int	i;
	int	sorted;
	int	temp;

	sorted = 0;
	while (sorted == 0)
	{
		i = 0;
		sorted = 1;
		while (i < len - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				sorted = 0;
			}
			i++;
		}
	}
}
*/
