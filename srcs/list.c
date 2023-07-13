/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:41:57 by akent-go          #+#    #+#             */
/*   Updated: 2023/06/06 10:55:24 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_slist	*l_new(int val)
{
	t_slist	*new;

	new = ft_lstn(val);
	new->index = -1;
	return (new);
}

t_slist	*ft_lstn(int content)
{
	t_slist	*sol;

	sol = malloc(sizeof(t_slist));
	if (!sol)
		return (0);
	sol->content = content;
	sol->next = 0;
	return (sol);
}

t_slist	*ft_lstlasts(t_slist *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_lstsizes(t_slist *lst)
{
	int	sol;

	sol = 0;
	while (lst)
	{
		lst = lst->next;
		sol++;
	}
	return (sol);
}

void	free_lst(t_slist **a)
{
	t_slist	*head;
	t_slist	*temp;

	head = *a;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	free(a);
}
