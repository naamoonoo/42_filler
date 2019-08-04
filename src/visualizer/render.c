#include "visualizer.h"

void	render_filler_head(t_sdl *sdl)
{
	int		fd;
	char	*line;
	int		i;
	int		h;

	line = NULL;
	fd = open("./filler_head", O_RDONLY);
	h = 1;
	while (get_next_line(fd, &line) > 0)
	{
		i = -1;
		while (line[++i])
		{
			if (line[i] == '0')
				continue;
			SDL_SetRenderDrawColor(sdl->ren, 0, 0, 0, 255);
			line[i] == '2' ? SDL_RenderFillRect(sdl->ren, &(SDL_Rect){
				BOX_P_X + i * 20, BOX_P_X * h - 10, 20, 20})
				: SDL_RenderFillRect(sdl->ren, &(SDL_Rect){
				BOX_P_X + i * 20, BOX_P_X * h, 20, 20});
		}
		h++;
		free(line);
	}
}

void	render_map(t_sdl *sdl, t_f *f)
{
	int	width;
	int	height;
	int	x;
	int	y;

	width = 800 / MAP_X;
	height = 600 / MAP_Y;
	y = -1;
	while (++y < MAP_Y)
	{
		x = -1;
		while (++x < MAP_X)
		{
			SDL_SetRenderDrawColor(sdl->ren, 255, 255, 255, 255);
			SDL_RenderDrawRect(sdl->ren, &(SDL_Rect){
				BOX_P_X + x * width, BOX_P_Y + y * height, width, height});
			if (ft_strchr("oOxX", f->m[y][x]))
			{
				get_color_by(f->m[y][x], f, sdl);
				SDL_RenderFillRect( sdl->ren, &(SDL_Rect){
					BOX_P_X + x * width + 1, BOX_P_Y + y * height + 1,
					width - 2, height - 2});
			}
		}
	}
}

void	render_status_bar(t_sdl *sdl, t_f *f)
{
	int	p1_w;
	int	p2_w;

	p1_w = ((f->s_p1 * 800) / (f->s_p1 + f->s_p2));
	p2_w = 800 - p1_w;
	SDL_SetRenderDrawColor(sdl->ren, 255, 255, 255, 255);
	SDL_RenderDrawRect(sdl->ren, &(SDL_Rect){20, 760, 800, 20});
	SDL_SetRenderDrawColor(sdl->ren,
		f->c_p1.r, f->c_p1.g, f->c_p1.b, f->c_p1.a);
	SDL_RenderFillRect(sdl->ren, &(SDL_Rect){BOX_P_X + 1, 761, p1_w - 1, 18});
	SDL_SetRenderDrawColor(sdl->ren,
		f->c_p2.r, f->c_p2.g, f->c_p2.b, f->c_p2.a);
	SDL_RenderFillRect(sdl->ren, &(SDL_Rect){p1_w + BOX_P_X + 1, 761, p2_w - 1, 18});
}

void	get_color_by(char p, t_f *f, t_sdl *sdl)
{
	SDL_Color	cl;

	cl = ft_strchr(f->p1, p) ? f->c_p1 : f->c_p2;
	if (p >= 'o' && p <= 'z')
	{
		cl.r *= 0.8;
		cl.g *= 0.8;
		cl.b *= 0.8;
	}
	SDL_SetRenderDrawColor(sdl->ren, cl.r, cl.g, cl.b, cl.a);
}

