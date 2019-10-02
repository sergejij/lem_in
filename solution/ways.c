 #include "../lem_in.h"

void	ft_record_ways(t_map *nest,	int j,	int i, int end)
{
	int cur;
	int prev;

	cur = end;
	//nest->sh_path = (int*)malloc(sizeof(int) * nest->num_of_rooms);
	while (++i <= nest->rooms[end].weght)
	{
		j = -1;
		while (++j < nest->rooms[cur].num_of_links)
		{
			prev = nest->rooms[cur].links[j];
			if (nest->rooms[cur].weght - 1 == nest->rooms[prev].weght)
			{
				nest->rooms[cur].forb_new_way = 1; // первая вершина вайза
				nest->rooms[nest->rooms[cur].links[j]].forb_new_way = 1; // вторая
				nest->rooms[cur].sh = 1; // первая вершина вайза
				nest->rooms[nest->rooms[cur].links[j]].sh = 1; // вторая
				/**(nest->sh_path)++ =  cur;
				*(nest->sh_path)++ =  nest->rooms[cur].links[j];*/
				nest->ways[ft_find_index_ways(nest, cur,
											  nest->rooms[cur].links[j])].shortest = 1;
				cur = nest->rooms[cur].links[j];
				j = -1;
			}
		}
	}
}

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
	if(!(nest->ways = ft_memalloc(sizeof(t_way) * nest->num_of_ways)))
		exit(1);
	ft_fill_ways(nest);
}