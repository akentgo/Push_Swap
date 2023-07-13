/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:41:27 by akent-go          #+#    #+#             */
/*   Updated: 2023/06/06 10:57:38 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rotate(t_slist **lst)
{
	t_slist	*head;

	if (ft_lstsizes(*lst) <= 1)
		return (-1);
	head = *lst;
	*lst = (*lst)->next;
	head->next = NULL;
	ft_lstadd_bak(lst, head);
	return (0);
}

int	ra(t_slist **lst)
{
	if (rotate(lst) == -1)
		return (-1);
	ft_putstr_fd("ra\n", 1);
	return (0);
}

int	rb(t_slist **lst)
{
	if (rotate(lst) == -1)
		return (-1);
	ft_putstr_fd("rb\n", 1);
	return (0);
}

int	rr(t_slist **lst_a, t_slist **lst_b)
{
	if (ft_lstsizes(*lst_a) <= 1 || ft_lstsizes(*lst_b) <= 1)
		return (-1);
	ra(lst_a);
	rb(lst_b);
	ft_putstr_fd("rr", 1);
	return (0);
}
