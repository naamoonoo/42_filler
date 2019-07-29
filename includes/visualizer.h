/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:31:49 by hnam              #+#    #+#             */
/*   Updated: 2019/07/28 23:37:17 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include "../lib/includes/ft_printf.h"
# include "../lib/includes/libft.h"

#include <stdio.h>
#include <SDL2/SDL.h>

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Surface		*screenSurface;
	SDL_Renderer	*renderer;
	SDL_Event		event;
	int				is_running;
	int				w;
	int				h;
}					t_sdl;


t_sdl				*sdl_init();
#endif
