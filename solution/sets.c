#include "../lem_in.h"

int ft_pathlen(t_map *nest, int count_path, int i)
{
	int res;

	res = 0;
	while (++i < nest->num_of_rooms)
	{
		if (nest->rooms[i].sh == count_path)
			res += 1;
	}
	return (res);
}

void ft_record_sets(t_map *nest, int count_path, int i)
{
	int start;
	int j;

	j = 0;
	nest->sets[count_path].len_path = ft_pathlen(nest,  count_path, -1);
	printf("\t$$$    %d    $$$\n", nest->sets->len_path);
	nest->sets[count_path].v[2] = (int*)malloc(sizeof(int) * nest->sets->len_path);
	start = nest->index_start;
	while (++i < nest->rooms[start].num_of_links)
	{
		if (nest->rooms[nest->rooms[start].links[i]].sh == count_path)
		{
			nest->sets[count_path].v[0][j++] = start;
			start = nest->rooms[start].links[i];
			i = -1;
		}
	}
}