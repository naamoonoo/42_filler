/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:31:49 by hnam              #+#    #+#             */
/*   Updated: 2019/07/29 00:59:24 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include "../lib/includes/ft_printf.h"
# include "../lib/includes/libft.h"
# include "filler.h"

#include <SDL2/SDL.h>
#include "../framework/SDL2/includes/SDL2/SDL.h"

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Surface		*scr;
	SDL_Renderer	*ren;
	SDL_Event		event;
	int				round;
	int				is_running;
	int				w;
	int				h;
}					t_sdl;

void				init_data(t_filler *filler);
void				player_info(t_filler *filler, char *line);
t_sdl				*sdl_init();
#endif
