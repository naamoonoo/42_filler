/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 12:04:06 by hnam              #+#    #+#             */
/*   Updated: 2019/08/07 22:46:28 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	render_piece(t_sdl *sdl, t_f *f)
{
	int	x;
	int	y;

	sdl->w = 250 / (PIECE_X > 10 ? PIECE_X : 10);
	sdl->h = 250 / (PIECE_Y > 10 ? PIECE_Y : 10);
	y = -1;
	while (++y < (PIECE_Y > 10 ? PIECE_Y : 10))
	{
		x = -1;
		while (++x < (PIECE_X > 10 ? PIECE_X : 10))
		{
			SDL_SetRenderDrawColor(sdl->ren, 255, 255, 255, 255);
			SDL_RenderDrawRect(sdl->ren, &(SDL_Rect){PIECE_P_X + x * sdl->w +
				50, PIECE_P_Y + y * sdl->h + 50, sdl->w, sdl->h});
			fuck_norm(sdl, f, y, x);
		}
	}
}

void	fuck_norm(t_sdl *sdl, t_f *f, int y, int x)
{
	if (y < PIECE_Y && x < PIECE_X && f->p[y][x] == '*')
	{
		SDL_SetRenderDrawColor(sdl->ren, 0, 0, 0, 255);
		SDL_RenderFillRect(sdl->ren, &(SDL_Rect){PIECE_P_X + x *
			sdl->w + 1 + 50, PIECE_P_Y + y * sdl->h + 1 + 50,
			sdl->w - 2, sdl->h - 2});
	}
	else if (y < PIECE_Y && x < PIECE_X && f->p[y][x] == '.')
	{
		SDL_SetRenderDrawColor(sdl->ren, 0, 0, 0, 255);
		SDL_RenderFillRect(sdl->ren, &(SDL_Rect){PIECE_P_X + x *
			sdl->w + 10 + 50, PIECE_P_Y + y * sdl->h + 10 + 50,
			sdl->w - 20, sdl->h - 20});
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
			if (ft_strchr("oOxX", f->m[y][x]))
			{
				get_color_by(f->m[y][x], f, sdl);
				SDL_RenderFillRect(sdl->ren, &(SDL_Rect){
					MAP_P_X + x * width + 1, MAP_P_Y + y * height + 1,
					width - 2, height - 2});
			}
		}
	}
}

void	render_empty_map(t_sdl *sdl, t_f *f)
{
	int	width;
	int	height;
	int	x;
	int	y;

	width = 800 / MAP_X;
	height = 600 / MAP_Y;
	y = -1;
	while (++y <= MAP_Y)
	{
		SDL_SetRenderDrawColor(sdl->ren, 255, 255, 255, 255);
		SDL_RenderDrawLine(sdl->ren, MAP_P_X, MAP_P_Y + y * height,
			MAP_P_X + 800, MAP_P_Y + y * height);
	}
	x = -1;
	while (++x <= MAP_X)
	{
		SDL_SetRenderDrawColor(sdl->ren, 255, 255, 255, 255);
		SDL_RenderDrawLine(sdl->ren, MAP_P_X + x * width, MAP_P_Y,
			MAP_P_X + x * width, MAP_P_Y + 600);
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
	SDL_RenderFillRect(sdl->ren, &(SDL_Rect){MAP_P_X + 1, 761, p1_w - 1, 18});
	SDL_SetRenderDrawColor(sdl->ren,
		f->c_p2.r, f->c_p2.g, f->c_p2.b, f->c_p2.a);
	SDL_RenderFillRect(sdl->ren, &(SDL_Rect){p1_w + MAP_P_X + 1,
		761, p2_w - 1, 18});
}
