/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:01:01 by hece              #+#    #+#             */
/*   Updated: 2023/01/21 20:01:35 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2)
		swap(stack_a, NULL, "sa", 0);
	else if (stack_size == 3)
		sort_three(stack_a);
	else if (stack_size > 3)
		sort(stack_a, stack_b);
}

static t_stack	*parse_fill_a(int ac, char *av[])
{
	t_stack	*stack_a;
	char	*nums;

	if (ac == 2)
	{
		nums = ft_split(av[1], ' ');
		ac = count_words(av[1], ' ');
		if (!is_valid_input(nums))
			exit_error(NULL, NULL);
		stack_a = fill_stack_a(ac, nums);
		while (--ac >= 0)
			free(nums[ac]);
		free(nums);
	}
	else
	{
		if (!is_valid_input(av + 1))
			exit_error(NULL, NULL);
		stack_a = fill_stack_a(ac - 1, av + 1);
	}
	return (stack_a);
}

int	main(int ac, char *av[])
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			stack_size;

	if (ac < 2)
		return (0);
	stack_a = parse_fill_a(ac, av);
	stack_b = NULL;
	if (is_sorted(stack_a))
		return (0);
	stack_size = get_stack_size(stack_a);
	assign_order(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
