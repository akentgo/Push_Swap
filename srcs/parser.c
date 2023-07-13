/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:42:03 by akent-go          #+#    #+#             */
/*   Updated: 2023/06/21 16:47:53 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_nums(char **a, int argc)
{
	int		c[2];

	c[0] = 0;
	c[1] = -1;
	if (argc == 2)
	{
		a = ft_split(a[1], ' ');
		c[0] = -1;
	}
	if (!a[0])
		return (0);
	while (a[++c[0]])
	{
		c[1] = -1;
		while (a[c[0]][++c[1]] != '\0')
		{
			if ((ft_isdigit(a[c[0]][c[1]]) == 0 && a[c[0]][c[1]] != '-') || \
				is_overflow(a[c[0]]) == -1)
				return (0);
		}
	}
	if (argc == 2)
		ft_free(a);
	return (1);
}

int	is_dup(t_slist **lst)
{
	t_slist	*head;
	t_slist	*start;
	int		n;

	head = *lst;
	start = *lst;
	while (head->next)
	{
		n = head->content;
		start = start->next;
		if (n == start->content)
			return (0);
		if (start->next == NULL)
		{
			head = head->next;
			start = head;
		}
	}
	return (1);
}

int	is_overflow(char *n)
{
	long long	temp;

	temp = ft_atoll(n);
	if (temp >= INT_MIN && temp <= INT_MAX)
		return (1);
	return (-1);
}

int	parser(char **argv, t_slist **lst, int argc)
{
	if (check_nums(argv, argc) && is_dup(lst))
		return (1);
	else
	{
		ft_putstr_fd("Error\n", 1);
		exit (0);
	}
}
