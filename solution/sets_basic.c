/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 12:49:06 by lshellie          #+#    #+#             */
/*   Updated: 2019/09/21 12:49:07 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void		free_lst(t_lst *lst)
{
	t_sets		*cur;
	t_lst		*lst_tmp;
	t_nodes		*tmp_nodes;
	t_sets		*tmp;

	while (lst)
	{
		cur = lst->sets;
		while (cur)
		{
			tmp = cur;
			cur = cur->next;
			while (cur->nodes_start)
			{
				tmp_nodes = cur->nodes_start;
				cur->nodes_start = cur->nodes_start->next;
				free(tmp_nodes);
			}
			free(tmp);
		}
		lst_tmp = lst;
		lst = lst->next;
		free(lst_tmp);
	}
}

t_sets		*new_set(t_map *nest, int cur)
{
	t_sets		*new;

	if (!(new = ft_memalloc(sizeof(t_sets))))
		return (0);
	return (new);
}

void		put_set(t_lst *lst, t_sets *new)
{
	t_sets		*cur;
	t_sets		*prev;

	prev = 0;
	if (!lst->sets)
	{
		lst->sets = new;
		return ;
	}
	cur = lst->sets;
	while (cur)
	{
		if (new->len < cur->len)
		{
			new->next = cur;
			if (prev)
				prev->next = new;
			else
				lst->sets = new;
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
}

t_lst		*new_lst(void)
{
	t_lst		*new;

	if (!(new = (t_lst *)ft_memalloc(sizeof(t_lst))))
		return (0);
	return (new);
}

void		set_new_set(t_lst **lst, t_lst *new)
{
	if (!*lst)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}
