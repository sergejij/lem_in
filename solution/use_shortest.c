#include "../lem_in.h"

int *ft_make_arr_rooms(t_map *nest, int i, int j, int start)
{
	int *arr;
	int k;

	k = -1;
	arr = (int*)malloc(sizeof(int) * nest->num_of_rooms);
	while (++j < nest->rooms[start].num_of_links)
	{
		if (nest->ways[ft_find_index_ways(nest, start, nest->rooms[start].links[j])].shortest)
		{
			if ((!nest->rooms[nest->rooms[start].links[j]].looked || start == nest->index_end))
			{
				arr[++k] = start;
				nest->rooms[start].looked = 1;
				start = nest->rooms[start].links[j];
				j = -1;
			}
		}
	}
	while (k < nest->num_of_rooms)
		arr[++k] = -1;
	return (arr);
}

void	ft_use_shortest(t_map *nest)
{
	int i;
	int j;
	int start;
	int num_ant;
	int *arr;

	num_ant = 0;
	i = -1;
	j = -1;
	start = nest->index_start;
	arr = ft_make_arr_rooms(nest, -1, -1, nest->index_start);
	while (++i < nest->num_of_rooms)
	{
		while (++j < nest->rooms[start].num_of_links)
		{
			if (nest->ways[ft_find_index_ways(nest, start, nest->rooms[start].links[j])].shortest)
			{
				printf("L%d-%s ", num_ant++, nest->rooms[start].name);
				start = nest->rooms[start].links[j];
			}
		}
	}
}