#include "visualizer.h"

void	parse_data(t_f *f, t_sdl *sdl)
{
	while (sdl->is_running && get_next_line(f->fd, &(f->line)) >= 0)
	{
		if (ft_strstr(f->line, "fin") || ft_strstr(f->line, "error")
			|| f->line == NULL)
			sdl->is_running = 0;
		if (ft_strstr(f->line, "got") && f->round++)
			break ;
		if (!f->round && ft_strstr(f->line, "$$$ exec"))
			player_info(f, f->line);
		else if (!f->round && ft_strstr(f->line, "Plateau"))
			info_of(&(f->map_size), f->line);
		if (ft_strstr(f->line, "Plateau"))
			current_map(f, f->map_size.y + 1, f->fd);
		free(f->line);
	}
}

void	player_info(t_f *f, char *line)
{
	char	**arr;
	int		i;

	i = 0;
	arr = ft_strsplit(line, '/');
	while (arr[i] && arr[i + 1])
		i++;
	if (ft_strstr(line, "p1"))
	{
		f->p1_name = ft_strsub(arr[i], 0, ft_strchr_idx(arr[i], '.'));
		f->p1 = "oO";
		f->c_p1 = (SDL_Color){0xf7, 0Xb7, 0X31, 255}; // #f7b731, #e58e26
	}
	else if (ft_strstr(line, "p2"))
	{
		f->p2_name = ft_strsub(arr[i], 0, ft_strchr_idx(arr[i], '.'));
		f->p2= "xX";
		f->c_p2 = (SDL_Color){0x38, 0x67, 0xd6, 255}; // #38ada9,
	}
	free_char_pp(arr);
}

void	info_of(t_cor *size, char *line)
{
	char	**arr;
	char	*tmp;

	if (ft_c_cnt(line, ' ') != 2)
		return ;
	tmp = ft_strtrim_by(line, ':');
	arr = ft_strsplit(tmp, ' ');
	ft_strdel(&tmp);
	size->y = ft_atoi(arr[1]);
	size->x = ft_atoi(arr[2]);
	free_char_pp(arr);
}

void	current_map(t_f *f, int lines, int fd)
{
	char		*tmp;
	int			line;
	static int	call = 0;

	line = -1;
	tmp = NULL;
	if (call++ == 0)
		f->m = (char **)malloc(sizeof(char *) * lines);
	f->m[lines - 1] = NULL;
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
	get_score(f);
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
