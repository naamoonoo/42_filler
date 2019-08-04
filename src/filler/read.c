#include "filler.h"

void	get_data(t_filler *filler)
{
	char	*line;

	line = NULL;
	while (gnl_linked_lst(STDIN_FILENO, &line) > 0)
	{
		if (strstr(line, "Plateau"))
		{
			get_info_of(&(filler->map_size), line);
			get_current_map(filler, filler->map_size.y + 1);
		}
		else if (strstr(line, "Piece"))
		{
			get_info_of(&(filler->piece_size), line);
			get_current_piece(filler, filler->piece_size.y);
			break;
		}
		ft_strdel(&line);
	}
}

int	get_player_info(t_filler *filler)
{
	static int	nb_of_p = 0;
	char		**arr;
	char		*line;

	line = NULL;
	arr = NULL;
	if (nb_of_p++)
		exit_on_error("player info");
	if (gnl_linked_lst(0, &line) > 0 && strstr(line, "$$$ exec"))
	{
		arr = ft_strsplit(line, ' ');
		ft_strdel(&line);
	}
	if (strcmp(arr[0], "$$$") || strcmp(arr[1], "exec") || strcmp(arr[3], ":"))
		exit_on_error("player info");
	filler->p1 = !strcmp(arr[2], "p1") ? "oO" : "xX";
	filler->p2 = !strcmp(arr[2], "p1") ? "xX" : "oO";
	free_char_pp(arr);
	return (0);
}

int get_info_of(t_cor *size, char *line)
{
	char	**arr;
	char	*tmp;

	if (ft_c_cnt(line, ' ') != 2)
		exit_on_error("getting info");
	tmp = ft_strtrim_by(line, ':');
	arr = ft_strsplit(tmp, ' ');
	ft_strdel(&tmp);
	size->y = ft_atoi(arr[1]);
	size->x = ft_atoi(arr[2]);
	if (size->y <= 0 || size->x <= 0 ||
		(int)ft_strlen(arr[1]) != ft_numlen(size->x, 10) ||
		(int)ft_strlen(arr[2]) != ft_numlen(size->y, 10))
		exit_on_error("getting info");
	free_char_pp(arr);
	return (0);
}

int	get_current_map(t_filler *filler, int lines)
{
	char		*tmp;
	int			line;
	static int	call = 0;

	line = -1;
	tmp = NULL;

	if (call++ == 0)
		filler->map = (char **)malloc(sizeof(char *) * lines);
	filler->map[lines - 1] = NULL;
	while (++line < lines && gnl_linked_lst(STDIN_FILENO, &tmp) > 0)
	{
		if (line != 0)
		{
			if (call != 1)
				free(filler->map[line - 1]);
			filler->map[line - 1] = ft_strdup(tmp + 4);
		}
		ft_strdel(&tmp);
	}
	return (0);
}

int	get_current_piece(t_filler *filler, int lines)
{
	char		*tmp;
	int			line;
	// static int	call = 0;

	line = -1;
	tmp = NULL;
	// if (call++ == 0)
	// {
		filler->piece = (char **)malloc(sizeof(char *) * (lines + 1));
		filler->piece[lines] = NULL;
	// }
	while (++line < lines && gnl_linked_lst(STDIN_FILENO, &tmp) > 0)
	{
		// if (call != 1)
		// 	free(filler->piece[line]);
		filler->piece[line] = ft_strdup(tmp);
		ft_strdel(&tmp);
		if (line == lines - 1)
			break;
	}
	return (0);
}
