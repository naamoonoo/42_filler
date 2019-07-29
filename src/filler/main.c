#include "filler.h"

int main()
{
	t_filler	*filler;
	char *line;

	line = NULL;
	filler = ft_memalloc(sizeof(t_filler));
	if (!filler->p1)
		get_player_info(filler);
	FILE *f = fopen("./res", "w");

	while (1)
	{
		get_data(filler);
		put_piece(filler);
		// break;

	}
	fclose(f);
	free_char_pp(filler->map);
	free_char_pp(filler->piece);
	// while (1)
	// 	sleep(1);
	// if (get_data(filler) == 1)
	// 	return (1);
	// FP("8 2\n");

	// fprintf(f, "p1 : %c\t p2 : %c\n", filler->p1, filler->p2);
	// fprintf(f, "map size is [%d, %d]\n", filler->map_size.x, filler->map_size.y);
	// // for (int j = 0; j < filler->map_size.y; j++)
	// // fprintf(f, "map %s\n", filler->map[1]);
	// // fprintf(f, "map %s\n", filler->map[2]);
	// fprintf(f, "piece size is [%d, %d]\n", filler->piece_size.x, filler->piece_size.y);
	// for (int j = 0; filler->piece[j]; j++)
	// 	fprintf(f, "piece %s\n", filler->piece[j]);
	// // for (int j = 0; j < filler->piece_size.y; j++)
	// // fprintf(f, "piece %s\n", filler->piece);
	// // fprintf(f, "piece %s\n", filler->piece[0]);
	// fprintf(f,"end\n");

	return (0);
}
