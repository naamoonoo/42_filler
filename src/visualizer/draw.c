#include "visualizer.h"

void draw_map(t_sdl *sdl, t_f *f)
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

void	get_color_by(char p, t_f *f, t_sdl *sdl)
{
	t_cl	cl;

	cl = ft_strchr(f->p1, p) ? f->c_p1 : f->c_p2;
	if (p >= 'o' && p <= 'z')
	{
		cl.r *= 0.85;
		cl.g *= 0.85;
		cl.b *= 0.85;
	}
	SDL_SetRenderDrawColor(sdl->ren, cl.r, cl.g, cl.b, cl.a);
}

