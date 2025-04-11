/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:52:19 by alejandj          #+#    #+#             */
/*   Updated: 2025/04/12 01:09:04 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_number(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i] != '\0')
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

void	fill_stack(int n, t_stack **stack_a, t_stack **stack_b)
{
	t_list	*node;
	t_list	*current;
	int		*num;

	num = malloc(sizeof(int));
	if (!num)
		print_errors(*stack_a, *stack_b);
	*num = n;
	node = ft_lstnew(num);
	if (!node)
		print_errors(*stack_a, *stack_b);
	if ((*stack_a)->head == NULL)
	{
		(*stack_a)->head = node;
		return ;
	}
	current = (*stack_a)->head;
	while (current != NULL)
	{
		if (*(int *)(current->content) == n)
			print_errors(*stack_a, *stack_b);
		current = current->next;
	}
	ft_lstadd_back(&((*stack_a)->head), node);
}

void	validate_fill_stack(int argc, char *argv[], t_stack **stack_a,
		t_stack **stack_b)
{
	int		i;
	int		j;
	int		num;
	char	**arr;

	i = 1;
	while (i < argc)
	{
		arr = ft_split(argv[i], ' ');
		j = 0;
		while (arr[j] != NULL)
		{
			if (!is_number(arr[j]))
				print_errors(*stack_a, *stack_b);
			num = ft_atoi(arr[j]);
			if (num > INT_MAX || num < INT_MIN)
				print_errors(*stack_a, *stack_b);
			fill_stack(num, stack_a, stack_b);
			j++;
		}
		free_arr(arr);
		i++;
	}
}

void	init_stacks(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = malloc(sizeof(t_stack));
	if (!*stack_a)
		print_errors(*stack_a, *stack_b);
	(*stack_a)->head = NULL;
	*stack_b = malloc(sizeof(t_stack));
	if (!*stack_b)
		print_errors(*stack_a, *stack_b);
	(*stack_b)->head = NULL;
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	init_stacks(&stack_a, &stack_b);
	if (argc < 2)
		print_errors(stack_a, stack_b);
	validate_fill_stack(argc, argv, &stack_a, &stack_b);
	print_stack(stack_a);
	sort4(&stack_a, &stack_b);
	ft_printf("Despues\n");
	print_stack(stack_a);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
