/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:14:30 by alejandj          #+#    #+#             */
/*   Updated: 2025/04/12 19:07:00 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
Takes the first element from stack and puts it first in the oder stack
*/
void	push(t_stack **dest, t_stack **src)
{
	t_list	*node;

	if (!dest)
		return ;
	if (!src || !(*src) || !(*src)->head)
		return ;
	node = (*src)->head;
	(*src)->head = node->next;
	node->next = (*dest)->head;
	(*dest)->head = node;
}

void    pa(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_a, stack_b);
    ft_printf("pa\n");
}

void    pb(t_stack **stack_b, t_stack **stack_a)
{
    push(stack_b, stack_a);
    ft_printf("pb\n");
}

//  ===========
// || Push test ||
//  ===========

/*
int	main(void)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*a1;
	int		*a2;
	int		*a3;
	int		*b1;
	int		*b2;
	int		*b3;
	t_list	*n1a;
	t_list	*n2a;
	t_list	*n3a;
	t_list	*n1b;
	t_list	*n2b;
	t_list	*n3b;
	t_list	*current_a;
	t_list	*current_b;

	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	//Values a
	a1 = malloc(sizeof(int));
	a2 = malloc(sizeof(int));
	a3 = malloc(sizeof(int));
	*a1 = 2;
	*a2 = 3;
	*a3 = 4;
	//Values b
	b1 = malloc(sizeof(int));
	b2 = malloc(sizeof(int));
	b3 = malloc(sizeof(int));
	*b1 = 6;
	*b2 = 5;
	*b3 = 10;
	//Nodes a
	n1a = ft_lstnew(a1);
	n2a = ft_lstnew(a2);
	n3a = ft_lstnew(a3);
	//Nodes b
	n1b = ft_lstnew(b1);
	n2b = ft_lstnew(b2);
	n3b = ft_lstnew(b3);
	//Add nodes stack_a
	ft_lstadd_back(&(stack_a->head), n1a);
	ft_lstadd_back(&(stack_a->head), n2a);
	ft_lstadd_back(&(stack_a->head), n3a);
	//Add nodes stack_b
	ft_lstadd_back(&(stack_b->head), n1b);
	ft_lstadd_back(&(stack_b->head), n2b);
	ft_lstadd_back(&(stack_b->head), n3b);
	//Print stacks
	ft_printf("Before push\n");
	ft_printf("Stack a\n");
	current_a = stack_a->head;
	while (current_a != NULL)
	{
		ft_printf("%d\n", *(int *)(current_a->content));
		current_a = current_a->next;
	}
	ft_printf("Stack b\n");
	current_b = stack_b->head;
	while (current_b != NULL)
	{
		ft_printf("%d\n", *(int *)(current_b->content));
		current_b = current_b->next;
	}
	ft_printf("After push\n");
	pb(&stack_b, &stack_a);
	ft_printf("Stack a\n");
	current_a = stack_a->head;
	while (current_a != NULL)
	{
		ft_printf("%d\n", *(int *)(current_a->content));
		current_a = current_a->next;
	}
	ft_printf("Stack b\n");
	current_b = stack_b->head;
	while (current_b != NULL)
	{
		ft_printf("%d\n", *(int *)(current_b->content));
		current_b = current_b->next;
	}
}
*/