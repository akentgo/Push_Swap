/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:39:23 by akent-go          #+#    #+#             */
/*   Updated: 2023/06/22 16:54:19 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_box(char **argv, t_slist **lst, int argc)
{
	int		i;
	char	**arg;
	t_slist	*new;

	i = 0;
	if (argc == 2)
		arg = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		arg = argv;
	}
	while (arg[i])
	{
		new = l_new(ft_atoi(arg[i]));
		ft_lstadd_bak(lst, new);
		i++;
	}
	indexer(lst);
	if (argc == 2)
		ft_free(arg);
}

void	sorter(t_slist **a, t_slist **b)
{
	if (ft_lstsizes(*a) <= 5)
		simple(a, b);
	else
		radix(a, b);
}

int	main(int argc, char **argv)
{
	t_slist	**a;
	t_slist	**b;

	if (argc < 2)
		return (-1);
	a = ((t_slist **)malloc(sizeof(t_slist)));
	b = ((t_slist **)malloc(sizeof(t_slist)));
	init_box(argv, a, argc);
	parser(argv, a, argc);
	if (is_ordered(a))
	{
		free_lst(a);
		free_lst(b);
		return (0);
	}
	sorter(a, b);
	free_lst(a);
	free_lst(b);
	return (0);
}
