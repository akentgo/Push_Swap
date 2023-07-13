/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akent-go <akent-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:23:22 by akent-go          #+#    #+#             */
/*   Updated: 2023/06/06 11:07:37 by akent-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "limits.h"
# include <stdio.h>

typedef struct t_slist
{
	int				content;
	int				index;
	struct t_slist	*next;
}	t_slist;

void	init_box(char **argv, t_slist **lst, int argc);
void	sorter(t_slist **a, t_slist **b);
int		check_nums(char **argv, int argc);
int		is_dup(t_slist **lst);
int		is_overflow(char *n);
int		parser(char **argv, t_slist **lst, int argc);
void	sort_3(t_slist **a);
void	sort_4(t_slist **a, t_slist **b);
void	sort_5(t_slist **a, t_slist **b);
void	simple(t_slist **a, t_slist **b);
int		get_max_index(t_slist **lst);
int		get_n_bits(t_slist **lst);
void	radix(t_slist **a, t_slist **b);
t_slist	*get_next_min(t_slist **list);
void	indexer(t_slist **stack);
int		swap(t_slist **lst);
int		sa(t_slist **lst_a);
int		sb(t_slist **lst_b);
int		ss(t_slist **lst_a, t_slist **lst_b);
int		push(t_slist **sender, t_slist **recepient);
int		pa(t_slist **lst_a, t_slist **lst_b);
int		pb(t_slist **lst_a, t_slist **lst_b);
int		reverse_rotate(t_slist **lst);
int		rra(t_slist **lst_a);
int		rrb(t_slist **lst_b);
int		rrr(t_slist **lst_a, t_slist **lst_b);
int		rotate(t_slist **lst);
int		ra(t_slist **lst);
int		rb(t_slist **lst);
int		rr(t_slist **lst_a, t_slist **lst_b);
t_slist	*l_new(int val);
t_slist	*ft_lstn(int content);
t_slist	*ft_lstlasts(t_slist *lst);
int		ft_lstsizes(t_slist *lst);
void	free_lst(t_slist **a);
void	ft_lstadd_bak(t_slist **lst, t_slist *new);
void	ft_free(char **str);
int		is_ordered(t_slist **lst);
int		get_distance(t_slist **lst, int num);
int		get_min(t_slist **lst, int num);

#endif