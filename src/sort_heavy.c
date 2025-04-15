/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_heavy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:36:02 by alejandj          #+#    #+#             */
/*   Updated: 2025/04/15 03:09:28 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/*
void    sort_heavy(t_stack **stack_a, t_stack **stack_b)
{
    
}
*/


// 30k movs
/*
void    sort_heavy(t_stack **stack_a, t_stack **stack_b)
{
    int len;
    int pos_min;
    int i;
    int size = ft_lstsize((*stack_a)->head);

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