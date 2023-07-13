/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:04:48 by akent-go          #+#    #+#             */
/*   Updated: 2023/06/06 10:57:12 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	reverse_rotate(t_slist **lst)
{
	t_slist	*head;
	t_slist	*temp;

	if (ft_lstsizes(*lst) <= 1)
		return (-1);
	head = *lst;
	temp = ft_lstlasts(*lst);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	temp->next = *lst;
	*lst = temp;
	return (0);
}

int	rra(t_slist **lst_a)
{
	if (reverse_rotate(lst_a) == -1)
		return (-1);
	ft_putstr_fd("rra\n", 1);
	return (0);
}

int	rrb(t_slist **lst_b)
{
	if (reverse_rotate(lst_b) == -1)
		return (-1);
	ft_putstr_fd("rrb\n", 1);
	return (0);
}

int	rrr(t_slist **lst_a, t_slist **lst_b)
{
	if (ft_lstsizes(*lst_a) <= 1 || ft_lstsizes(*lst_b) <= 1)
		return (-1);
	rra(lst_a);
	rrb(lst_b);
	ft_putstr_fd("rrr", 1);
	return (0);
}
