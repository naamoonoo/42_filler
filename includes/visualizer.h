/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:31:49 by hnam              #+#    #+#             */
/*   Updated: 2019/08/03 16:08:42 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include "filler.h"
# include "../lib/includes/ft_printf.h"
# include "../lib/includes/libft.h"

# include "SDL.h"
# include "SDL_ttf.h"
// #include "../frameworks/SDL2.framework/includes/SDL2/SDL.h"
// #include "../frameworks/SDL2_ttf.framework/includes/SDL_ttf.h"

# define MAP_Y f->map_size.y
# define MAP_X f->map_size.x
# define BOX_P_X 20
# define BOX_P_Y 140

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

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
	int				a;
}					t_cl;

typedef struct		s_f
{
	char			*p1_name;
	char			*p1;
	t_cl			c_p1;
	int				s_p1;
	char			*p2_name;
	char			*p2;
	t_cl			c_p2;
	int				s_p2;
	t_cor			map_size;
	char			**m;
}					t_f;

void				init_data(t_f *f);
void				player_info(t_f *f, char *line);

void		draw_map(t_sdl *sdl, t_f *f);
void		get_color_by(char p, t_f *f, t_sdl *sdl);
void		event_handler(t_sdl *sdl, t_f *f);

int	current_map(t_f *f, int lines, int fd);
int info_of(t_cor *size, char *line);


t_sdl				*sdl_init();
#endif
