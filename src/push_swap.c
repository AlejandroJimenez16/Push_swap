/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:52:19 by alejandj          #+#    #+#             */
/*   Updated: 2025/05/20 16:59:16 by alejandj         ###   ########.fr       */
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

void	fill_stack(int n, t_stack **stack_a, t_stack **stack_b, char **arr)
{
	t_list	*node;
	int		*num;

	num = malloc(sizeof(int));
	if (!num)
		print_errors_arr(*stack_a, *stack_b, arr);
	*num = n;
	node = ft_lstnew(num);
	if (!node)
	{
		free(num);
		print_errors_arr(*stack_a, *stack_b, arr);
	}
	if ((*stack_a)->head == NULL)
	{
		(*stack_a)->head = node;
		return ;
	}
	if (is_duplicate(*stack_a, n) == 1)
	{
		free(node);
		free(num);
		print_errors_arr(*stack_a, *stack_b, arr);
	}
	ft_lstadd_back(&((*stack_a)->head), node);
}

void	validate_fill_stack(int argc, char *argv[], t_stack **stack_a,
		t_stack **stack_b)
{
	int		i;
	int		j;
	long	num;
	char	**arr;

	i = 1;
	while (i < argc)
	{
		arr = ft_split(argv[i], ' ');
		if (!arr)
			print_errors_arr(*stack_a, *stack_b, arr);
		j = 0;
		while (arr[j] != NULL)
		{
			if (!is_number(arr[j]))
				print_errors_arr(*stack_a, *stack_b, arr);
			num = ft_atol(arr[j]);
			if (num > INT_MAX || num < INT_MIN)
				print_errors_arr(*stack_a, *stack_b, arr);
			fill_stack(num, stack_a, stack_b, arr);
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
		print_errors(NULL, NULL);
	(*stack_a)->head = NULL;
	*stack_b = malloc(sizeof(t_stack));
	if (!*stack_b)
		print_errors(*stack_a, NULL);
	(*stack_b)->head = NULL;
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (1);
	init_stacks(&stack_a, &stack_b);
	validate_fill_stack(argc, argv, &stack_a, &stack_b);
	manage_sort(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
