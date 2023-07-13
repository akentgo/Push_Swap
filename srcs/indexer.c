/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:37:17 by akent-go          #+#    #+#             */
/*   Updated: 2023/06/13 16:47:02 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_slist	*get_next_min(t_slist **list)
{
	t_slist	*head;
	t_slist	*lst;
	int		has_min;

	lst = NULL;
	has_min = 0;
	head = *list;
	if (head)
	{
		while (head)
		{
			if ((head->index) == -1 && (has_min == 0 || \
				head->content < lst->content))
			{
				lst = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (lst);
}

void	indexer(t_slist **stack)
{
	int		min;
	t_slist	*lst;

	min = 0;
	lst = get_next_min(stack);
	while (lst)
	{
		lst->index = min++;
		lst = get_next_min(stack);
	}
}
