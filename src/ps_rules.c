/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandj <alejandj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 20:10:15 by alejandj          #+#    #+#             */
/*   Updated: 2025/04/06 18:52:12 by alejandj         ###   ########.fr       */
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

	if (!stack || !*stack)
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

/*
Takes the first element from stack and puts it first in the oder stack 
*/
void    push(t_stack **stack_a, t_stack **stack_b)
{
    t_list  *node;

    if (!stack_a || !stack_b)
        return ;
    if ((*stack_b)->head == NULL)
        return ;
    if ((*stack_a)->head == NULL)
        return ;
    node = (*stack_b)->head;
    (*stack_b)->head = node->next;
    node->next = (*stack_a)->head;
    (*stack_a)->head = node;
}

/*
Move all elements in stack up one position, so that the first element become the last

[ [1] [5] [8] ] --> [ [5] [8] [1] ]

*/
void    rotate(t_stack **stack)
{
     t_list *first;
    
    if (!stack || !(*stack) || !(*stack)->head)
        return ;
    first =  (*stack)->head;
    (*stack)->head = first->next;
    first->next = NULL;
    ft_lstadd_back(&(*stack)->head, first);
}

/*
Move all elements in stack down one position, so that the first element become the last

[ [1] [5] [8] ] --> [ [8] [1] [5] ]

*/
void    reverse_rotate(t_stack **stack)
{
    
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
		current = current->next;
	}
}
*/

//  ===========
// || Push test ||
//  ===========

/*
int	main(void)
{
    t_stack *stack_a = malloc(sizeof(t_stack));
	t_stack	*stack_b = malloc(sizeof(t_stack));
    
    //Values a
    int *a1 = malloc(sizeof(int));
    int *a2 = malloc(sizeof(int));
    int *a3 = malloc(sizeof(int));
    
    *a1 = 2;
    *a2 = 3;
    *a3 = 4;
    
    //Values b
    int *b1 = malloc(sizeof(int));
    int *b2 = malloc(sizeof(int));
    int *b3 = malloc(sizeof(int));

    *b1 = 6;
    *b2 = 5;
    *b3 = 10;

    //Nodes a
    t_list *n1a = ft_lstnew(a1);
    t_list *n2a = ft_lstnew(a2);
    t_list *n3a = ft_lstnew(a3);

    //Nodes b
    t_list *n1b = ft_lstnew(b1);
    t_list *n2b = ft_lstnew(b2);
    t_list *n3b = ft_lstnew(b3);

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
    
    t_list *current_a;
    current_a = stack_a->head;
    while (current_a != NULL)
    {
        ft_printf("%d\n", *(int *)(current_a->content));
        current_a = current_a->next;
    }
    
    ft_printf("Stack b\n");
    
    t_list *current_b;
    current_b = stack_b->head;
    while (current_b != NULL)
    {
        ft_printf("%d\n", *(int *)(current_b->content));
        current_b = current_b->next;
    }
    
    ft_printf("After push\n");
    
    push(&stack_a, &stack_b);

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

//  ==============
// || Rotate test ||
//  ==============

/*
int main(void)
{
    t_stack *stack = malloc(sizeof(t_stack));

    int *n1 = malloc(sizeof(int));
    int *n2 = malloc(sizeof(int));
    int *n3 = malloc(sizeof(int));
    int *n4 = malloc(sizeof(int));

    *n1 = 5;
    *n2 = 2;
    *n3 = 8;
    *n4 = 1;

    t_list *node1 = ft_lstnew(n1);
    t_list *node2 = ft_lstnew(n2);
    t_list *node3 = ft_lstnew(n3);
    t_list *node4 = ft_lstnew(n4);

    ft_lstadd_back(&(stack->head), node1);
    ft_lstadd_back(&(stack->head), node2);
    ft_lstadd_back(&(stack->head), node3);
    ft_lstadd_back(&(stack->head), node4);

    ft_printf("Before rotate\n");

    t_list *current = stack->head;
    while(current != NULL)
    {
        ft_printf("%d\n", *(int *)(current->content));
        current = current->next;
    }
    
    ft_printf("After rotate\n");

    rotate(&stack);

    int size = ft_lstsize(stack->head);

    current = stack->head;
    while(current != NULL)
    {
        ft_printf("%d\n", *(int *)(current->content));
        current = current->next;
    }
    ft_printf("Size : %d\n", size);
}
*/
