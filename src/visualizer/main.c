/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 12:01:44 by hnam              #+#    #+#             */
/*   Updated: 2019/08/07 22:28:28 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	main_loop(t_sdl *sdl, t_f *f)
{
	while (sdl->is_running)
	{
		while (SDL_PollEvent(&(sdl->e)))
			event_handler(sdl, f);
		SDL_RenderClear(sdl->ren);
		render_piece(sdl, f);
		render_text(sdl, f);
		render_empty_map(sdl, f);
		render_map(sdl, f);
		render_status_bar(sdl, f);
		SDL_SetRenderDrawColor(sdl->ren, 0xdc, 0xdd, 0xe1, 0);
		f->auto_fill ? parse_data(f, sdl) : 0;
		SDL_RenderPresent(sdl->ren);
		SDL_Delay(1000 / 60);
	}
}

int		main(int ac, char *av[])
{
	t_sdl	*sdl;
	t_f		*f;

	if (ac != 2 && FP("./visualizer [trace]\n"))
		return (0);
	sdl = sdl_init();
	f = ft_memalloc(sizeof(t_f));
	f->fd = open(ac == 1 ? "./trace" : av[1], O_RDONLY);
	parse_data(f, sdl);
	main_loop(sdl, f);
	while (!sdl->is_quit)
	{
		while (SDL_PollEvent(&(sdl->e)))
			if (sdl->e.type == SDL_QUIT || sdl->e.key.keysym.sym == 27)
				sdl->is_quit = 1;
		SDL_Delay(1000);
	}
	end_process(sdl, f);
	return (0);
}
