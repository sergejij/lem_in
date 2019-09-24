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
	t_sets		*tmp;

	while (lst)
	{
		cur = lst->sets;
		while (cur)
		{
			tmp = cur;
			cur = cur->next;
			free(tmp->set_rooms);
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
	new->len = count_sets_len(nest, cur) + 1;
	if (!(new->set_rooms = ft_memalloc(sizeof(int) * new->len)))
		return (0);
}

void		put_set(t_lst *lst, t_sets *new)
{
	t_sets		*cur;
	t_sets		*tmp;

	cur = lst->sets;
	while (cur && cur->next)
	{
		if (new->len < cur->next->len)
		{
			tmp = cur->next;
			cur->next = new;
			new->next = tmp;
			break ;
		}
		cur = cur->next;
	}
	if (!cur)
		lst->sets = new;
	else
		cur->next = new;
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
