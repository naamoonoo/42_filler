/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnam <hnam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:31:49 by hnam              #+#    #+#             */
/*   Updated: 2019/07/22 14:26:55 by hnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../lib/includes/ft_printf.h"
# include "../lib/includes/libft.h"

# include "stdio.h"

typedef struct	s_coordinate {
	int			x;
	int			y;
}				t_cor;

typedef struct	s_filler {
	char		*line;
	char 		p1;
	char		p2;
	t_cor		map_size;
	char		*map;
	t_cor		piece_size;
	char		*piece;
}				t_filler;

int				get_player_info(t_filler *filler);
int				get_data(t_filler *filler);
int				get_map_info(t_filler *filler, char *line);
int				get_current_map(t_filler *filler, int lines);
int				get_piece_info(t_filler *filler, char *line);
int				get_current_piece(t_filler *filler, int lines);

void			exit_on_error(char *msg);
#endif
