#include "filler.h"

void			put_piece(t_filler *filler)
{
	get_heat_map(filler);
	// free_char_pp(filler->map);
	// free_char_pp(filler->piece);
	// int i = 0;
	// while (i < filler->map_size.y - 1)
	// {
	// 	free(filler->heat_map[i++]);
	// }
	// free(filler->heat_map);
	// free_char_pp(filler->heat_map);
	// FP("8 2\n");
	FP("50 50\n");

	// calculate



	// FP("x y\n");
}

void	get_heat_map(t_filler *filler)
{
	int 	y;
	int 	x;
	t_cor	loc;

	filler->heat_map = (int **)malloc(sizeof(int *) * (filler->map_size.y - 1));
	y = -1;
	while (++y < filler->map_size.y - 1)
	{
		x = -1;
		filler->heat_map[y] = ft_memalloc(sizeof(int) * filler->map_size.x - 1);
		while (++x < filler->map_size.x - 1)
		{
			if (ft_strchr("xX", filler->map[y][x]))
			{
				loc.x = x;
				loc.y = y;
			}
			filler->heat_map[y][x] = 424;
		}

	}
	heat_map_maker(filler, loc.x, loc.y, 0);
}

void	heat_map_maker(t_filler *filler, int x, int y, int from)
{
	int		**tab;
	t_cor	size;

	if (x < 0 || x > filler->map_size.x - 1 || y < 0 || y > filler->map_size.y - 1
	|| ft_strchr("oO", filler->map[y][x]) )
		return ;
	tab = filler->heat_map;
	size = filler->map_size;
	if (from <= tab[y][x])
		tab[y][x] = from++;
	if (x - 1 >= 0 && (tab[y][x - 1] == 0 || tab[y][x - 1] > from))
		heat_map_maker(filler, x - 1, y, from);
	if (x + 1 < size.x - 1 && (tab[y][x + 1] == 0 || tab[y][x + 1] > from))
		heat_map_maker(filler, x + 1, y, from);
	if (y - 1 >= 0 && (tab[y - 1][x] == 0 || tab[y - 1][x] > from))
		heat_map_maker(filler, x, y - 1, from);
	if (y + 1 < size.y - 1 && (tab[y + 1][x] == 0 || tab[y + 1][x] > from))
		heat_map_maker(filler, x, y + 1, from);
}

// void	get_location(t_filler *filler)
// {
// 	int x;
// 	int y;

// 	y = -1;
// 	while (++y)
// 	{
// 		x = -1;
// 		while (++x)
// 		{
// 			// if (filler->map[y][x] == 'o' ||
// 		}
// 	}
// }
