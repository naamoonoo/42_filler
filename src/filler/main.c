#include "filler.h"


int main()
{
	t_filler	*filler;
	char *line;

	line = NULL;
	filler = ft_memalloc(sizeof(t_filler));
	if (!filler->p1)
		get_player_info(filler);
	while (1)
	{
		get_data(filler);
		put_piece(filler);
	}
	free_char_pp(filler->map);
	free_char_pp(filler->piece);

	return (0);
}
