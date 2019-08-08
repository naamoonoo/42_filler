/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 12:02:27 by hnam              #+#    #+#             */
/*   Updated: 2019/08/04 16:10:17 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

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
		while (f->m[y][++x])
		{
			if (ft_strchr(f->p1, f->m[y][x]))
				f->s_p1 += 1;
			else if (ft_strchr(f->p2, f->m[y][x]))
				f->s_p2 += 1;
		}
	}
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

void	event_handler(t_sdl *sdl, t_f *f)
{
	if (sdl->e.type == SDL_QUIT)
		sdl->is_quit = 1;
	if (sdl->e.type == SDL_QUIT || sdl->e.key.keysym.sym == SDLK_ESCAPE)
		sdl->is_running = 0;
	else if (sdl->e.key.keysym.sym == SDLK_DOWN)
		parse_data(f, sdl);
	else if (sdl->e.key.keysym.sym == SDLK_RIGHT)
		f->auto_fill = 1;
	else if (sdl->e.key.keysym.sym == SDLK_LEFT)
		f->auto_fill = 0;
	else if (sdl->e.key.keysym.sym == SDLK_1)
	{
		f->c_p1 = (SDL_Color){0xf7, 0xb7, 0x31, 255};
		f->c_p2 = (SDL_Color){0x38, 0x67, 0xd6, 255};
	}
	else if (sdl->e.key.keysym.sym == SDLK_2)
	{
		f->c_p1 = (SDL_Color){0xa0, 0x85, 0x5b, 255};
		f->c_p2 = (SDL_Color){0xdd, 0x6b, 0x4d, 255};
	}
	else if (sdl->e.key.keysym.sym == SDLK_3)
	{
		f->c_p1 = (SDL_Color){0x93, 0x70, 0xdb, 255};
		f->c_p2 = (SDL_Color){0x58, 0x93, 0xd4, 255};
	}
}

void	end_process(t_sdl *sdl, t_f *f)
{
	int i;

	i = -1;
	SDL_DestroyRenderer(sdl->ren);
	SDL_DestroyWindow(sdl->win);
	while (++i < NUM_OF_INFO)
		SDL_DestroyTexture(sdl->tex[i]);
	TTF_Quit();
	SDL_Quit();
	close(f->fd);
	free(f->p1_name);
	free(f->p2_name);
	free_char_pp(f->m);
	free_char_pp(f->p);
	free(f);
	free(sdl);
}
