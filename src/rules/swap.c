/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:02:27 by alejandj          #+#    #+#             */
/*   Updated: 2025/04/09 17:26:08 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Swap the first two elements
*/
void	swap(t_stack **stack)
{
	t_list	*first;
	t_list	*second;
	void	*temp;
	int		size;

	if (!stack || !(*stack) || !(*stack)->head || !(*stack)->head->next)
		return ;
	first = (*stack)->head;
	second = first->next;
	size = ft_lstsize((*stack)->head);
	if (size <= 1)
		return ;
	temp = first->content;
	first->content = second->content;
	second->content = temp;
}

void    sa(t_stack **stack_a)
{
    swap(stack_a);
    ft_printf("sa\n");
}

void    sb(t_stack **stack_b)
{
    swap(stack_b);
    ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !(*stack_a) || !(*stack_a)->head || !(*stack_a)->head->next)
		return ;
	if (!stack_b || !(*stack_b) || !(*stack_b)->head || !(*stack_b)->head->next)
		return ;
	swap(stack_a);
	swap(stack_a);
	ft_printf("ss\n");
}

//  ===========
// || Swap test ||
//  ===========

/*
int	main(void)
{
	t_stack	*stack_a;
	int		*a;
	int		*b;
	int		*c;
	t_list	*nodo1;
	t_list	*nodo2;
	t_list	*nodo3;
	t_list	*current;

	stack_a = malloc(sizeof(t_stack));
	a = malloc(sizeof(int));
	b = malloc(sizeof(int));
	c = malloc(sizeof(int));
	*a = 2;
	*b = 3;
	*c = 4;
	nodo1 = ft_lstnew(a);
	nodo2 = ft_lstnew(b);
	nodo3 = ft_lstnew(c);
	ft_lstadd_back(&(stack_a->head), nodo1);
	ft_lstadd_back(&(stack_a->head), nodo2);
	ft_lstadd_back(&(stack_a->head), nodo3);
	ft_printf("Antes swap:\n");
	current = stack_a->head;
	while (current != NULL)
	{
		ft_printf("%d\n", *(int *)(current->content));
		current = current->next;
	}
	swap_a(&stack_a);
	ft_printf("Despues swap:\n");
	current = stack_a->head;
	while (current != NULL)
	{
		ft_printf("%d\n", *(int *)(current->content));
		current = current->next;nodo1 = ft_lstnew(a);
	nodo2 = ft_lstnew(b);
	nodo3 = ft_lstnew(c);
	}
}
*/

