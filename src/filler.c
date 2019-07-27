#include "filler.h"

void			put_piece(t_filler *filler)
{
	FILE *f;
	f = fopen("./trace","w");
	for (int j = 0; filler->map[j]; j++)
		fprintf(f, "%s\n", filler->map[j]);

	get_heat_map(filler);

	for (int y = 0; y < filler->map_size.y - 1; y++)
	{
		for (int x = 0; x < filler->map_size.x - 1; x++)
			fprintf(f, "%d\t", filler->heat_map[y][x]);
		fprintf(f, "\n");
	}

	filler->heat_score = 999;
	filler->best_pos.y = -1;
	filler->best_pos.x = -1;
	get_best_position(filler, filler->p1_pos.x, filler->p1_pos.y);
	// free_char_pp(filler->map);
	// free_char_pp(filler->piece);
	// int i = 0;
	// while (i < filler->map_size.y - 1)
	// {
	// 	free(filler->heat_map[i++]);
	// }
	// free(filler->heat_map);
	// free_char_pp(filler->heat_map);
	if (filler->best_pos.x >= 0 && filler->best_pos.y >= 0)
		FP("%d %d\n", filler->best_pos.y, filler->best_pos.x);
	else
		FP("%d %d\n", filler->p1_pos.y, filler->p1_pos.x);
	// fclose(f);

	// FP("50 50\n");

	// calculate



	// FP("x y\n");
}


void	get_best_position(t_filler *filler, int x, int y)
{
	// if (x < 0 || x > filler->map_size.x - 1 || y < 0 || y > filler->map_size.y - 1
	// || !ft_strchr("oO", filler->map[y][x]) )
	// 	return ;
	FILE *f = fopen("./get_best_position","w");

	// update_position(filler, x, y);
	// if (x - 1 >= 0 && ft_strchr("oO", filler->map[y][x - 1]))
	// 	get_best_position(filler, x - 1, y);
	// // if (x + 1 < filler->map_size.x - 1 && ft_strchr("oO", filler->map[y][x + 1]))
	// // 	get_best_position(filler, x + 1, y);
	// if (y - 1 >= 0 && ft_strchr("oO", filler->map[y - 1][x]))
	// 	get_best_position(filler, x, y - 1);
	// // if (y + 1 < filler->map_size.y - 1 && ft_strchr("oO", filler->map[y + 1][x]))
	// // 	get_best_position(filler, x, y + 1);
	int		ix;
	int		iy;
	int		tmp;

	iy = -1;
	while (++iy < filler->map_size.y - 1)
	{
		ix = -1;
		while (++ix < filler->map_size.x - 1)
		{
			if (ix + filler->piece_size.x < filler->map_size.x - 1 &&
				iy + filler->piece_size.y < filler->map_size.y - 1 &&
				(tmp = is_valid(filler, ix, iy, f)) > 0
				&& tmp <= filler->heat_score)
			{
				fprintf(f, "updated with %d, %d [%d]\n", ix, iy, tmp);
				filler->best_pos.x = ix;
				filler->best_pos.y = iy;
				filler->heat_score = tmp;
			}
		}
	}

	x = y + 1;
}

int		is_valid(t_filler *filler, int x, int y, FILE *f)
{
	t_cor	t;
	int		is_valid;
	int		min;

	t.y = -1;
	min = 999;
	is_valid = 0;
	while (++t.y < filler->piece_size.y)
	{
		t.x = -1;
		while (++t.x < filler->piece_size.x)
		{
			if (t.y + y < filler->map_size.y - 1
				&& t.x + x < filler->map_size.x - 1)
			{
				if (ft_strchr("oO", filler->map[t.y + y][t.x + x])
					&& filler->piece[t.y][t.x] == '*')
					is_valid = 1;
				if (filler->piece[t.y][t.x] == '*' &&
					filler->heat_map[t.y + y][t.x + x] != 0
					&& filler->heat_map[t.y + y][t.x + x] <= min)
					min = filler->heat_map[t.y + y][t.x + x];
			}
		}
	}
	// if (is_valid)
	// 	fprintf(f, "curr heat : %d\t new score is%d\n", filler->heat_score, min);
	(void)f;
	return is_valid ? min : -1;
}

// void	update_position(t_filler *filler, int x, int y)
// {
// 	int		iy;
// 	int		ix;
// 	int		tmp;

// 	iy = -1;
// 	while (++iy < filler->piece_size.y)
// 	{
// 		ix = -1;
// 		while (++ix < filler->piece_size.x)
// 		{
// 			if (x - ix >= 0 && y - iy >= 0 &&
// 				(tmp = is_valid(filler, x - ix, y - iy)) > 0
// 				&& tmp < filler->heat_score)
// 				{
// 					filler->best_pos.x = x - ix;
// 					filler->best_pos.y = y - iy;
// 					filler->heat_score = tmp;
// 				}
// 		}
// 	}
// }
