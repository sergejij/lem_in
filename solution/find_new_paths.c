#include "lem_in.h"

int ft_find_intersections(t_map *nest, int index_forb, int i, int j)
{
	// у меня есть одна вершина, я подаю еЁ и еЁ связь в функцию, которая выдает индекс пути
	// тут же проверяю является ли это ребро запрещенным
	// если ((текущая запрещенная вершина - 1) == вершине) по связи и он форбиден,
	// значит это путь к старту, ищу пересечение
	// в таком же стиле иду до старта, но если встречаю вершину с более чем двумя связями, возвращяю её
	while (++i < nest->rooms[nest->index_end].weght)
	{
		while (++j < nest->rooms[index_forb].num_of_links)
		{
			if (nest->rooms[nest->rooms[index_forb].links[j]].forb_new_way &&
					((nest->rooms[index_forb].weght - 1) ==
							nest->rooms[nest->rooms[index_forb].links[j]].weght)) // связь явл форб
			{
				index_forb = nest->rooms[index_forb].links[j];
				j = 0;
			}
			if (nest->rooms[nest->rooms[index_forb].links[j]].forb_new_way &&
			nest->rooms[index_forb].num_of_links > 2)
				return (index_forb);
		}
	}
	return (-1);
}

void 	ft_line_breaker(t_map *nest, int index_forb)
{ // ф-я удаляет линию без пересечений, до пересечения
	int index_intersections;
	// если нет пересечений до старта, а только линия, мы не трогаем
	// то есть сначала имеет смысл проверить есть ли пересечения до старта
	// если да, получить этот индекс
	if ((index_intersections = ft_find_intersections(nest, index_forb, -1, -1)) == - 1)
	{
		 // пересечений, значит надо удалить ту линию по которой мы пришли к форбиден вершине
		return ;
	}
	// иначе у меня есть пересечение и мне нужно удалить от пересечения до индекс_форб
}

void	ft_find_new_paths(t_map *nest)
{
	int index_forb;
	/*int i;

	i = -1;
	while (++i < nest->num_of_ways)
	{
		if (nest->ways[i].shortest)
			nest->ways[i].forbbiden;
	}*/
	if ((index_forb = ft_find_shortest(nest, nest->index_start)) != -1) // но надо тут менять, чтобы не искал forbbiden
	{
		//index_forb - вершина пересечения нового пути и запрещенного пути
		// пускаю в бой ft_line_breaker();
		ft_line_breaker(nest, index_forb);
	}
	// и возвращаял индекс вершины в которой есть пересечение с шортест/форбиден
}