/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:52:19 by alejandj          #+#    #+#             */
/*   Updated: 2025/03/26 22:51:31 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_errors(char *error, t_stack *stack_a)
{
	ft_printf("%s\n", error);
	if (stack_a)
		free_stacks(stack_a);
	exit(1);
}

void	fill_stack(int n, t_stack **stack_a)
{
	t_list	*node;
	t_list *current;
	int		*num;

	num = malloc(sizeof(int));
	if (!num)
		print_errors("Error allocating memory", *stack_a);
	*num = n;
	node = ft_lstnew(num);
	if (!node)
		print_errors("Error creating new node", *stack_a);
	if ((*stack_a)->head == NULL)
	{
		(*stack_a)->head = node;
		return;
	}
	current = (*stack_a)->head;
	while (current != NULL)
	{
		if (*(int *)(current->content) == n)
			print_errors("Duplicate numbers", *stack_a);
		current = current->next;
	}
	ft_lstadd_back(&((*stack_a)->head), node);
	
	//----------Imprimir lista para ver-----------------
	t_list *temp;
	temp = (*stack_a)->head;
	while (temp != NULL)
	{
		ft_printf("%d\n", *(int *)(temp->content));
		temp = temp->next;
	}
	//---------------------------------------------------
}

void	validate_fill_stack(int argc, char *argv[], t_stack **stack_a)
{
	int	i;
	int j;
	int num;
	int isneg;

	i = 1;
	while (i < argc)
	{
		j = 0;
		isneg = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == ' ')
				j++;
			if (argv[i][j] == '-')
			{
				isneg = 1;
				j++;	
			}
			if (!ft_isdigit(argv[i][j]))
				print_errors("Only numbers are allowed", *stack_a);
			num = ft_atoi(&argv[i][j]);
			if (isneg)
				num = -num;
			if (num > INT_MAX || num < INT_MIN)
				print_errors("Number is out of range", *stack_a);
			fill_stack(num, stack_a);
			while (argv[i][j] != '\0' && argv[i][j] != ' ')
				j++;
		}
		i++;
	}
}

void	init_stacks(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = malloc(sizeof(t_stack));
	if (!*stack_a)
		print_errors("Error allocating memory for stack", *stack_a);
	(*stack_a)->head = NULL;
	*stack_b = malloc(sizeof(t_stack));
	if (!*stack_b)
		print_errors("Error allocating memory for stack", *stack_b);
	(*stack_b)->head = NULL;
}

int	main(int argc, char *argv[])
{
	t_stack *stack_a;
	t_stack *stack_b;
	
	init_stacks(&stack_a, &stack_b);
	if (argc < 2)
		print_errors("No arguments", stack_a);
	validate_fill_stack(argc, argv, &stack_a);
	free(stack_a);
	return (0);
}
