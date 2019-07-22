#include "filler.h"

int	get_player_info(t_filler *filler)
{
	static int	nb_of_p = 0;
	char		**arr;
	char		*line;

	line = NULL;
	arr = NULL;
	if (nb_of_p)
		exit_on_error("player info");
	if (gnl_linked_lst(0, &line) > 0 && strstr(line, "$$$ exec"))
	{
		arr = ft_strsplit(line, ' ');
		ft_strdel(&line);
	}
	if (strcmp(arr[0], "$$$") || strcmp(arr[1], "exec") || strcmp(arr[3], ":"))
		exit_on_error("player info");
	if (!strcmp(arr[2], "p1"))
	{
		filler->p1 = 'O';
		filler->p2 = 'X';
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
	get_current_map(filler, filler->map_size.y + 1);
	return (0);
}

int	get_current_map(t_filler *filler, int lines)
{
	char	*tmp;
	char	*res;

	FILE *f;
	f = fopen("./error","w");

	tmp = NULL;
	while (lines-- && gnl_linked_lst(STDIN_FILENO, &tmp) > 0)
	{
		if (lines != filler->map_size.y)
			fprintf(f,"[%d] \t%s\n", lines, ft_strsplit(tmp, ' ')[1]);
		if (lines == 0)
			filler->map = ft_strdup(tmp);
		ft_strdel(&tmp);
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
	get_current_piece(filler, filler->piece_size.y);
	return (0);
}

int	get_current_piece(t_filler *filler, int lines)
{
	char	*tmp;
	char	*res;

	FILE *f;
	f = fopen("./error","w");

	tmp = NULL;
	while (lines-- && gnl_linked_lst(STDIN_FILENO, &tmp) > 0)
	{
		fprintf(f,"[%d] \t%s\n", lines, tmp);
		if (lines == 0 && tmp)
		{
			filler->map = ft_strdup(tmp);
			ft_strdel(&tmp);
			break;
		}
		ft_strdel(&tmp);
	}
	fprintf(f,"read all!\n");
	fclose(f);
	return (0);
	res = NULL;
}
