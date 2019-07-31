/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:31:49 by hnam              #+#    #+#             */
/*   Updated: 2019/07/29 22:00:44 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include "../lib/includes/ft_printf.h"
# include "../lib/includes/libft.h"
# include "filler.h"

# include "SDL.h"
# include "SDL_ttf.h"
// #include "../frameworks/SDL2.framework/includes/SDL2/SDL.h"
// #include "../frameworks/SDL2_ttf.framework/includes/SDL_ttf.h"

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Surface		*scr;
	SDL_Renderer	*ren;
	SDL_Event		e;
	SDL_Texture		*tex;
	int				round;
	int				is_running;
	int				w;
	int				h;
	TTF_Font		*font;
}					t_sdl;

typedef struct		s_fd
{
	char			*p1_name;
	char			*p1;
	char			*p2_name;
	char			*p2;
	t_cor			map_size;
	char			**m;
	t_cor			piece_size;
	char			**piece;
}					t_fd;

void				init_data(t_filler *filler);
void				player_info(t_filler *filler, char *line);

void		draw_rectangle(t_sdl *sdl);
void		event_handler(t_sdl *sdl);

t_sdl				*sdl_init();
#endif
