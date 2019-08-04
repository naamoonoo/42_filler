#include "visualizer.h"

void	parse_data(t_f *f)
{
	static int round = 0;

	while (round >= 0 && get_next_line(f->fd, &(f->line)) >= 0)
	{
		if (f->line == NULL)
			round = INT_MIN;
		if (round == 0)
		{
			if (ft_strstr(f->line, "$$$ exec"))
				player_info(f, f->line);
			else if (ft_strstr(f->line, "Plateau"))
				info_of(&(f->map_size), f->line);
		}
		else if (ft_strstr(f->line, "Plateau"))
		{
			current_map(f, f->map_size.y + 1, f->fd);
			get_score(f);
		}
		if (ft_strstr(f->line, "<got") && round++)
			return ;
		round > 0 ? free(f->line) : 0;
	}
}

void	player_info(t_f *f, char *line)
{
	char	**arr;
	int		i;
	static	int call = 0;

	if (call++ > 0)
		return ;
	i = 0;
	arr = ft_strsplit(line, '/');
	while (arr[i] && arr[i + 1])
		i++;
	if (ft_strstr(line, "p1"))
		f->p1_name = ft_strsub(arr[i], 0, ft_strchr_idx(arr[i], '.'));
	else if (ft_strstr(line, "p2"))
		f->p2_name = ft_strsub(arr[i], 0, ft_strchr_idx(arr[i], '.'));
	f->p1 = line[10] == '1' ? "oO" : "xX";
	f->p2 = line[10] == '1' ? "xX" : "oO";
	f->c_p1 = (t_cl){0xFC, 0X5c, 0X65, 255}; // #f7b731, #e58e26
	f->c_p2 = (t_cl){0x38, 0x67, 0xd6, 255}; // #38ada9,
	free_char_pp(arr);
}

int info_of(t_cor *size, char *line)
{
	char	**arr;
	char	*tmp;

	if (ft_c_cnt(line, ' ') != 2)
		return(1);
	tmp = ft_strtrim_by(line, ':');
	arr = ft_strsplit(tmp, ' ');
	ft_strdel(&tmp);
	size->y = ft_atoi(arr[1]);
	size->x = ft_atoi(arr[2]);
	free_char_pp(arr);
	return (0);
}
// void draw_map(t_sdl *sdl, t_f *f)

int	current_map(t_f *f, int lines, int fd)
{
	char		*tmp;
	int			line;
	static int	call = 0;

	line = -1;
	tmp = NULL;
	if (call++ == 0)
	{
		f->m = (char **)malloc(sizeof(char *) * lines);
		f->m[lines - 1] = NULL;
	}
	while (++line < lines && get_next_line(fd, &tmp) > 0)
	{
		if (line != 0)
		{
			if (call != 1)
				free(f->m[line - 1]);
			f->m[line - 1] = ft_strdup(tmp + 4);
		}
		ft_strdel(&tmp);
	}
	return (0);
}

void	get_score(t_f *f)
{
	int	y;
	int	x;

	y = -1;
	f->s_p1 = 0;
	f->s_p2 = 0;
	while (f->m[++y])
	{
		x = -1;
		while(f->m[y][++x])
		{
			if (ft_strchr(f->p1, f->m[y][x]))
				f->s_p1 += 1;
			else if (ft_strchr(f->p2, f->m[y][x]))
				f->s_p2 += 1;
		}
	}
}
