/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:40:15 by lshellie          #+#    #+#             */
/*   Updated: 2019/09/21 14:40:17 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void		ft_show_sets(t_map *nest)
{
	t_lst		*cur_lst;
	t_sets		*cur_set;
	int 		i;

	cur_lst = nest->sets;
	while (cur_lst)
	{
		cur_set = cur_lst->sets;
		while (cur_set)
		{
			i = -1;
			while (++i < cur_set->len)
				printf("%d ", cur_set->set_rooms[i]);
			cur_set = cur_set->next;
			printf("\n");
		}
		cur_lst = cur_lst->next;
	}
}

int 		count_sets_len(t_map *nest, int cur)
{
	int 	i;
	int 	len;

	len = 0;
	i = -1;
	while (++i < nest->rooms[cur].num_of_links)
	{
		if (nest->rooms[nest->rooms[cur].links[i]].sh == nest->rooms[cur].sh &&
				nest->rooms[nest->rooms[cur].links[i]].weght == nest->rooms[cur].weght + 1)
		{
			cur = nest->rooms[cur].links[i];
			i = -1;
			++len;
		}
	}
	return (len);
}

int			make_set(t_map *nest, t_lst *lst, int cur)
{
	int 	i;
	int 	j;
	t_sets	*new;

	j = 0;
	if (!(new = new_set(nest, cur)))
		return (0);
	/*if (!(new->set_rooms = ft_memalloc(sizeof(int) * new->len)))
		return (0);*/
	i = -1;
	while (++i < nest->rooms[cur].num_of_links)
	{
		if ((nest->rooms[nest->rooms[cur].links[i]].sh == nest->rooms[cur].sh
		|| nest->rooms[cur].links[i] == nest->index_end)
		&& nest->rooms[nest->rooms[cur].links[i]].weght == nest->rooms[cur].weght + 1)
		{
			new->set_rooms[j++] = cur;
			cur = nest->rooms[cur].links[i];
			i = -1;
		}
	}
	put_set(lst, new);
	return (1);
}

void 		find_sets(t_map *nest)
{
	int 	cur;
	int 	i;
	t_lst	*new;

	cur = nest->index_start;
	i = -1;
	while (++i < nest->rooms[cur].num_of_links)
	{
		if (nest->rooms[nest->rooms[cur].links[i]].sh != 0)
		{
			if (!(new = new_lst()))
				return ;
			set_new_set(&nest->sets, new);
			make_set(nest, new, nest->rooms[cur].links[i]);
		}
	}
}