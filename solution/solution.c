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
		nest->rooms[(nest->rooms[current].links[i])].weght++;
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

void main_solution(t_map *nest)
{
	ft_malloc_and_fill__ways(nest);
	ft_solution(nest);
}