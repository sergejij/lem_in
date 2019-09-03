#include "lem_in.h"


int		ft_find_index_ways(t_map *nest, int first, int second)
{
	int index_ways;

	index_ways = -1;
	while (++index_ways < nest->num_of_ways)
	{
		if (nest->ways[index_ways].room1 == first)
		{
			if (nest->ways[index_ways].room2 == second)
				return (index_ways);
		}
		else if (nest->ways[index_ways].room1 == second)
		{
			if (nest->ways[index_ways].room2 == first)
				return (index_ways);
		}
	}
	return (-1);
}

void 	ft_fill_ways(t_map *nest)
{
	int index_room;
	int index_link;
	int index_ways;

	index_room = -1;
	index_ways = -1;
	while (++index_room < nest->num_of_rooms)
	{
		index_link = -1;
		while (++index_link < nest->rooms[index_room].num_of_links)
		{
			if (nest->rooms[index_room].links[index_link] > index_room &&
			++index_ways < nest->num_of_ways)
			{
				nest->ways[index_ways].room1 = index_room;
				nest->ways[index_ways].room2 = nest->rooms[index_room].links[index_link];
			}
		}
	}
}

int 	ft_count_ways(t_map *nest)
{
	int index;
	int res;
	int index_links;

	index = -1;
	res = 0;
	while (++index < nest->num_of_rooms)
	{
		index_links = -1;
		while (++index_links < nest->rooms[index].num_of_links)
		{
			if (nest->rooms[index].links[index_links] > index)
				res += 1;
		}
	}
	return (res);
}

void 	ft_malloc_and_fill_ways(t_map *nest)
{
	nest->num_of_ways = ft_count_ways(nest);
	if(!(nest->ways = (t_way *)ft_memalloc(sizeof(t_way) * nest->num_of_ways)))
		exit(1);
	ft_fill_ways(nest);
}