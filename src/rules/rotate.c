/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:24:01 by alejandj          #+#    #+#             */
/*   Updated: 2025/04/11 12:32:40 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
Move all elements in stack up one position,
	so that the first element become the last

[ [1] [5] [8] ] --> [ [5] [8] [1] ]

*/
void	rotate(t_stack **stack)
{
	t_list	*first;

	if (!stack || !(*stack) || !(*stack)->head || !(*stack)->head->next)
		return ;
	first = (*stack)->head;
	(*stack)->head = first->next;
	first->next = NULL;
	ft_lstadd_back(&(*stack)->head, first);
}

void    ra(t_stack **stack_a)
{
    rotate(stack_a);
    ft_printf("ra\n");
}

void    rb(t_stack **stack_b)
{
    rotate(stack_b);
    ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !(*stack_a) || !(*stack_a)->head || !(*stack_a)->head->next)
		return ;
	if (!stack_b || !(*stack_b) || !(*stack_b)->head || !(*stack_b)->head->next)
		return ;
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}

//  ==============
// || Rotate test ||
//  ==============

/*
int	main(void)
{
	t_stack	*stack;
	int		*n1;
	int		*n2;
	int		*n3;
	int		*n4;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*node4;
	t_list	*current;
	int		size;

	stack = malloc(sizeof(t_stack));
	n1 = malloc(sizeof(int));
	n2 = malloc(sizeof(int));
	n3 = malloc(sizeof(int));
	n4 = malloc(sizeof(int));
	*n1 = 5;
	*n2 = 2;
	*n3 = 8;
	*n4 = 1;
	node1 = ft_lstnew(n1);
	node2 = ft_lstnew(n2);
	node3 = ft_lstnew(n3);
	node4 = ft_lstnew(n4);
	ft_lstadd_back(&(stack->head), node1);
	ft_lstadd_back(&(stack->head), node2);
	ft_lstadd_back(&(stack->head), node3);
	ft_lstadd_back(&(stack->head), node4);
	ft_printf("Before rotate\n");
	current = stack->head;
	while(current != NULL)
	{
		ft_printf("%d\n", *(int *)(current->content));
		current = current->next;
	}
	ft_printf("After rotate\n");
	rotate(&stack);
	size = ft_lstsize(stack->head);
	current = stack->head;
	while(current != NULL)
	{
		ft_printf("%d\n", *(int *)(current->content));
		current = current->next;
	}
	ft_printf("Size : %d\n", size);
}
*/