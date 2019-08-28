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


int ft_room_less_weght(t_map *nest, int current)
{
	int i;
	int less;
	int index;
	int cur_weght;

	index = 0;
	less = 214792993;
	i = -1;
	while (++i < nest->rooms[current].num_of_links)
	{
		cur_weght =  nest->rooms[nest->rooms[current].links[i]].weght;
		if (!nest->rooms[current].visited && cur_weght < less
		&& (cur_weght != 0 /*|| nest->rooms[current].start*/))
		{
			less = cur_weght;
			index = i;
		}
	}
	return (index);
}

void ft_check_next_rooms(t_map *nest, int current)
{
	int i;

	i = -1;
	while (++i < nest->rooms[current].num_of_links)
		nest->rooms[(nest->rooms[current].links[i])].weght++;
	nest->rooms[current].visited = 1;
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

void	ft_solution(t_map *nest)
{
	// need to find start
	int		current;
	int		less_follow;
	int 	i;

	i = -1;
	current = ft_found_start(nest);
	ft_find_shortest(nest, current, -1);
//	while (++i < nest->num_of_rooms)
//	{ // идем по каждой комнате начиная со старта
//		less_follow = ft_room_less_weght(nest, current); // текущий элемент (наименьший по весу)
//		ft_check_next_rooms(nest, less_follow);
//		current = less_follow;
//	}
	//name connect map->rooms[map->rooms[i].links[j]].name
}

void main_solution(t_map *nest)
{
	ft_malloc_and_fill__ways(nest);
	ft_solution(nest);
	show_map(nest);
}