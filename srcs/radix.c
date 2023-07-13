/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:53:49 by akent-go          #+#    #+#             */
/*   Updated: 2023/06/06 10:57:19 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_max_index(t_slist **lst)
{
	t_slist	*head;
	int		max;

	head = *lst;
	max = head->index;
	while (head->next)
	{
		if (max < head->next->index)
			max = head->next->index;
		head = head->next;
	}
	return (max);
}

int	get_n_bits(t_slist **lst)
{
	int	index;
	int	i;

	i = 10;
	index = get_max_index(lst);
	while (i > 0)
	{
		if ((index >> i & 1) == 0)
			i--;
		else
			break ;
	}
	return (i);
}

void	radix(t_slist **a, t_slist **b)
{
	int	n_bits;
	int	i;
	int	index_ct;
	int	max;

	n_bits = get_n_bits(a);
	max = get_max_index(a);
	i = -1;
	index_ct = 0;
	if (is_ordered(a))
		return ;
	while (++i <= n_bits)
	{
		while (index_ct <= max)
		{
			if (((*a)->index >> i & 1) == 0)
				pb(a, b);
			else if (((*a)->index >> i & 1) == 1)
				ra(a);
			index_ct++;
		}
		while ((*b))
			pa(a, b);
		index_ct = 0;
	}
}
