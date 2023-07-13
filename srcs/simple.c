/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:12:31 by akent-go          #+#    #+#             */
/*   Updated: 2023/06/21 17:09:28 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3(t_slist **lst_a)
{
	t_slist	*a;
	int		min;
	int		n_min;

	a = *lst_a;
	min = get_min(lst_a, -1);
	n_min = get_min(lst_a, min);
	if (is_ordered(lst_a))
		return ;
	if (a->index == min && a->next->index != n_min)
	{
		sa(lst_a);
		ra(lst_a);
	}
	else if (a->index == n_min && a->next->index == min)
		sa(lst_a);
	else if (a->index == n_min && a->next->index != min)
		rra(lst_a);
	else if ((a->index != min && a->index != n_min) && a->next->index == n_min)
	{
		sa(lst_a);
		rra(lst_a);
	}
	else
		ra(lst_a);
}

void	sort_4(t_slist **lst_a, t_slist **lst_b)
{
	if (get_distance(lst_a, get_min(lst_a, -1)) == 1)
		sa(lst_a);
	else if (get_distance(lst_a, get_min(lst_a, -1)) == 2)
	{
		ra(lst_a);
		ra(lst_a);
	}
	else if (get_distance(lst_a, get_min(lst_a, -1)) == 3)
		rra(lst_a);
	if (is_ordered(lst_a))
		return ;
	pb(lst_a, lst_b);
	sort_3(lst_a);
	pa(lst_a, lst_b);
}

void	sort_5(t_slist **lst_a, t_slist **lst_b)
{
	if (get_distance(lst_a, get_min(lst_a, -1)) == 1)
		sa(lst_a);
	else if (get_distance(lst_a, get_min(lst_a, -1)) == 2)
	{
		ra(lst_a);
		ra(lst_a);
	}
	else if (get_distance(lst_a, get_min(lst_a, -1)) == 3)
	{
		rra(lst_a);
		rra(lst_a);
	}
	else if (get_distance(lst_a, get_min(lst_a, -1)) == 4)
	{
		rra(lst_a);
	}
	if (is_ordered(lst_a))
		return ;
	pb(lst_a, lst_b);
	sort_4(lst_a, lst_b);
	pa(lst_a, lst_b);
}

void	simple(t_slist **a, t_slist **b)
{
	if (is_ordered(a) || ft_lstsizes(*a) == 0 || ft_lstsizes(*a) == 1)
		return ;
	else if (ft_lstsizes(*a) == 2)
		sa(a);
	else if (ft_lstsizes(*a) == 3)
		sort_3(a);
	else if (ft_lstsizes(*a) == 4)
		sort_4(a, b);
	else if (ft_lstsizes(*a) == 5)
		sort_5(a, b);
}
