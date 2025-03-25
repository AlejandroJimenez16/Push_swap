/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:52:19 by alejandj          #+#    #+#             */
/*   Updated: 2025/03/24 20:07:46 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	validate_fill_stack(int argc, char *argv[])
{
	int	i;
	int j;
	int num;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == ' ')
				j++;
			if (!ft_isdigit(argv[i][j]))
			{
				ft_printf("Error\n");
				return ;
			}
			num = ft_atoi(&argv[i][j]);
			if (num > INT_MAX || num < INT_MIN)
			{
				ft_printf("Error\n");
				return ;
			}
			ft_printf("%d\n", num);
			while (argv[i][j] != '\0' && argv[i][j] != ' ')
				j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	//t_stack *stack_a;
	//t_stack *stack_b;
	
	//stack_a = NULL;
	//stack_b = NULL;
	if (argc <= 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	validate_fill_stack(argc, argv);
	return (0);
}
