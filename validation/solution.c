#include "lem_in.h"


int	ft_found_start(t_map *nest)
{
	int i;

	i = -1;
	while (++i < nest->num_of_rooms)
		if (nest->rooms[i].start)
			return (i);
	return (0);
}


int ft_room_less_weght(t_map *nest)
{
	int i;
	int less;
	int index;

	index = 0;
	less = 214792993;
	i = 0;
	while (i < nest->rooms->num_of_links)
	{
		if (!nest->rooms->visited && nest->rooms[i].weght < less)
		{
			less = nest->rooms[i].weght;
			index = i;
		}
		i++;
	}
	return (index);
}

void ft_check_next_rooms(t_map *nest, int current)
{
	int i;

	i = 0;
	while (i < nest->rooms[current].num_of_links)
	{
		nest->rooms[(nest->rooms[current].links[i])].weght++;;
		i++;
	}
	nest->rooms[current].visited = 1;
}

void	ft_solution(t_map *nest)
{
	// need to find start
	int		start;
	int 	i;
	int 	j;
	int		current;

	j = -1;
	i = -1;
	start = ft_found_start(nest);
	while (++j < nest->num_of_rooms)
	{ // идем по каждой комнате
		current = ft_room_less_weght(nest); // текущий элемент (наименьший пов весу)
		ft_check_next_rooms(nest, current);
	}
	//name connect map->rooms[map->rooms[i].links[j]].name
}

int ft_count_ways(t_map *nest)
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

void ft_malloc_ways(t_map *nest)
{
	int num_ways;

	num_ways = ft_count_ways(nest);
	(t_way *)ft_memalloc(sizeof(t_way) * num_ways);
	// еще в него надо выделить память в линкс и как-то туда записывать значения
}

void main_solution(t_map *nest)
{
	ft_malloc_ways(nest);
	ft_solution(nest);
}