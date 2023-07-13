/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:03:24 by akent-go          #+#    #+#             */
/*   Updated: 2023/06/06 11:00:20 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	swap(t_slist **lst)
{
	t_slist	*a;
	t_slist	*b;
	int		temp_val;
	int		temp_index;

	if (ft_lstsizes(*lst) < 2)
		return (-1);
	a = *lst;
	b = a->next;
	if (!a && !b)
	{
		ft_putstr_fd("Error\n", 1);
		return (-1);
	}
	temp_val = a->content;
	temp_index = a->index;
	a->content = b->content;
	a->index = b->index;
	b->content = temp_val;
	b->index = temp_index;
	return (0);
}

int	sa(t_slist **lst_a)
{
	if (swap(lst_a) == -1)
		return (-1);
	ft_putstr_fd("sa\n", 1);
	return (0);
}

int	sb(t_slist **lst_b)
{
	if (swap(lst_b) == -1)
		return (-1);
	ft_putstr_fd("sb\n", 1);
	return (0);
}

int	ss(t_slist **lst_a, t_slist **lst_b)
{
	if (ft_lstsizes(*lst_a) < 2 || ft_lstsizes(*lst_b) < 2)
		return (-1);
	swap(lst_a);
	swap(lst_b);
	ft_putstr_fd("Error\n", 1);
	return (0);
}
