#include "filler.h"

int				get_data(t_filler *filler)
{
	char	*line;

	line = NULL;
	while (1)
	{
		while (gnl_linked_lst(STDIN_FILENO, &line) > 0)
		{
			if (strstr(line, "Plateau"))
			{
				get_map_info(filler, line);
				// continue ;
			}
			else if (strstr(line, "Piece"))
			{
				get_piece_info(filler, line);
				break;
			}
			ft_strdel(&line);
		}
		FP("8 2\n");
	}
	return (0);
}

int main()
{
	static int	init = 0;
	t_filler	*filler;
	char *line;

	FILE *f;
	f = fopen("./trace","w");

	line = NULL;
	filler = ft_memalloc(sizeof(t_filler));
	fprintf(f, "start\n");
	if (!filler->p1 && !init++)
		get_player_info(filler);
	if (get_data(filler) == 1)
		return (1);
	FP("8 2\n");

	fprintf(f, "p1 : %c\t p2 : %c\n", filler->p1, filler->p2);
	fprintf(f, "map size is [%d, %d]\n", filler->map_size.x, filler->map_size.y);
	fprintf(f, "map s %s\n", filler->map);
	fprintf(f, "piece size is [%d, %d]\n", filler->piece_size.x, filler->piece_size.y);
	fprintf(f,"end\n");
	fclose(f);

	return (0);
}
