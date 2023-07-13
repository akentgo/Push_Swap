/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:56:47 by akent-go          #+#    #+#             */
/*   Updated: 2023/06/06 10:57:04 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	push(t_slist **sender, t_slist **recepient)
{
	t_slist	*temp;

	temp = *sender;
	if (!sender)
		return (-1);
	*sender = (*sender)->next;
	temp->next = *recepient;
	*recepient = temp;
	return (0);
}

int	pa(t_slist **lst_a, t_slist **lst_b)
{
	if (push(lst_b, lst_a) == -1)
		return (-1);
	ft_putstr_fd("pa\n", 1);
	return (0);
}

int	pb(t_slist **lst_a, t_slist **lst_b)
{
	if (push(lst_a, lst_b) == -1)
		return (-1);
	ft_putstr_fd("pb\n", 1);
	return (0);
}
