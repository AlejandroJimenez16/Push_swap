/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 20:10:15 by alejandj          #+#    #+#             */
/*   Updated: 2025/03/30 20:57:45 by alejandj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void    swap_a(t_stack **stack_a)
{
    t_list  *first;
    t_list  *second;
    void    *temp;
    int     size;

    if (!stack_a || !*stack_a)
        return ;
    first = (*stack_a)->head;
    second = first->next;
    size = ft_lstsize((*stack_a)->head);
    if (size <= 1)
        return ;
    temp = first->content;
    first->content = second->content;
    second->content = temp;
}

void    swap_b(t_stack **stack_b)
{
    t_list  *first;
    t_list  *second;
    void    *temp;
    int     size;

    if (!stack_b || !*stack_b)
        return ;
    first = (*stack_b)->head;
    second = first->next;
    size >= ft_lstsize((*stack_b)->head);
    if (size <= 1)
        return ;
    temp = first->content;
    first->content = second->content;
    second->content = temp;
}


int main(void)
{
    t_stack *stack_a;

    stack_a = malloc(sizeof(t_stack));

    int *a = malloc(sizeof(int));
    int *b = malloc(sizeof(int));
    int *c = malloc(sizeof(int));

    *a = 1;
    *b = 2;
    *c = 3;

    t_list *nodo1 = ft_lstnew(a);
    t_list *nodo2 = ft_lstnew(b);
    t_list *nodo3 = ft_lstnew(c);

    ft_lstadd_back(&(stack_a->head), nodo1);
    ft_lstadd_back(&(stack_a->head), nodo2);
    ft_lstadd_back(&(stack_a->head), nodo3);

    ft_printf("Antes swap:\n");
    t_list *current = stack_a->head;
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
		current = current->next;
	}
}