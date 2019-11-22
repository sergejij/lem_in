/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:49:43 by lshellie          #+#    #+#             */
/*   Updated: 2019/10/07 17:49:44 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int			find_min_weight(t_map *map, int cur)
{
	int		i;
	int		ret;
	t_room	*rooms;

	rooms = map->rooms;
	i = 0;
	ret = -1;
	while (i < rooms[cur].num_of_links)
	{
		if ((ret == -1 || rooms[ret].weight > rooms[rooms[cur].links[i]].weight)
		&& rooms[rooms[cur].links[i]].weight != -1
		&& map->pipes[rooms[cur].links[i] + cur * map->num_of_rooms] == 0)
			ret = rooms[cur].links[i];
		++i;
	}
	return (ret);
}

int			find_way(t_map *map)
{
	int		cur;
	int		i;
	t_room	*room;

	i = -1;
	room = map->rooms;
	if ((cur = find_min_weight(map, map->index_end)) < 0)
		return (0);
	map->pipes[cur + map->index_end * map->num_of_rooms] = -1;
	while (++i < room[cur].num_of_links)
	{
		if (cur == map->index_start)
			return (1);
		if (room[room[cur].links[i]].weight < 0)
			continue ;
		if (room[cur].weight > room[room[cur].links[i]].weight
			&& map->pipes[cur + room[cur].links[i] * map->num_of_rooms] == 0)
		{
			room[cur].sh = map->step;
			map->pipes[room[cur].links[i] + cur * map->num_of_rooms] = -1;
			cur = room[cur].links[i];
			i = -1;
		}
	}
	return (1);
}
