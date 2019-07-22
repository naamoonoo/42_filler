#include "filler.h"

int	get_player_info(t_filler *filler, char *line)
{
	static int	nb_of_p = 0;
	char		**arr;

	if (nb_of_p || filler->p1 || (strstr(line, "p1") && strstr(line, "p2")))
		exit_on_error("player info");
	arr = ft_strsplit(line, ' ');
	if (strcmp(arr[0], "$$$") || strcmp(arr[1], "exec") || strcmp(arr[3], ":"))
		exit_on_error("player info");
	if (!strcmp(arr[2], "p1"))
	{
		filler->p1 = 'O';
		filler->p2 = 'X';
	}
	else
	{
		filler->p1 = 'X';
		filler->p2 = 'O';
	}
	nb_of_p += 1;
	free_char_pp(arr);
	return (0);
}

int	get_map_info(t_filler *filler, char *line)
{
	char	**arr;
	char	*tmp;

	if (ft_c_cnt(line, ' ') != 2)
		exit_on_error("map info");
	tmp = ft_strtrim_by(line, ':');
	arr = ft_strsplit(tmp, ' ');
	ft_strdel(&tmp);
	filler->map_size.y = ft_atoi(arr[1]);
	filler->map_size.x = ft_atoi(arr[2]);
	if (filler->map_size.y <= 0 || filler->map_size.x <= 0)
		exit_on_error("map info");
	free_char_pp(arr);
	return (0);
}

int	get_current_map(t_filler *filler)
{
	int		nb_lines;
	char	*tmp;
	char	*res;

	FILE *f;
	f = fopen("./error","w");

	tmp = NULL;
	nb_lines = filler->map_size.y;
	// while (nb_lines-- >= 0)
	while (nb_lines-- && get_next_line(STDIN_FILENO, &tmp) >= 0)
	{
		if (nb_lines != filler->map_size.y - 1)
		{
			fprintf(f,"[%d] \t%s\n", nb_lines, tmp);
		}
		ft_strdel(&tmp);


		// if(nb_lines == 5)
		// 	return (0);
	}
	fprintf(f,"read all!\n");
	fclose(f);
	return (0);
	res = NULL;

}

int	get_piece_info(t_filler *filler, char *line)
{
	char	**arr;
	char	*tmp;

	if (ft_c_cnt(line, ' ') != 2)
		exit_on_error("piece info");
	tmp = ft_strtrim_by(line, ':');
	arr = ft_strsplit(tmp, ' ');
	ft_strdel(&tmp);
	filler->piece_size.y = ft_atoi(arr[1]);
	filler->piece_size.x = ft_atoi(arr[2]);
	if (filler->piece_size.y <= 0 || filler->piece_size.x <= 0)
		exit_on_error("piece info");
	free_char_pp(arr);
	return (0);
}

int	get_current_piece(t_filler *filler)
{
	int		nb_lines;
	char	*tmp;
	char	*res;

	FILE *f;
	f = fopen("./error","w");

	tmp = NULL;
	nb_lines = filler->piece_size.y + 1;
	// while (nb_lines-- >= 0)
	while (--nb_lines && get_next_line(STDIN_FILENO, &tmp) >= 0)
	{
		fprintf(f,"[%d] \t%s\n", nb_lines, tmp);
		ft_strdel(&tmp);
		// if(nb_lines == 5)
		// 	return (0);
	}
	fprintf(f,"read all!\n");
	fclose(f);
	return (0);
	res = NULL;
}
