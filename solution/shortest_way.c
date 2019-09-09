#include "../lem_in.h"

void 	ft_initialization_weight(t_map *nest)
{
	int i;

	i = -1;
	while (++i < nest->num_of_rooms)
	{
		if (nest->rooms[i].start)
			continue;
		else if (!nest->rooms[i].forbbiden)
			nest->rooms[i].weght = 2147483640;
	}
}

int		ft_room_less_weight(t_map *nest, int index, int i)
{
	int cur_weight;
	int less;

	less = 2147483645;
	while (++i < nest->num_of_rooms)
	{
		cur_weight =  nest->rooms[i].weght;
		if (!nest->rooms[i].forbbiden && (nest->rooms[i].open ||
		nest->rooms[i].start) && cur_weight < less)
		{
			if (nest->rooms[i].start)
				nest->rooms[i].forbbiden = 1;
			less = cur_weight;
			index = i;
		}
	}
	return (index);
}

int	ft_check_next_rooms(t_map *nest, int current)
{
	int i;
	int tmp;

	i = -1;
	while (++i < nest->rooms[current].num_of_links)
	{
		if (nest->rooms[nest->rooms[current].links[i]].forb_new_way)
			return (nest->rooms[current].links[i]); // тут выходит при поиске второго пути
		if (nest->rooms[nest->rooms[current].links[i]].forbbiden)
			continue ;
		tmp = nest->rooms[current].weght + 1;
		if (tmp < nest->rooms[(nest->rooms[current].links[i])].weght)
			nest->rooms[(nest->rooms[current].links[i])].weght = tmp;
		nest->rooms[nest->rooms[current].links[i]].open = 1;
	}
	nest->rooms[current].forbbiden = 1;
	return (-1);
}

int	ft_find_shortest(t_map *nest, int i)
{
	int less_next;
	int index_forb;

	ft_initialization_weight(nest);
	while (++i < nest->num_of_rooms)
	{
		if (nest->rooms[i].end)
			nest->index_end = i;
		if ((less_next = ft_room_less_weight(nest, -1, -1)) == -1)
			exit (-2);
		if ((index_forb = ft_check_next_rooms(nest, less_next)) != -1)
			return (index_forb);
	}
	if (!nest->rooms[nest->index_end].weght)
		exit (-1);  // наверное надо тсначала нормально чистить
	return (-1);
}