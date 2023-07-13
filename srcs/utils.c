/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:45:36 by akent-go          #+#    #+#             */
/*   Updated: 2023/06/22 16:54:30 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lstadd_bak(t_slist **lst, t_slist *new)
{
	t_slist	*temp;

	temp = ft_lstlasts(*lst);
	if (!temp)
		*lst = new;
	else
		temp->next = new;
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	is_ordered(t_slist **lst)
{
	t_slist	*head;
	t_slist	*run;
	int		temp;

	if (!lst)
		return (-1);
	head = *lst;
	run = head;
	if (run->next == NULL)
		return (1);
	while (head->next)
	{
		temp = head->content;
		while (run->next)
		{
			if (temp > run->next->content)
				return (0);
			run = run->next;
		}
		head = head->next;
		run = head;
	}
	return (1);
}

int	get_distance(t_slist **lst, int num)
{
	int		aux;
	t_slist	*head;

	head = *lst;
	aux = 0;
	if (num == (*lst)->index)
		return (0);
	else
	{
		while (head->next)
		{
			if (num == head->index)
				return (aux);
			aux++;
			head = head->next;
		}
	}
	return (aux);
}

int	get_min(t_slist **lst, int num)
{
	int		temp;
	t_slist	*head;

	head = *lst;
	temp = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < temp) && head->index != num)
			temp = head->index;
	}
	return (temp);
}
