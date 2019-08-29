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

int	ft_found_end(t_map *nest)
{
	int i;

	i = -1;
	while (++i < nest->num_of_rooms)
		if (nest->rooms[i].end)
			return (i);
	return (0);
}

void	ft_find_shortest(t_map *nest, int start, int prev)
{
	int 	cur;
	t_room	*rooms;
	int 	i;

	i = -1;
	rooms = nest->rooms;
	if (prev >= 0)
		rooms[prev].visited = 1;
	cur = start;
	while (++i < rooms[cur].num_of_links)
	{
		if (!rooms[rooms[cur].links[i]].visited && (!rooms[rooms[cur].links[i]].weght || rooms[rooms[cur].links[i]].weght > 1 + rooms[cur].weght))
			rooms[rooms[cur].links[i]].weght = 1 + rooms[cur].weght;
	}
	i = -1;
	while (++i < rooms[cur].num_of_links)
	{
		if (!rooms[rooms[cur].links[i]].visited)
			ft_find_shortest(nest, rooms[cur].links[i], cur);
	}
	rooms[prev].visited = 0;
}

void ft_write_ways(t_map *nest)
{
	int	end;
	int i;
	int cur;
	int j;
	int prev;

	i = -1;
	end = ft_found_end(nest);
	cur = end;
	while (++i <= nest->rooms[end].weght)
	{
		j = -1;
		while (++j < nest->rooms[cur].num_of_links)
		{
			prev = nest->rooms[cur].links[j];
			if (nest->rooms[cur].weght - 1 == nest->rooms[prev].weght)
			{
				nest->ways[ft_find_index_ways(nest, cur, nest->rooms[cur].links[j])].shortest = 1;
				cur = nest->rooms[cur].links[j];
			}
		}

	}
}

void	ft_solution(t_map *nest)
{
	int		start;
	int		less_follow;
	int 	i;

	i = -1;
	start = ft_found_start(nest);
	ft_find_shortest(nest, start, -1);
	ft_write_ways(nest);
}

void main_solution(t_map *nest)
{
	ft_malloc_and_fill__ways(nest);
	ft_solution(nest);
	show_map(nest);
}