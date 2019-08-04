/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:31:49 by hnam              #+#    #+#             */
/*   Updated: 2019/08/04 11:51:03 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include "filler.h"
# include "../lib/includes/ft_printf.h"
# include "../lib/includes/libft.h"

# include "SDL.h"
# include "SDL_ttf.h"

# define MAP_Y f->map_size.y
# define MAP_X f->map_size.x
# define PIECE_Y f->piece_size.y
# define PIECE_X f->piece_size.x
# define MAP_P_X 20
# define MAP_P_Y 140
# define PIECE_P_X 850
# define PIECE_P_Y 140
# define COMMANDS "set  :  1/set  :  2/set  :  3/auto ON  :  RIGHT\
		/auto OFF  :  LEFT/next  :  DOWN/finish  : ESC"
# define NUM_OF_INFO 14

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Surface		*scr;
	SDL_Renderer	*ren;
	SDL_Event		e;
	SDL_Texture		*tex[NUM_OF_INFO];
	SDL_Rect		rect[NUM_OF_INFO];
	int				round;
	int				is_running;
	int				is_quit;
	int				w;
	int				h;
	TTF_Font		*font[2];
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
	int				fd;
	int				round;
	char			*line;
	char			*p1_name;
	char			*p1;
	SDL_Color		c_p1;
	int				s_p1;
	char			*p2_name;
	char			*p2;
	SDL_Color		c_p2;
	int				s_p2;
	t_cor			map_size;
	char			**m;
	int				auto_fill;
	t_cor			piece_size;
	char			**p;
}					t_f;

void				parse_data(t_f *f, t_sdl *sdl);
void				player_info(t_f *f, char *line);
void		get_score(t_f *f);
void	current_piece(t_f *f, int lines, int fd);

void		render_piece(t_sdl *sdl, t_f *f);
void		fuck_norm(t_sdl *sdl, t_f *f, int y, int x);
void		render_map(t_sdl *sdl, t_f *f);
void		render_status_bar(t_sdl *sdl, t_f *f);

void		get_color_by(char p, t_f *f, t_sdl *sdl);

void	render_text(t_sdl *sdl, t_f *f);
void	render_text2(t_sdl *sdl, t_f *f);
void	get_text_and_rect(char *text, t_sdl *sdl, int idx, SDL_Color color);
void		event_handler(t_sdl *sdl, t_f *f);

void		current_map(t_f *f, int lines, int fd);
void		info_of(t_cor *size, char *line);


t_sdl				*sdl_init();
#endif
