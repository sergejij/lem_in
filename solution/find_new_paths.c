#include "../lem_in.h"

void ft_clear_piece_of_path(t_map *nest, int point_inters, int start, int i)
{
	while (++i < nest->rooms[start].num_of_links)
	{
		if (nest->rooms[nest->rooms[start].links[i]].weght == nest->rooms[start].weght + 1 &&
		(!nest->rooms[nest->rooms[start].links[i]].forb_new_way || nest->rooms[nest->rooms[start].links[i]].invisib)
		&& !nest->rooms[nest->rooms[start].links[i]].hide)
		{
			nest->rooms[start].sh = 0;
			nest->rooms[nest->rooms[start].links[i]].sh = 0;
			nest->ways[ft_find_index_ways(nest, start, nest->rooms[start].links[i])].shortest = 0; // удаляем трубку
			start = nest->rooms[start].links[i];
			i = -1;
		}
	}
}

void    ft_delete_sh(t_map *nest, int count_path, int i)
{
    while (++i < nest->num_of_rooms)
    {
        if (nest->rooms[i].sh == count_path)
            nest->rooms[i].sh = 0;
    }
}

int     ft_link_start(t_map *nest, int count_path, int start, int i)
{
    while (++i < nest->rooms[start].num_of_links)
    {
        if (nest->rooms[nest->rooms[start].links[i]].sh == count_path)
            return (1);
    }
    return (0);
}

int     ft_link_end(t_map *nest, int count_path, int end, int i)
{
    while (++i < nest->rooms[end].num_of_links)
    {
        if (nest->rooms[nest->rooms[end].links[i]].sh == count_path)
            return (1);
    }
    return (0);
}

void    ft_delete_garbage(t_map *nest, int count_path, int i, int j)
{
    if (ft_link_start(nest, count_path, nest->index_start, -1) && ft_link_end(nest, count_path, nest->index_end, -1))
        return;
    ft_delete_sh(nest, count_path, -1);
    /*while (++i < nest->rooms[nest->index_start].num_of_links)
    {
        if (nest->rooms[i].sh == count_path)
        {
            while (++j < nest->rooms[i].num_of_links)
            {
                if (nest->rooms[nest->rooms[i].links[j]].sh == count_path)
                    break;
                if (j + 1 == nest->rooms[i].num_of_links)
                    ft_delete_sh(nest, count_path, -1);
            }
        }
    }*/
}

int 	ft_find_new_path(t_map *nest, int i, int start, int *count_path)
{
	int tmp;
    int prev;

    prev = start;
	tmp = start;
	while (++i < nest->rooms[start].num_of_links)
	{
		if ((nest->rooms[nest->rooms[start].links[i]].weght == nest->rooms[start].weght + 1) &&
				(!nest->rooms[nest->rooms[start].links[i]].forb_new_way || nest->rooms[nest->rooms[start].links[i]].invisib)
				&& !nest->rooms[nest->rooms[start].links[i]].sh && !nest->rooms[nest->rooms[start].links[i]].hide
				&& !nest->rooms[nest->rooms[start].links[i]].end)
		{
			nest->ways[ft_find_index_ways(nest, start, nest->rooms[start].links[i])].shortest = *count_path; // сохраняем трубку, но если встретим пересечение надо либо удалять либо потом начинать отсюда
			if (!nest->rooms[start].start)
				nest->rooms[start].sh = *count_path;
			if (!nest->rooms[nest->rooms[start].links[i]].end)
				nest->rooms[nest->rooms[start].links[i]].sh = *count_path;
            prev = start;
			start = nest->rooms[start].links[i];
			i = -1;
		}
		else if (nest->rooms[nest->rooms[start].links[i]].end && nest->rooms[prev].sh > 1)
		{
/*			(*count_path)++;*/
            //ft_delete_garbage(nest, *count_path, -1, -1);
			return (-1);
		}
		else if (nest->rooms[nest->rooms[start].links[i]].weght != nest->rooms[start].weght + 1 &&
                nest->rooms[nest->rooms[start].links[i]].forb_new_way &&
				 !nest->rooms[nest->rooms[start].links[i]].invisib && !nest->rooms[nest->rooms[start].links[i]].start)
		{
			ft_clear_piece_of_path(nest, nest->rooms[start].links[i], tmp, -1);
			if (nest->rooms[tmp].num_of_links > *count_path)
			{
			    start = tmp;
                continue;
            }
            //ft_delete_garbage(nest, *count_path, -1, -1);
			return (nest->rooms[start].links[i]);
		}
	}
	ft_delete_garbage(nest, *count_path, -1, -1);
	return (-1);
}

void ft_remove_weight(t_map *nest, int i)
{
	while (++i < nest->num_of_rooms)
	{
		nest->rooms[i].weght = 0;
		nest->rooms[i].sh = 0;
		nest->rooms[i].forb_new_way = 0;
		nest->rooms[i].forbbiden = 0;
	}
}

void	ft_find_new_paths(t_map *nest, int count_path) // если количество путей 1, надо искать 2 и тд
{
	int index_forb;
	int i;

	i = -1;
	while ((index_forb = ft_find_new_path(nest, -1, nest->index_start, &count_path)) != -1)
	{
		find_sets(nest);
        //ft_show_sets(nest);
		ft_line_breaker(nest, index_forb);
		ft_remove_weight(nest, -1);
		ft_find_shortest(nest, -1);
	}
    find_sets(nest);
	if (nest->rooms[nest->index_start].num_of_links + 5 >= count_path
		&& nest->rooms[nest->index_end].num_of_links + 5 >= count_path)
		ft_find_new_paths(nest, count_path + 1);
	else
		find_sets(nest);
}