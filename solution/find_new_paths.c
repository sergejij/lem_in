#include "../lem_in.h"

int ft_find_intersections(t_map *nest, int index_forb, int i, int j)
{
	// у меня есть одна вершина, я подаю еЁ и еЁ связь в функцию, которая выдает индекс пути
	// тут же проверяю является ли это ребро запрещенным
	// если ((текущая запрещенная вершина - 1) == вершине) по связи и он форбиден,
	// значит это путь к старту, ищу пересечение
	// в таком же стиле иду до старта, но если встречаю вершину с более чем двумя связями, возвращяю её
	t_room *room;

	room = nest->rooms;
	while (++i < room[nest->index_end].weght)
	{
		while (++j < room[index_forb].num_of_links)
		{
			if (room[room[index_forb].links[j]].forb_new_way &&
				((room[index_forb].weght - 1) == room[room[index_forb].links[j]].weght)  &&
				(!nest->ways[ft_find_index_ways(nest, index_forb, room[index_forb].links[j])].invisible)) // не является ли связь в пересечении невидимой
			{
				index_forb = room[index_forb].links[j];
				j = 0;
			}
			if (room[room[index_forb].links[j]].forb_new_way &&
				room[index_forb].num_of_links > 2)
				return (index_forb);
		}
	}
	return (-1);
}

void ft_delete_ways(t_map *nest, int start, int end, int i)
{
	// 1. иду по связи старта, по форбиден
	// 2. отмечаю эту трубку как невидимую (или прям удалять?)
	// 3. перехожу на след и так до енд
	int j;
	t_room *room;
	int index_way;

	room = nest->rooms;
	j = -1;
	while (++i < room[start].num_of_links && start != end)
	{
		if (room[room[start].links[i]].forb_new_way &&
			(room[start].weght + 1) == room[room[start].links[i]].weght)
		{
			nest->rooms[start].invisib = 1;
			nest->rooms[room[start].links[i]].invisib = 1;
			nest->rooms[end].forb_new_way = 0;
			index_way = ft_find_index_ways(nest, start, room[start].links[i]);
			nest->ways[index_way].invisible = 1;
			start = room[start].links[i];
			i = -1;
		}
	}
}

void 	ft_line_breaker(t_map *nest, int index_forb)
{ // ф-я удаляет линию без пересечений, до пересечения
	int index_intersections;
	int i;

	i = -1;
	// если нет пересечений до старта, а только линия, мы не трогаем
	// то есть сначала имеет смысл проверить есть ли пересечения до старта
	// если да, получить этот индекс
	if ((index_intersections = ft_find_intersections(nest, index_forb, -1, -1)) == - 1)
	{
		// нет пересечений, значит надо удалить ту линию по которой мы пришли к форбиден вершине
		// просто вычитанием веса я могу получить нужную вершину, так как
		// при запуске ft_find_shortest я обнулил вершины и заного отметил один (другой путь)

		// надо сделать невидимой линию до пересечения(своего пересечения, просто иди пока не будет более 2-х связей)
		// если его нет, то
		while (++i < nest->rooms[index_forb].num_of_links)
		{
			if ((nest->rooms[index_forb].weght - 1) == nest->rooms[nest->rooms[index_forb].links[i]].weght)
			{
				index_intersections = nest->rooms[index_forb].links[i];
				if (nest->rooms[index_forb].num_of_links > 2)
					ft_delete_ways(nest, index_intersections, index_forb, -1);
			}
			else
				break;
		}
		return ;
	}
	// иначе у меня есть пересечение и мне нужно удалить от пересечения до индекс_форб
	ft_delete_ways(nest, index_intersections, index_forb, -1);
}

void ft_clear_paice_of_path(t_map *nest, int point_inters, int start, int i)
{
	while (++i < nest->rooms[start].num_of_links)
	{
		if (nest->rooms[nest->rooms[start].links[i]].weght == nest->rooms[start].weght + 1 &&
		(!nest->rooms[nest->rooms[start].links[i]].forb_new_way || nest->rooms[nest->rooms[start].links[i]].invisib))
		{
			nest->rooms[start].sh = 0;
			nest->rooms[nest->rooms[start].links[i]].sh = 0;
			nest->ways[ft_find_index_ways(nest, start, nest->rooms[start].links[i])].shortest = 0; // удаляем трубку
			start = nest->rooms[start].links[i];
			i = -1;
		}
	}
}

int 	ft_find_new_path(t_map *nest, int i, int start, int *count_path)
{
	int tmp;

	tmp = start;
	while (++i < nest->rooms[start].num_of_links)
	{
		if ((nest->rooms[nest->rooms[start].links[i]].weght == nest->rooms[start].weght + 1 /*|| nest->rooms[nest->rooms[start].links[i]].invisib*/) &&
				(!nest->rooms[nest->rooms[start].links[i]].forb_new_way || nest->rooms[nest->rooms[start].links[i]].invisib)
				&& !nest->rooms[nest->rooms[start].links[i]].sh) // косяк с условием прыгает на way[2] - 1-4
		{
			nest->ways[ft_find_index_ways(nest, start, nest->rooms[start].links[i])].shortest = *count_path; // сохраняем трубку, но если встретим пересечение надо либо удалять либо потом начинать отсюда
			if (!nest->rooms[start].start)
				nest->rooms[start].sh = *count_path;
			if (!nest->rooms[nest->rooms[start].links[i]].end)
				nest->rooms[nest->rooms[start].links[i]].sh = *count_path;
			start = nest->rooms[start].links[i];
			i = -1;
		}
		else if (nest->rooms[nest->rooms[start].links[i]].end)
		{
			(*count_path)++;
			return (-1);
			// нужно сохранить этот путь
			// мы не нашли пересечения с форб, а нашли новый путь
		}
		else if (nest->rooms[nest->rooms[start].links[i]].weght != nest->rooms[start].weght + 1 &&
				 nest->rooms[nest->rooms[start].links[i]].forb_new_way &&
				 !nest->rooms[nest->rooms[start].links[i]].invisib && !nest->rooms[nest->rooms[start].links[i]].start)
		{
			// надо записывать сразу путь
			// а если оказался тут надо его очистить
		/*	nest*/
			ft_clear_paice_of_path(nest, nest->rooms[start].links[i], tmp, -1);
			return (nest->rooms[start].links[i]);
		}
	}
	return (-1);
}

void ft_remove_weight(t_map *nest, int i)
{
	while (++i <= nest->num_of_rooms)
	{
		nest->rooms[i].weght = 0;
		nest->rooms[i].forb_new_way = 0;
		nest->rooms[i].forbbiden = 0;
	}
}

void	ft_find_new_paths(t_map *nest, int count_path) // если количество путей 1, надо искать 2 и тд
{
	int index_forb;
	/*int i;

	i = -1;
	while (++i < nest->num_of_ways)
	{
		if (nest->ways[i].shortest)
			nest->ways[i].forbbiden;
	} попробую без доп флага, там еще невидимый будет*/
	int i;

	i = -1;
	/*while (++i < nest->num_of_rooms)
	{
		if (nest->rooms[i].forbbiden)
			nest->rooms[i].forbbiden = 0;
	}*/
	while ((index_forb = ft_find_new_path(nest, -1, nest->index_start, &count_path)) != -1) // но надо тут менять, чтобы не искал forbbiden
	{
		// вернул не -1 значит путь не найден, а найдена вершина пересечения с запрещенной линией
		//index_forb - вершина пересечения нового пути и запрещенного пути
		// пускаю в бой ft_line_breaker();
		ft_line_breaker(nest, index_forb);
		// обрезано пересечение, надо обнулить веса и форб иначе не получится найти путь
		ft_remove_weight(nest, -1);
		ft_find_shortest(nest, -1); // тут падает
	}
	if (count_path > 5)
		return;
	ft_find_new_paths(nest, count_path + 1); //  так как нашел путь мы увеличиваем, пока хз как это использовать
	// но надо каждый раз искать на 1 путь больше чем в предыдущий
	// и возвращаял индекс вершины в которой есть пересечение с шортест/форбиден
}