#include "includes/push_swap.h"

int	get_pos_num(t_stack *stack, int num)
{
	t_list	*current;
	int		pos;

	pos = 0;
	current = stack->head;
	while (*(int *)(current->content) != num)
	{
		pos++;
		current = current->next;
	}
	return (pos);
}

void	push_b_chunk(t_stack **stack_a, t_stack **stack_b, int chunck_low,
		int chunck_hight)
{
	t_list	*current;
	int		pos;

	current = (*stack_a)->head;
	while (current != NULL)
	{
		if ((*(int *)(current->content) >= chunck_low)
			&& (*(int *)(current->content) <= chunck_hight))
		{
			pos = get_pos_num(*stack_a, *(int *)(current->content));
			if (pos <= ft_lstsize((*stack_a)->head) / 2)
				while (pos-- > 0)
					ra(stack_a);
			else
			{
				while (pos++ < ft_lstsize((*stack_a)->head))
					rra(stack_a);
			}
			pb(stack_b, stack_a);
			current = (*stack_a)->head;
		}
		else
			current = current->next;
	}
}

void	push_max_a(t_stack **stack_a, t_stack **stack_b)
{
	int	pos_max;

	while ((*stack_b)->head)
	{
		pos_max = get_pos_num_max(*stack_b);
		if (pos_max == 0)
			pa(stack_a, stack_b);
		else
		{
			if (pos_max <= ft_lstsize((*stack_b)->head) / 2)
			{
				while (pos_max-- > 0)
					rb(stack_b);
			}
			else
			{
				while (pos_max++ < ft_lstsize((*stack_b)->head))
					rrb(stack_b);
			}
			pa(stack_a, stack_b);
		}
	}
}

int	get_num_chunks(int size)
{
	if (size <= 100)
		return 5;
	else if (size <= 200)
		return 10;
	else if (size <= 300)
		return 15;
	else if (size <= 400)
		return 18;
	else
		return 10;
}

void	get_chunks_limits(int *chunk_low, int *chunk_hight,
		int *arr, int i, int num_chunks, int total_size)
{
	int chunk_size;
	int start_idx;
	int end_idx;

	chunk_size = total_size / num_chunks;
	start_idx = i * chunk_size;

	// El último chunk coge el resto
	if (i == num_chunks - 1)
		end_idx = total_size - 1;
	else
		end_idx = (i + 1) * chunk_size - 1;

	if (start_idx >= total_size)
		start_idx = total_size - 1;
	if (end_idx >= total_size)
		end_idx = total_size - 1;

	*chunk_low = arr[start_idx];
	*chunk_hight = arr[end_idx];

	//ft_printf("Chunk %d: [%d, %d]\n", i, *chunk_low, *chunk_hight);
}

void	sort_heavy(t_stack **stack_a, t_stack **stack_b)
{
	int	chunk_low;
	int	chunk_hight;
	int	*arr;
	int	i;
	int	num_chunks;
	int	total_size;

	i = 0;
	total_size = ft_lstsize((*stack_a)->head);
	num_chunks = get_num_chunks(total_size);

	arr = stack_to_array(*stack_a);
	sort_arr(arr, total_size);

	while (i < num_chunks)
	{
		get_chunks_limits(&chunk_low, &chunk_hight, arr, i, num_chunks, total_size);
		push_b_chunk(stack_a, stack_b, chunk_low, chunk_hight);
		i++;
	}
	free(arr);
	push_max_a(stack_a, stack_b);
}

//segunda

int	get_pos_num(t_stack *stack, int num)
{
	t_list	*current;
	int		pos;

	pos = 0;
	current = stack->head;
	while (*(int *)(current->content) != num)
	{
		pos++;
		current = current->next;
	}
	return (pos);
}

void	push_b_chunk(t_stack **stack_a, t_stack **stack_b, int chunk_low,
		int chunk_high)
{
	t_list	*current;
	int		pos;
	int		chunk_mid;

	chunk_mid = (chunk_low + chunk_high) / 2;
	current = (*stack_a)->head;
	while (current != NULL)
	{
		if (*(int *)(current->content) >= chunk_low && *(int *)(current->content) <= chunk_high)
		{
			pos = get_pos_num(*stack_a, *(int *)(current->content));
			if (pos <= ft_lstsize((*stack_a)->head) / 2)
				while (pos-- > 0)
					ra(stack_a);
			else
				while (pos++ < ft_lstsize((*stack_a)->head))
					rra(stack_a);
			pb(stack_b, stack_a);
			if (*(int *)(current->content) < chunk_mid)
				rb(stack_b);
			break ;
		}
		else
			current = current->next;
	}
}

void	push_max_a(t_stack **stack_a, t_stack **stack_b)
{
	int	pos_max;

	while ((*stack_b)->head)
	{
		pos_max = get_pos_num_max(*stack_b);
		if (pos_max == 0)
			pa(stack_a, stack_b);
		else
		{
			if (pos_max <= ft_lstsize((*stack_b)->head) / 2)
			{
				while (pos_max-- > 0)
					rb(stack_b);
			}
			else
			{
				while (pos_max++ < ft_lstsize((*stack_b)->head))
					rrb(stack_b);
			}
			pa(stack_a, stack_b);
		}
	}
}

int	count_in_chunk(t_stack *stack, int low, int high)
{
	t_list	*current = stack->head;
	int		count = 0;
	int		num;

	while (current)
	{
		num = *(int *)(current->content);
		if (num >= low && num <= high)
			count++;
		current = current->next;
	}
	return (count);
}


void	sort_heavy(t_stack **stack_a, t_stack **stack_b)
{
	int	*arr;
	int	chunk_low;
	int	chunk_high;
	int	size;
	int	i;
	int	num_chunks;

	size = ft_lstsize((*stack_a)->head);
	if (size < 100)
		num_chunks = 5;
	else if (size < 500)
		num_chunks = 10;
	else
		num_chunks = 20;

	arr = stack_to_array(*stack_a);
	sort_arr(arr, size);
	i = 0;
	while (ft_lstsize((*stack_a)->head) > 0)
	{
		int start = i * (size / num_chunks);
		int end = (i == num_chunks - 1) ? size - 1 : ((i + 1) * (size / num_chunks)) - 1;
		chunk_low = arr[start];
		chunk_high = arr[end];

		int chunk_count = count_in_chunk(*stack_a, chunk_low, chunk_high);
		push_b_chunk(stack_a, stack_b, chunk_low, chunk_high);
		if (chunk_count == 0)
			i++;
	}

	free(arr);

	push_max_a(stack_a, stack_b);
}