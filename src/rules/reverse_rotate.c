/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:35:36 by alejandj          #+#    #+#             */
/*   Updated: 2025/04/09 17:37:28 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Move all elements in stack down one position,
	so that the last element become the first

[ [1] [5] [8] ] --> [ [8] [1] [5] ]

*/
void	reverse_rotate(t_stack **stack)
{
	t_list	*current;
	t_list	*first;
	t_list	*last;

	if (!stack || !(*stack) || !(*stack)->head || !(*stack)->head->next)
		return ;
	first = (*stack)->head;
	last = ft_lstlast((*stack)->head);
	current = first;
	while (current != NULL)
	{
		if (current->next == last)
			break ;
		current = current->next;
	}
	current->next = NULL;
	last->next = first;
	(*stack)->head = last;
}

void    rra(t_stack **stack_a)
{
    reverse_rotate(stack_a);
    ft_printf("rra\n");
}

void    rrb(t_stack **stack_b)
{
    reverse_rotate(stack_b);
    ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !(*stack_a) || !(*stack_a)->head || !(*stack_a)->head->next)
		return ;
	if (!stack_b || !(*stack_b) || !(*stack_b)->head || !(*stack_b)->head->next)
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}

//  ======================
// || Reverse rotate test ||
//  ======================

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
	ft_printf("Before reverse rotate\n");
	current = stack->head;
	while (current != NULL)
	{
		ft_printf("%d\n", *(int *)(current->content));
		current = current->next;
	}
	ft_printf("After reverse rotate\n");
	reverse_rotate(&stack);
	current = stack->head;
	while (current != NULL)
	{
		ft_printf("%d\n", *(int *)(current->content));
		current = current->next;
	}
}
*/
